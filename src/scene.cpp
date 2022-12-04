#include "scene.h"

#include "inputManager.h"
#include "player.h"

#include <iostream>

using namespace std;

// --

Scene::Scene(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "Frustum Culling Test");
    screenFirstPerson = LoadRenderTexture(screenWidth / 2, screenHeight);
    screenTopDown = LoadRenderTexture(screenWidth / 2, screenHeight);
    splitScreenRect = { 0.0f, 0.0f, static_cast<float>(screenFirstPerson.texture.width), static_cast<float>(-screenFirstPerson.texture.height) };

    player = new Player({ 0.0f, 2.0f, 0.0f }, { 0.0f, 0.0f }, 10.0f, 45.0f);

	cout << "Scene was created!\n";
}

Scene::~Scene() {
    delete player;
	cout << "Scene was destroyed!\n";
}

// Private

void Scene::uninit() {
    UnloadRenderTexture(screenFirstPerson);
    UnloadRenderTexture(screenTopDown);
    CloseWindow();
}

void Scene::draw() {
    // First Person.
    BeginTextureMode(screenFirstPerson);
        ClearBackground(RAYWHITE);
        BeginMode3D(player->getCameraFirstPerson());

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 50.0f, 50.0f }, LIGHTGRAY);

        EndMode3D();
    EndTextureMode();

    // Top Down.
    BeginTextureMode(screenTopDown);
        ClearBackground(RAYWHITE);
        BeginMode3D(player->getCameraTopDown());

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 50.0f, 50.0f }, LIGHTGRAY);
        player->draw();

        EndMode3D();
    EndTextureMode();

    // Screen.
    BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureRec(screenFirstPerson.texture, splitScreenRect, { 0, 0 }, WHITE);
        DrawTextureRec(screenTopDown.texture, splitScreenRect, { GetScreenWidth() / 2.0f, 0 }, WHITE);
        DrawFPS(1, 1);
    EndDrawing();
}

void Scene::update() {
    while (!WindowShouldClose()) {
        InputManager::managePlayerInput(player);
        player->update();

        draw();
    }
}

void Scene::init() {
    SetTargetFPS(60.0f);
}

// Public

void Scene::run() {
    init();
    update();
    uninit();
}