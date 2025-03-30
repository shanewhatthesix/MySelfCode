#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <algorithm>
#include <string_view>
#include <iomanip>

class Matrix {
public:
	Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols) {}
	
	double& operator()(int row, int col) {
		return data_[row * cols_ + col];
	}
	
	double operator()(int row, int col) const {
		return data_[row * cols_ + col];
	}
	
	int rows() const {
		return rows_;
	}
	int cols() const {
		return cols_;
	}
	
	Matrix operator+(const Matrix& other) const {
		if (rows_ != other.rows_ || cols_ != other.cols_) {
			throw std::runtime_error("Matrix dimensions do not match for addition.");
		}
		Matrix result(rows_, cols_);
		for (int i = 0; i < rows_ * cols_; ++i) {
			result.data_[i] = data_[i] + other.data_[i];
		}
		return result;
	}
	
	Matrix operator-(const Matrix& other) const {
		if (rows_ != other.rows_ || cols_ != other.cols_) {
			throw std::runtime_error("Matrix dimensions do not match for subtraction.");
		}
		Matrix result(rows_, cols_);
		for (int i = 0; i < rows_ * cols_; ++i) {
			result.data_[i] = data_[i] - other.data_[i];
		}
		return result;
	}
	
	Matrix operator*(double scalar) const {
		Matrix result(rows_, cols_);
		for (int i = 0; i < rows_ * cols_; ++i) {
			result.data_[i] = data_[i] * scalar;
		}
		return result;
	}
	
	Matrix element_multiply(const Matrix& other) const {
		if (rows_ != other.rows_ || cols_ != other.cols_) {
			throw std::runtime_error("Matrix dimensions do not match for element-wise multiplication.");
		}
		Matrix result(rows_, cols_);
		for (int i = 0; i < rows_ * cols_; ++i) {
			result.data_[i] = data_[i] * other.data_[i];
		}
		return result;
	}
	
	Matrix transpose() const {
		Matrix result(cols_, rows_);
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				result(j, i) = data_[i * cols_ + j];
			}
		}
		return result;
	}
	
	Matrix operator*(const Matrix& other) const {
		if (cols_ != other.rows_) {
			throw std::runtime_error("Matrix dimensions are not compatible for multiplication.");
		}
		Matrix result(rows_, other.cols_);
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < other.cols_; ++j) {
				double sum = 0.0;
				for (int k = 0; k < cols_; ++k) {
					sum += data_[i * cols_ + k] * other(k, j);
				}
				result(i, j) = sum;
			}
		}
		return result;
	}
	
private:
	int rows_;
	int cols_;
	std::vector<double> data_;
};

class RNN {
public:
	RNN(int input_size, int hidden_size, int output_size)
	: input_size_(input_size), hidden_size_(hidden_size), output_size_(output_size),
	Wxh(hidden_size, input_size), Whh(hidden_size, hidden_size), Why(output_size, hidden_size),
	bh(hidden_size), by(output_size),
	mWxh(hidden_size, input_size), mWhh(hidden_size, hidden_size), mWhy(output_size, hidden_size),
	mbh(hidden_size), mby(output_size),
	vWxh(hidden_size, input_size), vWhh(hidden_size, hidden_size), vWhy(output_size, hidden_size),
	vbh(hidden_size), vby(output_size) {
		
		std::random_device rd;
		std::mt19937 gen(rd());
		std::normal_distribution<> distrib(0.0, 0.1);
		
		auto init_matrix = [&](Matrix & m) {
			for (int i = 0; i < m.rows(); ++i) {
				for (int j = 0; j < m.cols(); ++j) {
					m(i, j) = distrib(gen);
				}
			}
		};
		
		init_matrix(Wxh);
		init_matrix(Whh);
		init_matrix(Why);
		
		auto init_vector = [&](std::vector<double>& v) {
			for (size_t i = 0; i < v.size(); ++i) {
				v[i] = distrib(gen);
			}
		};
		
		init_vector(bh);
		init_vector(by);
	}
	
	std::vector<double> forward(const std::vector<double>& input, std::vector<double>& hidden_state) {
		std::vector<double> new_hidden_state(hidden_size_);
		for (int i = 0; i < hidden_size_; ++i) {
			double sum = bh[i];
			for (int j = 0; j < input_size_; ++j) {
				sum += Wxh(i, j) * input[j];
			}
			for (int j = 0; j < hidden_size_; ++j) {
				sum += Whh(i, j) * hidden_state[j];
			}
			new_hidden_state[i] = tanh(sum);
		}
		
		std::vector<double> output(output_size_);
		for (int i = 0; i < output_size_; ++i) {
			double sum = by[i];
			for (int j = 0; j < hidden_size_; ++j) {
				sum += Why(i, j) * new_hidden_state[j];
			}
			output[i] = sum;
		}
		
		hidden_state = new_hidden_state;
		return output;
	}
	
	void train_step(const std::vector<double>& input, const std::vector<double>& target, std::vector<double>& hidden_state, double learning_rate) {
		std::vector<double> output = forward(input, hidden_state);
		double loss = 0.0;
		for (size_t i = 0; i < output.size(); ++i) {
			loss += (output[i] - target[i]) * (output[i] - target[i]);
		}
		loss /= output.size();
		
		Matrix dWhy(output_size_, hidden_size_);
		std::vector<double> dby(output_size_);
		for (int i = 0; i < output_size_; ++i) {
			double diff = output[i] - target[i];
			dby[i] = diff;
			for (int j = 0; j < hidden_size_; ++j) {
				dWhy(i, j) = diff * hidden_state[j];
			}
		}
		
		double beta1 = 0.9, beta2 = 0.999, epsilon = 1e-8;
		static int t = 0;
		mWhy = mWhy * beta1 + dWhy * (1.0 - beta1);
		for (size_t i = 0; i < mby.size(); ++i) {
			mby[i] = mby[i] * beta1 + dby[i] * (1.0 - beta1);
		}
		
		vWhy = vWhy * beta2 + dWhy.element_multiply(dWhy) * (1.0 - beta2);
		for (size_t i = 0; i < vby.size(); ++i) {
			vby[i] = vby[i] * beta2 + dby[i] * dby[i] * (1.0 - beta2);
		}
		
		Matrix mWhy_hat = mWhy * (1.0 / (1.0 - pow(beta1, t + 1)));
		std::vector<double> mby_hat(mby.size());
		for (size_t i = 0; i < mby.size(); ++i) {
			mby_hat[i] = mby[i] * (1.0 / (1.0 - pow(beta1, t + 1)));
		}
		
		Matrix vWhy_hat = vWhy * (1.0 / (1.0 - pow(beta2, t + 1)));
		std::vector<double> vby_hat(vby.size());
		for (size_t i = 0; i < vby.size(); ++i) {
			vby_hat[i] = vby[i] * (1.0 / (1.0 - pow(beta2, t + 1)));
		}
		
		for (int i = 0; i < output_size_; ++i) {
			for (int j = 0; j < hidden_size_; ++j) {
				Why(i, j) -= learning_rate * mWhy_hat(i, j) / (sqrt(vWhy_hat(i, j)) + epsilon);
			}
			by[i] -= learning_rate * mby_hat[i] / (sqrt(vby_hat[i]) + epsilon);
		}
		
		t++;
	}
	
	std::string generate_answer(const std::string& input_question, const std::vector<char>& vocabulary) {
		std::vector<std::vector<double>> input_sequence = string_to_one_hot(input_question, vocabulary);
		std::vector<double> hidden_state(hidden_size_, 0.0);
		std::string generated_answer = "";
		
		for (const auto& input_vector : input_sequence) {
			std::vector<double> output = forward(input_vector, hidden_state);
			char next_char = one_hot_to_char(output, vocabulary);
			generated_answer += next_char;
		}
		
		return generated_answer;
	}
	
	int hidden_size() const {
		return hidden_size_;
	}
	
private:
	int input_size_, hidden_size_, output_size_;
	Matrix Wxh, Whh, Why;
	std::vector<double> bh, by;
	Matrix mWxh, mWhh, mWhy;
	std::vector<double> mbh, mby;
	Matrix vWxh, vWhh, vWhy;
	std::vector<double> vbh, vby;
	
	double tanh(double x) {
		return std::tanh(x);
	}
	
	std::vector<std::vector<double>> string_to_one_hot(const std::string& str, const std::vector<char>& vocabulary) {
		std::vector<std::vector<double>> one_hot_vectors;
		for (char c : str) {
			std::vector<double> one_hot_vector(vocabulary.size(), 0.0);
			auto it = std::find(vocabulary.begin(), vocabulary.end(), c);
			if (it != vocabulary.end()) {
				int index = std::distance(vocabulary.begin(), it);
				one_hot_vector[index] = 1.0;
			}
			one_hot_vectors.push_back(one_hot_vector);
		}
		return one_hot_vectors;
	}
	
	char one_hot_to_char(const std::vector<double>& one_hot_vector, const std::vector<char>& vocabulary) {
		auto max_element_it = std::max_element(one_hot_vector.begin(), one_hot_vector.end());
		if (max_element_it != one_hot_vector.end()) {
			int index = std::distance(one_hot_vector.begin(), max_element_it);
			return vocabulary[index];
		}
		return '?';
	}
};

// Utility functions

std::vector<std::vector<double >> string_to_one_hot(const std::string& str, const std::vector<char>& vocabulary) {
	std::vector<std::vector<double >> one_hot_vectors;
	for (char c : str) {
		std::vector<double> one_hot_vector(vocabulary.size(), 0.0);
		auto it = std::find(vocabulary.begin(), vocabulary.end(), c);
		if (it != vocabulary.end()) {
			int index = std::distance(vocabulary.begin(), it);
			one_hot_vector[index] = 1.0;
		}
		one_hot_vectors.push_back(one_hot_vector);
	}
	return one_hot_vectors;
}

char one_hot_to_char(const std::vector<double>& one_hot_vector, const std::vector<char>& vocabulary) {
	auto max_element_it = std::max_element(one_hot_vector.begin(), one_hot_vector.end());
	if (max_element_it != one_hot_vector.end()) {
		int index = std::distance(one_hot_vector.begin(), max_element_it);
		return vocabulary[index];
	}
	return '?';
}

void load_json_data(const std::string& filename, RNN& rnn, const std::vector<char>& vocabulary, double learning_rate, int epoch, int num_epochs, long long total_lines) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}
	
	std::string line;
	long long current_line = 0;
	while (std::getline(file, line)) {
		current_line++;
		
		std::string_view line_view = line;
		size_t start = line_view.find_first_not_of(" \t\n\r");
		size_t end = line_view.find_last_not_of(" \t\n\r");
		if (start == std::string::npos || end == std::string::npos) continue;
		
		line_view = line_view.substr(start, end - start + 1);
		
		size_t question_start = line_view.find("\"question\": \"");
		size_t answer_start = line_view.find("\"answer\": \"");
		
		if (question_start != std::string::npos && answer_start != std::string::npos) {
			question_start += std::string("\"question\": \"").length();
			answer_start += std::string("\"answer\": \"").length();
			
			size_t question_end = line_view.find("\"", question_start);
			size_t answer_end = line_view.find("\"", answer_start);
			
			if (question_end != std::string::npos && answer_end != std::string::npos) {
				std::string_view question_view = line_view.substr(question_start, question_end - question_start);
				std::string_view answer_view = line_view.substr(answer_start, answer_end - answer_start);
				
				std::string question(question_view);
				std::string answer(answer_view);
				
				std::vector<std::vector<double >> input_sequence = string_to_one_hot(question, vocabulary);
				std::vector<std::vector<double >> target_sequence = string_to_one_hot(answer, vocabulary);
				
				size_t min_length = std::min(input_sequence.size(), target_sequence.size());
				input_sequence.resize(min_length);
				target_sequence.resize(min_length);
				
				std::vector<double> hidden_state(rnn.hidden_size(), 0.0);
				
				for (size_t i = 0; i < min_length; ++i) {
					rnn.train_step(input_sequence[i], target_sequence[i], hidden_state, learning_rate);
				}
			}
		}
		
		if (current_line % 100 == 0) { // 增加更新频率，例如每 100 行更新一次
			double progress = static_cast<double>(current_line) / total_lines;
			int bar_width = 60; // 增加进度条宽度
			double pos = bar_width * progress; // 使用 double 类型
			int rounded_pos = static_cast<int>(std::round(pos)); // 四舍五入
			
			std::cout << "[" << std::string(rounded_pos, '=') << std::string(bar_width - rounded_pos, ' ') << "] "
			<< std::fixed << std::setprecision(2) << (progress * 100.0) << "% (Epoch " << epoch + 1 << "/" << num_epochs << ")\r"; // 显示两位小数
			std::cout.flush();
		}
		
		
	}
	std::cout << std::endl;
	file.close();
}

std::vector<char> create_vocabulary(const std::string& filename) {
	std::vector<char> vocabulary;
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return vocabulary;
	}
	
	std::string line;
	while (std::getline(file, line)) {
		std::string_view line_view = line;
		size_t start = line_view.find_first_not_of(" \t\n\r");
		size_t end = line_view.find_last_not_of(" \t\n\r");
		if (start == std::string::npos || end == std::string::npos) continue;
		
		line_view = line_view.substr(start, end - start + 1);
		
		size_t question_start = line_view.find("\"question\": \"");
		size_t answer_start = line_view.find("\"answer\": \"");
		
		if (question_start != std::string::npos && answer_start != std::string::npos) {
			question_start += std::string("\"question\": \"").length();
			answer_start += std::string("\"answer\": \"").length();
			
			size_t question_end = line_view.find("\"", question_start);
			size_t answer_end = line_view.find("\"", answer_start);
			
			if (question_end != std::string::npos && answer_end != std::string::npos) {
				std::string_view question_view = line_view.substr(question_start, question_end - question_start);
				std::string_view answer_view = line_view.substr(answer_start, answer_end - answer_start);
				
				std::string question(question_view);
				std::string answer(answer_view);
				
				for (char c : question) {
					if (std::find(vocabulary.begin(), vocabulary.end(), c) == vocabulary.end()) {
						vocabulary.push_back(c);
					}
				}
				
				for (char c : answer) {
					if (std::find(vocabulary.begin(), vocabulary.end(), c) == vocabulary.end()) {
						vocabulary.push_back(c);
					}
				}
			}
		}
	}
	
	if (std::find(vocabulary.begin(), vocabulary.end(), ' ') == vocabulary.end()) {
		/**/	vocabulary.push_back(' ');
	}
	
	std::sort(vocabulary.begin(), vocabulary.end());
	file.close();
	return vocabulary;
}

long long count_lines(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 0;
	}
	
	long long line_count = 0;
	std::string line;
	while (std::getline(file, line)) {
		line_count++;
	}
	
	file.close();
	return line_count;
}

int main() {
	std::vector<char> vocabulary = create_vocabulary("data.json");
	int vocab_size = vocabulary.size();
	
	int hidden_size = 128;
	RNN rnn(vocab_size, hidden_size, vocab_size);
	
	int num_epochs = 20;
	double learning_rate = 0.001;
	
	long long total_lines = count_lines("data.json");
	
	for (int epoch = 0; epoch < num_epochs; ++epoch) {
		load_json_data("data.json", rnn, vocabulary, learning_rate, epoch, num_epochs, total_lines);
	}
	
	// Interaction loop
	std::string input_question;
	while (true) {
		std::cout << "Enter your question (or type 'exit' to quit): ";
		std::getline(std::cin, input_question);
		
		if (input_question == "exit") {
			break;
		}
		
		std::string generated_answer = rnn.generate_answer(input_question, vocabulary);
		
		std::cout << "Question: " << input_question << std::endl;
		std::cout << "Generated Answer: " << generated_answer << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "Exiting program." << std::endl;
	
	return 0;
}

