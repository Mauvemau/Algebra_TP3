#include "scene.h"

#include "inputManager.h"
#include "player.h"

#include "plane.h"
#include "cube.h"

#include <iostream>

using namespace std;

// --

Scene::Scene(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "Frustum Culling Test");
    screenFirstPerson = LoadRenderTexture(screenWidth / 2, screenHeight);
    screenTopDown = LoadRenderTexture(screenWidth / 2, screenHeight);
    splitScreenRect = { 0.0f, 0.0f, static_cast<float>(screenFirstPerson.texture.width), static_cast<float>(-screenFirstPerson.texture.height) };

    player = new Player({ 0.0f, 2.0f, 0.0f }, { 0.0f, 0.0f }, 10.0f, 45.0f);

    entities[0] = new Plane({ 0.0f, 0.0f, 0.0f, }, { 50.0f, 50.0f }, LIGHTGRAY); // Floor
    entities[1] = new Cube({ 25.0f, 1.5f, 0.0f, }, { 1.0f, 3.0f, 50.0f }, BLUE); // Walls
    entities[2] = new Cube({ -25.0f, 1.5f, 0.0f, }, { 1.0f, 3.0f, 50.0f }, RED);
    entities[3] = new Cube({ 0.0f, 1.5f, 25.0f, }, { 50.0f, 3.0f, 1.0f }, ORANGE);
    entities[4] = new Cube({ 0.0f, 1.5f, -25.0f, }, { 50.0f, 3.0f, 1.0f }, GREEN);
    entities[5] = new Cube({ 6.0f, 1.0f, 6.0f, }, { 2.0f, 2.0f, 2.0f }, YELLOW); // Objects

	cout << "Scene was created!\n";
}

Scene::~Scene() {
    delete player;
    for (int i = 0; i < amountEntities; i++) {
        delete entities[i];
    }
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

        for (int i = 0; i < amountEntities; i++) {
            if(entities[i]) entities[i]->draw();
        }

        EndMode3D();
    EndTextureMode();

    // Top Down.
    BeginTextureMode(screenTopDown);
        ClearBackground(RAYWHITE);
        BeginMode3D(player->getCameraTopDown());

        for (int i = 0; i < amountEntities; i++) {
            if (entities[i]) entities[i]->draw();
        }

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