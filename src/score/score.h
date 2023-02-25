#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include "../ball/ball.h"

#ifndef SCORE_H_
#define SCORE_H_

class Score {
    public:
        Score(sf::RenderWindow& window, Ball& ball);

        void updateScore(int player, int enemey);
        void Resize();
        void draw(float deltaTime);
    private:
        Ball& mBall;
        sf::RenderWindow& mWindow;
        sf::Font font;

        sf::Vector2f playerPosition;
        sf::Vector2f enemyPosition;

        bool canScore = 1;
        int playerScore = 0;
        int enemyScore = 0;
};

#endif