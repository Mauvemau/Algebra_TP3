#pragma once
#include "raylib.h"

#include "player.h"

class Scene {
private:
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