#include "cube.h"

#include <iostream>

using namespace std;

Cube::Cube(Vector3 position, Vector3 scale, Color color) :
Entity(position, scale) {
	this->color = color;
	cout << "Cube was created!\n";
}

Cube::~Cube() {
	cout << "Cube was destroyed!\n";
}

void Cube::draw() {
	DrawCube(position, scale.x, scale.y, scale.z, color);
}