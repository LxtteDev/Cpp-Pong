#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SCORE_H_
#define SCORE_H_

class Score {
    public:
        Score(sf::RenderWindow& window);

        void updateScore(int player, int enemey);
        void draw(float deltaTime);
    private:
        sf::RenderWindow& mWindow;

        sf::Text& playerText;
        int playerScore = 0;

        sf::Text& enemyText;
        int enemyScore = 0;
};

#endif