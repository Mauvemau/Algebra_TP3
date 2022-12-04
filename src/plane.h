#pragma once
#include "entity.h"

class Plane : public Entity {
private:
	Color color;

public:
	Plane(Vector3 position, Vector2 scale, Color color);
	~Plane();

	void draw() override;
};