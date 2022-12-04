#include "entity.h"

#include <iostream>

using namespace std;

Entity::Entity(Vector3 position, Vector3 scale) {
	this->position = position;
	this->scale = scale;
	model = { 0 };
	cout << "Entity was created!\n";
}

Entity::Entity(Vector3 position, Vector3 scale, Model model) {
	this->position = position;
	this->scale = scale;
	this->model = model;
	cout << "Entity was created!\n";
}

Entity::~Entity() {
	cout << "Entity was destroyed!\n";
}