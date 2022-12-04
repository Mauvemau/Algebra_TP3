#include "scene.h"

int main() {
	Scene* scene = new Scene(1280, 720);

	scene->run();

	delete scene;
	return 0;
}