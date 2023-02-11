#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#ifndef BALL_H_
#define BALL_H_

class Ball {
    public:
        Ball(sf::RenderWindow& window);

        void Draw(float deltaTime, sf::Vector2f playerPosition);
        void Resize();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape mBall;
        sf::Vector2f velocity;
};

#endif