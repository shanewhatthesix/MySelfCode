#include <raylib.h>
#include<bits/stdc++.h>
using namespace std;
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

struct Ball{
	Texture t;
	int x,y;
	int speedx,speedy;
};

int main() {
	
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT,"Test");
	SetTargetFPS(60);
	
	Ball ballarray[5];
	for(int i=0;i<5;++i){
		Image img=GenImageColor(40,40,BLANK);
		ImageDrawCircle(&img,20,20,19,RED);
		ballarray[i].t = LoadTextureFromImage(img);
		UnloadImage(img);
		
		ballarray[i].x=0;
		ballarray[i].y=0;
		
		//这里用个简单的方式让小球有不同的速度。
		//大家也可以研究下随机数
		ballarray[i].speedx=(6-i);
		ballarray[i].speedy=(6+i);
		
	}
	
	//创建一个玩家的金色传说
	Image playerimg=GenImageColor(40,40,BLANK);
	ImageDrawCircle(&playerimg,20,20,19,GOLD);
	Texture playertexture = LoadTextureFromImage(playerimg);
	UnloadImage(playerimg);
	
	while (!WindowShouldClose()) {
		
		for(int i=0;i<5;++i){
			//判断本次运动后，是否碰到了边界 
			if(ballarray[i].x+ballarray[i].speedx>=WINDOW_WIDTH-40 || ballarray[i].x+ballarray[i].speedx<=0){
				ballarray[i].speedx*=-1;
			}
			if(ballarray[i].y+ballarray[i].speedy>=WINDOW_HEIGHT-40 || ballarray[i].y+ballarray[i].speedy<=0){
				ballarray[i].speedy*=-1;
			} 
			ballarray[i].x+=ballarray[i].speedx;
			ballarray[i].y+=ballarray[i].speedy;
		}
		
		int px=GetMouseX();
		int py=GetMouseY();
		
		//绘制帧，这一Part都是放在循环的最后的
		BeginDrawing();//开始绘制
		ClearBackground(WHITE);//重新绘制一些背景。
		for(int i=0;i<5;++i){
			DrawTexture(ballarray[i].t,ballarray[i].x,ballarray[i].y,WHITE);
		}
		DrawTexture(playertexture,px-20,py-20,WHITE);
		EndDrawing();//结束绘制
	}
	
	//释放texture对象
	for(int i=0;i<5;++i){
		UnloadTexture(ballarray[i].t); 
	}
	
	UnloadTexture(playertexture);
	
	//关闭窗口
	CloseWindow();
	return 0;
}



