#include "raylib.h"
#include <stdio.h>

typedef struct {
  Vector2 position;
  Vector2 velocity;
  float radius;
  float size;
} Ball;

// float

int main() {
  InitWindow(800, 600, "Simulating Fluids | Raylib");
  SetTargetFPS(60);

  Ball ball;
  ball.position = (Vector2){400, 300};
  ball.radius = 5;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
		for (int i = 0; i <= 20; i++) {
			DrawCircleV(ball.position, ball.radius, MAGENTA);
		}
    EndDrawing();
  }

  return 0;
}
