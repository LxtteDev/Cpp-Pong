#include "enemy.h"

Enemy::Enemy(sf::RenderWindow& window, Ball& ball): mWindow(window), mBall(ball) {
    this->Resize();
}

void Enemy::Draw(float deltaTime) {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(Enemy::mEnemy.getSize());

    // Predict ball (Could be better, doest make mistakes)
    sf::Vector2f ballPosition = Enemy::mBall.getPosition();
    sf::Vector2f ballVelocity = Enemy::mBall.getVelocity();
    if (ballPosition.x > windowSize.x / 2 && ballVelocity.x > 0) {
        float y = 0;
        float min = size.y / 2 + 10.0f;
        float max = windowSize.y - size.y / 2 - 10.0f;

        if (ballVelocity.y < 0) {
            // Moving up
            float distanceToTop = ballPosition.y;
            float distanceToPadel = windowSize.x - ballPosition.x - 30.0f;

            if (distanceToPadel > distanceToTop) {
                sf::Vector2f firstPrediction(ballPosition + sf::Vector2f(distanceToTop, -distanceToTop));
                float newDistanceToPadel = windowSize.x - firstPrediction.x - 30.0f;
                sf::Vector2f prediction(firstPrediction + sf::Vector2f(newDistanceToPadel, newDistanceToPadel));
                y = prediction.y;
            } else {
                sf::Vector2f prediction(ballPosition + sf::Vector2f(distanceToPadel, -distanceToPadel));
                y = prediction.y;
            }
        } else {
            float distanceToBottom = windowSize.y - ballPosition.y;
            float distanceToPadel = windowSize.x - ballPosition.x - 30.0f;

            if (distanceToPadel > distanceToBottom) {
                sf::Vector2f firstPrediction(ballPosition + sf::Vector2f(distanceToBottom, distanceToBottom));
                float newDistanceToPadel = windowSize.x - firstPrediction.x - 30.0f;
                sf::Vector2f prediction(firstPrediction + sf::Vector2f(newDistanceToPadel, -newDistanceToPadel));
                y = prediction.y;
            } else {
                sf::Vector2f prediction(ballPosition + sf::Vector2f(distanceToPadel, distanceToPadel));
                y = prediction.y;
            }
        }

        y = y < min ? min : (y > max ? max : y);

        float currentPosition = Enemy::mEnemy.getPosition().y;
        float tweenValue = currentPosition + (y - currentPosition) * 1.0f * deltaTime;
        Enemy::mEnemy.setPosition(sf::Vector2f(windowSize.x - 15.0f, tweenValue));

        if (abs(y - currentPosition) < 0.1)
            Enemy::mEnemy.setPosition(sf::Vector2f(windowSize.x - 15.0f, y));
    }
    
    Enemy::mWindow.draw(Enemy::mEnemy);
}

void Enemy::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(10.0f, windowSize.y / 7);

    Enemy::mEnemy = sf::RectangleShape(size);
    Enemy::mEnemy.setOrigin(size / 2.0f);
    Enemy::mEnemy.setPosition(sf::Vector2f(windowSize.x - 15.0f, size.y / 2 + 10.0f));
}

sf::Vector2f Enemy::getPosition() {
    return Enemy::mEnemy.getPosition();
}