#include "score.h"

Score::Score(sf::RenderWindow &window): mWindow(window), playerText(sf::Text()), enemyText(sf::Text()) {
    sf::Font arial;
    arial.loadFromFile("content/arial.ttf");

    Score::playerText.setFont(arial);
    Score::enemyText.setFont(arial);

    Score::playerText.setCharacterSize(60);
    Score::enemyText.setCharacterSize(60);

    Score::playerText.setPosition(sf::Vector2f(0.0f, 0.0f));
    Score::enemyText.setPosition(sf::Vector2f(0.0f, 0.0f));
    
    Score::updateScore(0, 0);
    
    Score::mWindow.draw(Score::playerText);
}

void Score::updateScore(int player, int enemy) {
    Score::playerScore += player;
    Score::enemyScore += enemy;
    
    Score::playerText.setString("00");
    Score::enemyText.setString("00");
}

void Score::draw(float deltaTime) {
    // Score::mWindow.draw(Score::enemyText);
}