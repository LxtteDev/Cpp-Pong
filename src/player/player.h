#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
    public:
        Player(sf::RenderWindow& window);

        void Draw(float deltaTime);
        void Resize();
        sf::Vector2f getPosition();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape mPlayer;
};

#endif