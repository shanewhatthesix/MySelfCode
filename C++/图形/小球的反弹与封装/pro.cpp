#include <raylib.h>
#include <bits/stdc++.h>
using namespace std;

int kuan = 16 * 90, gao = 9 * 90;

struct Ball {
	Texture texture;
	int x, y;
	int sx, sy;
	
	void init(int cx, int cy, int csx, int csy, Color color) {
		Image img = GenImageColor(40, 40, BLANK);
		ImageDrawCircle(&img, 20, 20, 19, color);
		texture = LoadTextureFromImage(img);
		UnloadImage(img);
		x = cx, y = cy;
		sx = csx, sy = csy;
	}
	
	void move() {
		x += sx;
		if (x + 40 >= kuan || x <= 0) {
			sx *= -1;
		}
		y += sy;
		if (y + 40 >= gao || y <= 0) {
			sy *= -1;
		}
	}
	
	void upload() {
		UnloadTexture(texture);
	}
	
	bool checkCollision(const Ball& other) {
		int dx = x - other.x;
		int dy = y - other.y;
		int distance = sqrt(dx * dx + dy * dy);
		return distance <= 40;
	}
	
	void handleCollision(Ball& other) {
		int temp_sx = sx;
		int temp_sy = sy;
		sx = other.sx;
		sy = other.sy;
		other.sx = temp_sx;
		other.sy = temp_sy;
	}
};

// 创建n个全参数随机的小球
vector<Ball> createRandomBalls(int n) {
	vector<Ball> balls;
	for (int i = 0; i < n; ++i) {
		Ball b;
		
		// 随机生成小球位置
		int x = rand() % (kuan - 40); // 保证小球不出界
		int y = rand() % (gao - 40);
		
		// 随机生成小球速度，范围调整至[5, 25]
		int sx = rand() % 21 + 5; // 范围为[5, 25]
		int sy = rand() % 21 + 5; // 范围为[5, 25]
		
		// 随机生成颜色
		Color color = Color{(unsigned char)(rand() % 256), (unsigned char)(rand() % 256), (unsigned char)(rand() % 256), 255};
		
		b.init(x, y, sx, sy, color);
		balls.push_back(b);
	}
	return balls;
}

int main() {
	// 初始化窗口
	InitWindow(kuan, gao, "Test");
	SetTargetFPS(60);
	
	// 创建10个随机小球
	vector<Ball> balls = createRandomBalls(100);
	
	while (!WindowShouldClose()) {
		// 移动所有小球
		for (auto& ball : balls) {
			ball.move();
		}
		
		// 碰撞检测
		for (size_t i = 0; i < balls.size(); ++i) {
			for (size_t j = i + 1; j < balls.size(); ++j) {
				if (balls[i].checkCollision(balls[j])) {
					balls[i].handleCollision(balls[j]);
				}
			}
		}
		
		// 绘制帧
		BeginDrawing(); // 开始绘制
		ClearBackground(WHITE); // 重新绘制背景
		
		// 绘制所有小球
		for (auto& ball : balls) {
			DrawTexture(ball.texture, ball.x, ball.y, WHITE);
		}
		
		EndDrawing(); // 结束绘制
	}
	
	// 释放texture对象
	for (auto& ball : balls) {
		ball.upload();
	}
	
	// 关闭窗口
	CloseWindow();
	return 0;
}

