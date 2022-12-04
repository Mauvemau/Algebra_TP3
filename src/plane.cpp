#include "plane.h"

#include <iostream>

using namespace std;

Plane::Plane(Vector3 position, Vector2 scale, Color color) :
Entity(position, {scale.x, 0.0f, scale.y}) {
	this->color = color;
	cout << "Plane was created!\n";
}

Plane::~Plane() {
	cout << "Plane was destroyed!\n";
}

void Plane::draw() {
	DrawPlane(position, { scale.x, scale.z }, color);
}