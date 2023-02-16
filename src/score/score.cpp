#include "score.h"

Score::Score(sf::RenderWindow &window): mWindow(window) {
    sf::Font arial;
    arial.loadFromFile("content/arial.ttf");

    Score::playerText.setFont(arial);
    Score::enemyText.setFont(arial);
    Score::playerText.setCharacterSize(60);
    Score::enemyText.setCharacterSize(60);
    Score::playerText.setString("00");
    Score::enemyText.setString("00");
}

void Score::updateScore(int player, int enemy) {
    Score::playerScore += player;
    Score::enemyScore += enemy;
}

void Score::draw(float deltaTime) {
    Score::mWindow.draw(Score::playerText);
    Score::mWindow.draw(Score::enemyText);
}