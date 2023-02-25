#include "score.h"

Score::Score(sf::RenderWindow &window, Ball& ball): mWindow(window), mBall(ball) {
    Score::font.loadFromFile("content/font.ttf");
    const_cast<sf::Texture&>(Score::font.getTexture(128)).setSmooth(false);

    Score::updateScore(0, 0);
    Score::Resize();
}

void Score::updateScore(int player, int enemy) {
    Score::playerScore += player;
    Score::enemyScore += enemy;
}

void Score::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());

    Score::playerPosition = sf::Vector2f(windowSize.x / 2 - 10.0f, 21.0f);
    Score::enemyPosition = sf::Vector2f(windowSize.x / 2 + 10.0f, 21.0f);
}

void Score::draw(float deltaTime) {
    // Update scores
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f ballPosition = Score::mBall.getPosition();
    sf::Vector2f ballVelocity = Score::mBall.getVelocity();
    if (canScore) {
        if (ballPosition.x <= 6 && ballVelocity.x < 0) {
            Score::updateScore(1, 0);
            canScore = 0;
        } else if (ballPosition.x >= windowSize.x - 6 && ballVelocity.x > 0) {
            Score::updateScore(0, 1);
            canScore = 0;
        }
    } else {
        float centre = windowSize.x / 2;
        if (ballPosition.x >= centre - 15.0f && ballPosition.x <= centre + 15.05)
            canScore = 1;
    }

    // Draw text
    std::string playerScore = std::to_string(this->playerScore);
    std::string enemyScore = std::to_string(this->enemyScore);

    sf::Text player(enemyScore, Score::font, 64);
    player.setOrigin(sf::Vector2f(player.getLocalBounds().width, 0));
    player.setPosition(Score::playerPosition);
    Score::mWindow.draw(player);

    sf::Text enemy(playerScore, Score::font, 64);
    enemy.setPosition(Score::enemyPosition);
    Score::mWindow.draw(enemy);
}