#include "game.h"

Game::Game(sf::Vector2f size): mWindow(sf::VideoMode(size.x, size.y), "Pong") {
    std::cout << "Creating game" << std::endl;

    this->display();

    std::cout << "Closing game" << std::endl;
}

Game::~Game() {
}

void Game::display() {
    sf::Clock clock;

    while (this->open) {
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();
        this->deltaTime = deltaSeconds / 1000;

        sf::Event e;
		while (this->mWindow.pollEvent(e))
			if (e.type == sf::Event::Closed)
                this->open=0;

        this->mWindow.display();
    }

    this->mWindow.close();
}
