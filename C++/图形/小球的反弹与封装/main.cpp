#include <raylib.h>
#include<bits/stdc++.h>
using namespace std;

int kuan = 16 * 60, gao = 9 * 60;

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

};


int main() {


	//初始化窗口
	InitWindow(kuan, gao, "Test");
	SetTargetFPS(60);

	Ball b1;
	b1.init(0,0,5,9,BLACK);


	while (!WindowShouldClose()) {
		b1.move();

		//绘制帧
		BeginDrawing();//开始绘制
		ClearBackground(WHITE);//重新绘制一些背景。
		DrawTexture(b1.texture, b1.x, b1.y, WHITE);
		EndDrawing();//结束绘制
	}

	//释放texture对象
	b1.upload();

	//关闭窗口
	CloseWindow();
	return 0;
}

