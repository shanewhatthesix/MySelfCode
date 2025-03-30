#include <raylib.h>
#include <deque>
using namespace std;

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define MAX_POINTS    70    // 增加轨迹点数量
#define BALL_RADIUS   3     // 定义小球半径
#define TRAIL_WIDTH   3.0f  // 匹配轨迹粗细

struct TrailPoint {
	Vector2 position;
	float alpha;
};

int main() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "微型弹跳球");
	SetTargetFPS(60);
	
	// 创建3像素半径小球
	Image img = GenImageColor(BALL_RADIUS*2, BALL_RADIUS*2, BLANK);
	ImageDrawCircle(&img, BALL_RADIUS, BALL_RADIUS, BALL_RADIUS, SKYBLUE);
	Texture ballTex = LoadTextureFromImage(img);
	UnloadImage(img);
	
	// 运动参数（无重力）
	Vector2 position = { 400, 300 };
	Vector2 velocity = { 4.5f, -3.8f }; // 初始速度
	const float energyLoss = 0.92f;     // 碰撞能量损失
	
	deque<TrailPoint> trailPoints;
	
	while (!WindowShouldClose()) {
		// 纯水平运动（无重力影响）
		position.x += velocity.x;
		position.y += velocity.y;
		
		// 精确边界碰撞（考虑小球半径）
		if (position.x < 0) {
			velocity.x *= -energyLoss;
			position.x = 0;
		}
		if (position.x + BALL_RADIUS*2 > WINDOW_WIDTH) {
			velocity.x *= -energyLoss;
			position.x = WINDOW_WIDTH - BALL_RADIUS*2;
		}
		if (position.y < 0) {
			velocity.y *= -energyLoss;
			position.y = 0;
		}
		if (position.y + BALL_RADIUS*2 > WINDOW_HEIGHT) {
			velocity.y *= -energyLoss;
			position.y = WINDOW_HEIGHT - BALL_RADIUS*2;
		}
		
// 添加当前轨迹点（带位置修正）
		trailPoints.push_front({ 
			{ position.x + BALL_RADIUS, // 中心点校正
				position.y + BALL_RADIUS }, 
			255.0f 
		});
		
// 自动清理旧轨迹点
		while (trailPoints.size() > MAX_POINTS)
			trailPoints.pop_back();
		
		BeginDrawing();
		ClearBackground(BLACK);
		
// 绘制发光轨迹
		if (trailPoints.size() >= 2) {
			for (size_t i = 0; i < trailPoints.size()-1; ++i) {
				TrailPoint& current = trailPoints[i];
				TrailPoint& next = trailPoints[i+1];
				
				// 渐隐控制（非线性衰减）
				current.alpha *= 0.89f + (1.0f - i/(float)MAX_POINTS)*0.05f;
				Color trailColor = {
					100,  // R
					200,  // G
					255,  // B
					(unsigned char)(current.alpha * 0.4f)  // A
				};
				
				// 绘制双重线条增强效果
				DrawLineEx(
					current.position,
					next.position,
					TRAIL_WIDTH + 1.0f,
					Fade(trailColor, 0.3f)
					);
				DrawLineEx(
					current.position,
					next.position,
					TRAIL_WIDTH,
					trailColor
					);
			}
		}
		
// 绘制带光晕的小球
		DrawCircleV(trailPoints.front().position, BALL_RADIUS+1, Fade(WHITE, 0.3f));
		DrawTextureV(ballTex, position, WHITE);
		
// 实时状态显示
		DrawText(TextFormat("Velocity: (%.2f, %.2f)", velocity.x, velocity.y), 10, 10, 18, GREEN);
		DrawFPS(WINDOW_WIDTH - 90, 10);
		
		EndDrawing();
	}
	
	UnloadTexture(ballTex);
	CloseWindow();
	return 0;
}

