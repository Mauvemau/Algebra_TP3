#pragma once
#include "raylib.h"

#include "player.h"
#include "entity.h"

const int amountEntities = 16;

class Scene {
private:
	Entity* entities[amountEntities];

	Player* player;
	RenderTexture screenFirstPerson;
	RenderTexture screenTopDown;
	Rectangle splitScreenRect;

	void uninit();
	void draw();
	void update();
	void init();
public:
	Scene(int screenWidth, int screenHeight);
	~Scene();

	void run();
};