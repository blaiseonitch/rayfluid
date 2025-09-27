#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BALL_COUNT 50

typedef struct {
  Vector2 position;
  Vector2 velocity;
  float radius;
  float size;
} Ball;

float RandomNumber(int x) {
  // Generate random number between 0 and x
  int number = (rand() % x) + 1;
  printf("%d\n", number);
  return (float)number;
}

int main() {
	SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simulating Fluids | Raylib");

  Ball balls[BALL_COUNT];
	for (int i=0; i<=BALL_COUNT; i++) {
		balls[i].position = (Vector2){RandomNumber(SCREEN_WIDTH), RandomNumber(SCREEN_HEIGHT)};
		balls[i].radius = 5;
		balls[i].velocity = (Vector2){RandomNumber(2), RandomNumber(2)};
	}

  while (!WindowShouldClose()) {
		for (int i = 0; i<=BALL_COUNT; i++) {
			balls[i].position.x += 1.0f;
			balls[i].position.y += 1.0f;

			// bounce if touching edge of window
		}

    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i <= BALL_COUNT; i++) {
      // DrawCircleV(ball.position, ball.radius, MAGENTA);
      DrawCircleV(balls[i].position, balls[i].radius, MAGENTA);
    }
    EndDrawing();
  }

  return 0;
}
