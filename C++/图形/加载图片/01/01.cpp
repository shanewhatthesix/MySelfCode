#include <raylib.h>
#include <iostream>
using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
	// 初始化窗口
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Test");
	SetTargetFPS(60);
	
	// 红色小球属性 (WSAD控制)
	Vector2 redBallPosition = { 100, 100 };
	float redBallRadius = 20;
	float redBallBaseRadius = 20;
	float redBallScaleFactor = 1.0f;
	bool redBallIsScaling = false;
	
	// 蓝色小球属性 (上下左右控制)
	Vector2 blueBallPosition = { 600, 400 };
	float blueBallRadius = 20;
	
	// 加载图片
	Image starting = LoadImage("start_normal.png");
	Texture startnormal = LoadTextureFromImage(starting);
	UnloadImage(starting);
	
	Rectangle btnframe;
	btnframe.x = 300;
	btnframe.y = 300;
	btnframe.width = startnormal.width;
	btnframe.height = startnormal.height;
	
	int index = 0;
	bool hasCollided = false; // 标记是否已经碰撞过
	
	// 开启程序的主循环
	while (!WindowShouldClose()) {
		// 红色小球移动控制 (WSAD)
		if (IsKeyDown(KEY_W)) redBallPosition.y -= 2;
		if (IsKeyDown(KEY_S)) redBallPosition.y += 2;
		if (IsKeyDown(KEY_A)) redBallPosition.x -= 2;
		if (IsKeyDown(KEY_D)) redBallPosition.x += 2;
		
		// 红色小球缩放控制 (空格)
		if (IsKeyPressed(KEY_SPACE)) {
			redBallIsScaling = true;
			redBallScaleFactor = 2.0f; // 放大两倍
		}
		
		// 红色小球缩放逻辑 (简化)
		if (redBallIsScaling) {
			redBallScaleFactor -= 0.05f; // 逐渐缩小
			if (redBallScaleFactor <= 1.0f) {
				redBallScaleFactor = 1.0f; // 恢复原始大小
				redBallIsScaling = false;
			}
		}
		
		// 蓝色小球移动控制 (上下左右)
		if (IsKeyDown(KEY_UP)) blueBallPosition.y -= 2;
		if (IsKeyDown(KEY_DOWN)) blueBallPosition.y += 2;
		if (IsKeyDown(KEY_LEFT)) blueBallPosition.x -= 2;
		if (IsKeyDown(KEY_RIGHT)) blueBallPosition.x += 2;
		
		// 碰撞检测
		bool collision = CheckCollisionCircleRec(redBallPosition, redBallRadius * redBallScaleFactor, btnframe);
		
		if (collision && !hasCollided) {
			index++;
			hasCollided = true; // 设置为已碰撞
			cout << "Collision detected! Index: " << index << endl;
		} else if (!collision) {
			hasCollided = false; // 如果不再碰撞，重置标记
		}
		
		// 绘制帧
		BeginDrawing();
		ClearBackground(WHITE);
		
		// 绘制红色小球 (半径随 scaleFactor 变化)
		DrawCircleV(redBallPosition, redBallRadius * redBallScaleFactor, RED);
		
		// 绘制蓝色小球
		DrawCircleV(blueBallPosition, blueBallRadius, BLUE);
		
		// 绘制图片
		DrawTexture(startnormal, 300, 300, WHITE);
		
		EndDrawing();
	}
	
	// 卸载纹理
	UnloadTexture(startnormal);
	
	// 关闭窗口
	CloseWindow();
	return 0;
}

