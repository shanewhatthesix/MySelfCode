#include "raylib.h"
#include <vector>
#include <cstddef>  // 包含 size_t

// 定义粒子结构
struct Particle {
	Vector2 position;
	Vector2 speed;
	float alpha; // 透明度，控制尾巴的消失
};

int main() {
	// 初始化窗口
	const int screenWidth = 800;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Comet Effect");
	
	// 设置游戏帧率
	SetTargetFPS(60);
	
	// 彗星的位置和速度
	Vector2 cometPosition = { 100.0f, screenHeight / 2.0f };
	Vector2 cometSpeed = { 3.0f, 0.0f };
	
	// 存储粒子的向量
	std::vector<Particle> particles;
	
	while (!WindowShouldClose()) {
		// 更新彗星位置
		cometPosition.x += cometSpeed.x;
		cometPosition.y += cometSpeed.y;
		
		// 生成新粒子
		Particle newParticle;
		newParticle.position = cometPosition;
		newParticle.speed = { -0.5f, 0.0f }; // 尾巴的粒子往回运动
		newParticle.alpha = 1.0f;
		particles.push_back(newParticle);
		
		// 更新粒子
		for (std::size_t i = 0; i < particles.size(); ++i) {
			particles[i].position.x += particles[i].speed.x;
			particles[i].alpha -= 0.01f; // 逐渐消失
			if (particles[i].alpha <= 0.0f) {
				particles.erase(particles.begin() + i);
				i--; // 删除粒子后需要调整索引
			}
		}
		
		// 开始绘制
		BeginDrawing();
		ClearBackground(BLACK);
		
		// 绘制彗星的主体
		DrawCircleV(cometPosition, 10, WHITE);
		
		// 绘制尾巴的粒子
		for (const auto& particle : particles) {
			Color particleColor = Color{ 255, 255, 255, static_cast<unsigned char>(particle.alpha * 255) };
			DrawCircleV(particle.position, 3, particleColor);
		}
		
		// 结束绘制
		EndDrawing();
	}
	
	// 关闭窗口
	CloseWindow();
	
	return 0;
}

