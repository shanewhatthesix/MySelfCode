#include <raylib.h>
#include <bits/stdc++.h>
using namespace std;
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
	
	// 初始化窗口
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Qwen-Logo");
	
	SetTargetFPS(60);
	
	// 加载一个图片
	Image backing = LoadImage("qwen.png");
	Texture backTexture = LoadTextureFromImage(backing);
	UnloadImage(backing);
	
	// 位置
	float x = 0;
	float y = 0;
	float speedX = 1.0f;
	float speedY = 0.5f;
	
	// 旋转
	float rotation = 0.0f;
	float rotationSpeed = 1.0f;
	
	// 缩放
	float scale = 1.0f;
	float scaleSpeed = 0.01f;
	
	// 图片的中心点
	Vector2 origin = { (float)backTexture.width / 2, (float)backTexture.height / 2 };
	
	// 开启程序的主循环
	while (!WindowShouldClose()) {
		
		// 运算
		
		// 移动
		x += speedX;
		y += speedY;
		
		// 考虑缩放后的图片宽高来判断边界
		float scaledWidth = backTexture.width * scale;
		float scaledHeight = backTexture.height * scale;
		
		// 反弹检测
		if (x > WINDOW_WIDTH - scaledWidth || x < 0) {
			speedX = -speedX;
		}
		if (y > WINDOW_HEIGHT - scaledHeight || y < 0) {
			speedY = -speedY;
		}
		
		// 旋转
		rotation += rotationSpeed;
		if (rotation > 360.0f) {
			rotation -= 360.0f;
		}
		
		// 缩放
		scale += scaleSpeed;
		if (scale > 2.0f || scale < 0.5f) {
			scaleSpeed = -scaleSpeed;
		}
		
		// 绘制帧
		BeginDrawing();
		ClearBackground(WHITE);
		
		// 绘制图片对象
		Vector2 position = {x + scaledWidth / 2, y + scaledHeight / 2}; //调整position，使旋转中心保持在图片中心
		DrawTextureEx(backTexture, position, rotation, scale, WHITE);
		
		EndDrawing();
	}
	
	// 卸载纹理
	UnloadTexture(backTexture);
	
	// 关闭窗口
	CloseWindow();
	return 0;
}

