#pragma once

#include "entity.h"

class Cube : public Entity {
private:
	Color color;

public:
	Cube(Vector3 position, Vector3 scale, Color color);
	~Cube();

	void draw() override;
};