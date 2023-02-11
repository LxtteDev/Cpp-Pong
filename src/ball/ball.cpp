#include "ball.h"

Ball::Ball(sf::RenderWindow& window): mWindow(window) {
    float speed = 50.0f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    Ball::velocity = sf::Vector2f(dis(gen) == 0 ? -speed : speed, dis(gen) == 0 ? -speed : speed);

    this->Resize();
}

void Ball::Draw(float deltaTime, sf::Vector2f playerPosition) {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f move(Ball::velocity * deltaTime);
    sf::Vector2f position(Ball::mBall.getPosition() + move);

    // Bounds
    if (position.y <= 5.0f || position.y >= windowSize.y - 5.0f)
        Ball::velocity = sf::Vector2f(velocity.x, -velocity.y);
    if (position.x<= 5.0f || position.x >= windowSize.x - 5.0f)
        Ball::velocity = sf::Vector2f(-velocity.x, velocity.y);

    // Player padel
    float padelSize = windowSize.y / 7 / 2;
    if (position.y <= playerPosition.y + padelSize && position.y >= playerPosition.y - padelSize && position.x >= 24.0f && position.x <= 26.0f)
        Ball::velocity = sf::Vector2f(-velocity.x, velocity.y);

    Ball::mBall.setPosition(position);
    Ball::mWindow.draw(Ball::mBall);
}

void Ball::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(10.0f,10.0f);

    Ball::mBall = sf::RectangleShape(size);
    Ball::mBall.setOrigin(size / 2.0f);
    Ball::mBall.setPosition(windowSize / 2.0f);
}