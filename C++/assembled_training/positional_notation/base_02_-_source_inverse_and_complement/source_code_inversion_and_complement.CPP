/*
二进制的加法

在讲为什么会有补码这种反人类的东西之前，要先讲一下二进制的加法运算和二进制怎么表示负数 。

例如两个二进制数相加 ：
*---------------------------------------*
|		1	0	1	0	1	0	1	1	|
|---------------------------------------|
| +		1	0	0	0	1	1	0	1	|
|---------------------------------------|
| =	1	0	0	1	1	1	0	0	0	|
*---------------------------------------*
算了之后前面会多出来一个1，如果有效位数只有8位，那么这个1就会被舍去

规定：最前面一位是符号位，1表示负数，0表示正数

int 	32位（31位表示数 ） 
char 	64位（63位表示数 ） 

 

我们可以发现，当只有这种法则时，符号不同而绝对值相同的两数相加，结果却不是0

为了解决正数和负数的加法问题，其实就是减法问题，于是反码与补码被发明出来了

反码的计算过程是：除了符号位，所有位取反

补码的计算过程是：反码 + 1  

（注意：只有复负数按照上面的计算，正数的反码和补码都和原码一样）

*---------------------------------------*
|原码 | 1	0	1	0	1	0	1	1	|
|-----|---------------------------------|
|反码 | 1	1	0	1	0	1	0	0	|
|-----|---------------------------------|
|补码 | 1	1	0	1	0	1	0	1	|
*---------------------------------------*

-174 =  1 0 1 1 1 0 1 0 1

01010100 = 44

*/

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

class NeuralNetwork {
private:
    std::vector<std::vector<double>> input_weights;
    std::vector<double> hidden_bias;
    std::vector<std::vector<double>> hidden_weights;
    std::vector<double> output_bias;

    double random_weight() {
        return (double)rand() / RAND_MAX * 2 - 1; // 在-1到1之间
    }

    double random_bias() {
        return (double)rand() / RAND_MAX; // 在0到1之间
    }

public:
    NeuralNetwork() {
        // 初始化输入层到隐藏层的权重和偏置
        for (size_t i = 0; i < 4; ++i) {
            std::vector<double> weights;
            for (size_t j = 0; j < 3; ++j) {
                weights.push_back(random_weight());
            }
            input_weights.push_back(weights);
            hidden_bias.push_back(random_bias());
        }

        // 初始化隐藏层到输出层的权重和偏置
        for (size_t i = 0; i < 2; ++i) {
            std::vector<double> weights;
            for (size_t j = 0; j < 4; ++j) {
                weights.push_back(random_weight());
            }
            hidden_weights.push_back(weights);
            output_bias.push_back(random_bias());
        }
    }

    std::vector<double> forward(const std::vector<double>& input_data) {
        // 计算隐藏层的输入
        std::vector<double> hidden_input(4, 0.0);
        for (size_t i = 0; i < 4; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                hidden_input[i] += input_weights[i][j] * input_data[j];
            }
            hidden_input[i] += hidden_bias[i];
        }

        // 应用Sigmoid激活函数
        std::vector<double> hidden_output(4, 0.0);
        for (size_t i = 0; i < 4; ++i) {
            hidden_output[i] = sigmoid(hidden_input[i]);
        }

        // 计算输出层的输入
        std::vector<double> output_input(2, 0.0);
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 4; ++j) {
                output_input[i] += hidden_weights[i][j] * hidden_output[j];
            }
            output_input[i] += output_bias[i];
        }

        // 应用Sigmoid激活函数
        std::vector<double> output(2, 0.0);
        for (size_t i = 0; i < 2; ++i) {
            output[i] = sigmoid(output_input[i]);
        }

        return output;
    }
};

int main() {
    srand(time(NULL)); // 初始化随机数生成器

    NeuralNetwork nn;
    std::vector<double> input_data = {0.5, 0.6, 0.7};
    std::vector<double> output = nn.forward(input_data);

    for (double o : output) {
        std::cout << o << " ";
    }
    std::cout << std::endl;

    return 0;
}

