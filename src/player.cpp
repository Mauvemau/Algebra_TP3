#include "player.h"

#include "inputManager.h"

#include "utils.h"

#include <iostream>

using namespace std;

// --

Player::Player(Vector3 position, Rotation rotation, float speed, float fov) {
	this->position = position;
	this->rotation = rotation;
    this->speed = speed;
	initCamera(fov);
    cout << "Player was created\n";
}

Player::~Player() {
    cout << "Player was destroyed\n";
}

// Private

void Player::updateCamera() {
    // First Person.
    cameraFirstPerson.position = position;
    cameraFirstPerson.target = { position.x + cosf(rotation.y), position.y, position.z + sinf(rotation.y) };
    // Top Down.
    cameraTopDown.position = { position.x, 25.0f, position.z };
    cameraTopDown.target = position;
}

void Player::initCamera(float fov) {
    // First Person.
    updateCamera();
    cameraFirstPerson.up = { 0.0f, 1.0f, 0.0f };
    cameraFirstPerson.fovy = fov;
    cameraFirstPerson.projection = CAMERA_PERSPECTIVE;
    // Top Down.
    cameraTopDown.fovy = fov;
    cameraTopDown.projection = CAMERA_PERSPECTIVE;
}

// Public

Camera Player::getCameraFirstPerson() {
    return cameraFirstPerson;
}

Camera Player::getCameraTopDown() {
    return cameraTopDown;
}


void Player::draw() {
    Vector3 endPos = { position.x + cosf(rotation.y), position.y, position.z + sinf(rotation.y) };
    DrawSphere(position, .5f, RED);
    DrawLine3D(position, endPos, GREEN);
}

void Player::rotate(Rotation direction) {
    rotation.x += direction.x * (2.5f * GetFrameTime());
    rotation.y += direction.y * (2.5f * GetFrameTime());
    updateCamera();
}

void Player::move(Direction direction) {
    switch (direction)
    {
    case Direction::FORWARD:
        position.x += cosf(rotation.y) * (speed * GetFrameTime());
        position.z += sinf(rotation.y) * (speed * GetFrameTime());
        break;
    case Direction::LEFT:
        position.x -= cosf(rotation.y + Utils::DegreesToRadians(90.0f)) * (speed * GetFrameTime());
        position.z -= sinf(rotation.y + Utils::DegreesToRadians(90.0f)) * (speed * GetFrameTime());
        break;
    case Direction::BACKWARDS:
        position.x -= cosf(rotation.y) * (speed * GetFrameTime());
        position.z -= sinf(rotation.y) * (speed * GetFrameTime());
        break;
    case Direction::RIGHT:
        position.x += cosf(rotation.y + Utils::DegreesToRadians(90.0f)) * (speed * GetFrameTime());
        position.z += sinf(rotation.y + Utils::DegreesToRadians(90.0f)) * (speed * GetFrameTime());
        break;
    default:
        break;
    }
    updateCamera();
}

void Player::update() {

}