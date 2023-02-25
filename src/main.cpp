#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <iostream>
#include "game/game.h"

int main(int, char**) {
    Game game(sf::Vector2f(800, 600));
}
