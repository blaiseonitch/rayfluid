#include "raylib.h"

int main(){
	int gravity = 5;
	Vector2 position;
	Vector2 velocity;

	InitWindow(800, 600, "Simulating Fluids | Raylib");
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawCircle(400, 300, 10, RAYWHITE);
		EndDrawing();
	}

	return 0;
}
