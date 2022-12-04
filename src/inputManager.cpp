#include "inputManager.h"

void InputManager::managePlayerInput(Player* player) {
    // Forward/Backwards
    if (IsKeyDown(KEY_W)) {
        player->move(Direction::FORWARD);
    }
    else if (IsKeyDown(KEY_S)) {
        player->move(Direction::BACKWARDS);
    }

    // Strafing Sideways.
    if (IsKeyDown(KEY_A)) {
        player->move(Direction::LEFT);
    }
    else if (IsKeyDown(KEY_D)) {
        player->move(Direction::RIGHT);
    }

    // Rotating Sideways.
    if (IsKeyDown(KEY_LEFT)) {
        player->rotate({ 0, -1 });
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        player->rotate({ 0, 1 });
    }
}