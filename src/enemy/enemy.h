#include <SFML/Graphics.hpp>
#include <iostream>
#include "../ball/ball.h"

#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy {
    public:
        Enemy(sf::RenderWindow& window, Ball& ball);

        void Draw(float deltaTime);
        void Resize();
        sf::Vector2f getPosition();

    private:
        Ball& mBall;
        sf::RenderWindow& mWindow;
        sf::RectangleShape mEnemy;
};

#endif