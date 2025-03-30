#include <raylib.h>
#include<bits/stdc++.h>
using namespace std;

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

struct Button{
	Texture2D text;
	Texture2D hover;
	Rectangle frame;
	
	void init(const char *fileName,int x,int y){
		text = LoadTexture(fileName);
		frame.x=x;
		frame.y=y;
		frame.width=text.width;
		frame.height=text.height;
	}
	
	
	
	void unload(){
		UnloadTexture(text);
	}
	void draw(){
		DrawTexture (text, frame.x, frame.y, WHITE);
	}
};

int main() {
	
	//初始化窗口
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT,"保卫萝卜");
	SetTargetFPS(60);
	
	Texture2D bg = LoadTexture("images/mainpage/back.png");
	
	Button adventure;
	adventure.init("images/mainpage/adventurehover.png",100,500);
	
	
	//开启程序的主循环
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		
		DrawTexture(bg,0,0,WHITE);
		
		EndDrawing();
	}
	
	//关闭窗口
	CloseWindow();
	return 0;
}

