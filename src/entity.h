#pragma once
#include "raylib.h"

class Entity {
private:
	Model model;

protected:
	Vector3 position;
	Vector3 scale;

public:
	Entity(Vector3 position, Vector3 scale);
	Entity(Vector3 position, Vector3 scale, Model model);
	virtual ~Entity();

	virtual void draw() = 0;
};