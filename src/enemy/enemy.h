#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy {
    public:
        Enemy(sf::RenderWindow& window);

        void Draw(float deltaTime);
        void Resize();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape mEnemy;
};

#endif