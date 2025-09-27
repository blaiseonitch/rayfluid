#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simulating Fluids | Raylib");

  Ball ball;
  ball.position = (Vector2){400, 300};
  ball.radius = 5;

  while (!WindowShouldClose()) {
    float randomPos1 = RandomNumber((int)SCREEN_WIDTH);
    float randomPos2 = RandomNumber((int)SCREEN_HEIGHT);
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i <= 20; i++) {
      // DrawCircleV(ball.position, ball.radius, MAGENTA);
      DrawCircleV((Vector2){randomPos1, randomPos2}, ball.radius, MAGENTA);
    }
    EndDrawing();
  }

  return 0;
}
