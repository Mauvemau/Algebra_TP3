#pragma once
#include "raylib.h"

enum class Direction {
	FORWARD,
	LEFT,
	BACKWARDS,
	RIGHT
};

struct Rotation {
	float x;
	float y;
};

class Player {
private:
	Camera cameraFirstPerson;
	Camera cameraTopDown;
	Vector3 position;
	Rotation rotation;
	float speed;

	void updateCamera();
	void initCamera(float fov);
public:

	Player(Vector3 position, Rotation rotation, float speed, float fov);
	~Player();

	Camera getCameraFirstPerson();
	Camera getCameraTopDown();

	void draw();

	void rotate(Rotation direction);
	void move(Direction direction);
	void update();
};