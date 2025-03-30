#include <raylib.h>
#include <vector>
#include <cmath>
#include <algorithm> // for std::remove_if

using namespace std;

const int SCREEN_WIDTH = 16 * 60;
const int SCREEN_HEIGHT = 9 * 60;
const int BALL_RADIUS = 9;
const int BALL_DIAMETER = 2 * BALL_RADIUS;

// 粒子结构体，表示拖尾效果
struct Particle {
	Vector2 position;  // 粒子的位置
	Vector2 speed;     // 粒子的速度
	float alpha;       // 粒子的透明度
};

// 小球结构体
struct Ball {
	Texture texture;       // 小球的纹理
	Vector2 position;      // 小球的位置
	Vector2 speed;         // 小球的速度
	vector<Particle> trail; // 存储小球的拖尾粒子
	
	// 初始化小球
	void init(float cx, float cy, float csx, float csy, Color color) {
		Image img = GenImageColor(BALL_DIAMETER, BALL_DIAMETER, BLANK); // 小球大小为 20x20
		ImageDrawCircle(&img, BALL_RADIUS, BALL_RADIUS, BALL_RADIUS - 1, color); // 小球半径为 9
		texture = LoadTextureFromImage(img);
		UnloadImage(img);
		position = {cx, cy};
		speed = {csx, csy};
	}
	
	// 移动小球
	void move() {
		position.x += speed.x;
		if (position.x + BALL_DIAMETER >= SCREEN_WIDTH || position.x <= 0) {  // 如果小球碰到屏幕边界，反弹
			speed.x *= -1;
		}
		position.y += speed.y;
		if (position.y + BALL_DIAMETER >= SCREEN_HEIGHT || position.y <= 0) {  // 如果小球碰到屏幕边界，反弹
			speed.y *= -1;
		}
		
		// 新粒子生成，粒子的位置在小球当前位置，并且速度稍微向反方向
		Particle newParticle;
		newParticle.position = { position.x + BALL_RADIUS, position.y + BALL_RADIUS };
		newParticle.speed = { -speed.x * 0.1f, -speed.y * 0.1f }; // 粒子的速度更平滑
		newParticle.alpha = 1.0f;
		trail.push_back(newParticle);
	}
	
	// 更新粒子的状态，模拟拖尾效果
	void updateTrail() {
		for (size_t i = 0; i < trail.size(); ++i) {
			trail[i].position.x += trail[i].speed.x;  // 更新粒子的位置
			trail[i].position.y += trail[i].speed.y;
			trail[i].alpha -= 0.01f;  // 渐变透明度，逐渐消失
		}
		
		// 使用 std::remove_if 删除透明度为 0 的粒子
		trail.erase(std::remove_if(trail.begin(), trail.end(), [](const Particle& p) {
			return p.alpha <= 0.0f;
		}), trail.end());
	}
	
	// 释放小球的纹理资源
	void unloadTexture() {
		UnloadTexture(texture);
	}
	
	// 检查小球是否与另一个小球碰撞
	bool checkCollision(const Ball& other) {
		float dx = position.x - other.position.x;
		float dy = position.y - other.position.y;
		float distance = sqrt(dx * dx + dy * dy);
		return distance <= BALL_DIAMETER;  // 如果距离小于等于小球直径，则认为发生碰撞
	}
	
	// 处理碰撞，交换小球的速度
	void handleCollision(Ball& other) {
		Vector2 temp_speed = speed;
		speed = other.speed;
		other.speed = temp_speed;
	}
};

// 创建n个随机的小球
vector<Ball> createRandomBalls(int n) {
	vector<Ball> balls;
	for (int i = 0; i < n; ++i) {
		Ball b;
		
		// 随机生成小球的位置
		float x = (float)(rand() % (SCREEN_WIDTH - BALL_DIAMETER)); // 保证小球不出界
		float y = (float)(rand() % (SCREEN_HEIGHT - BALL_DIAMETER));
		
		// 随机生成小球的速度，范围在 [5, 25]
		float sx = (float)(rand() % 21 + 5);
		float sy = (float)(rand() % 21 + 5);
		
		// 随机生成小球颜色
		Color color = Color{(unsigned char)(rand() % 256), (unsigned char)(rand() % 256), (unsigned char)(rand() % 256), 255};
		
		b.init(x, y, sx, sy, color);
		balls.push_back(b);
	}
	return balls;
}

int main() {
	// 初始化窗口
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "带拖尾的小球");
	SetTargetFPS(60);  // 设置帧率为 60
	
	// 创建 10 个随机的小球
	vector<Ball> balls = createRandomBalls(10);
	
	while (!WindowShouldClose()) {  // 当窗口没有关闭时
		// 移动小球并更新拖尾
		for (auto& ball : balls) {
			ball.move();
			ball.updateTrail();
		}
		
		// 碰撞检测和处理
		for (size_t i = 0; i < balls.size(); ++i) {
			for (size_t j = i + 1; j < balls.size(); ++j) {
				if (balls[i].checkCollision(balls[j])) {
					balls[i].handleCollision(balls[j]);
				}
			}
		}
		
		// 开始绘制
		BeginDrawing();
		ClearBackground(BLACK);  // 设置背景为黑色
		
		// 绘制拖尾粒子
		for (const auto& ball : balls) {
			for (const auto& particle : ball.trail) {
				Color particleColor = Color{255, 255, 255, static_cast<unsigned char>(particle.alpha * 255)};
				DrawCircleV(particle.position, 3, particleColor);  // 绘制粒子（小圆圈）
			}
		}
		
		// 绘制所有小球
		for (auto& ball : balls) {
			DrawTexture(ball.texture, (int)ball.position.x, (int)ball.position.y, WHITE);
		}
		
		EndDrawing();  // 结束绘制
	}
	
	// 释放资源
	for (auto& ball : balls) {
		ball.unloadTexture();
	}
	
	CloseWindow();  // 关闭窗口
	return 0;
}

