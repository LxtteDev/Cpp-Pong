#include "enemy.h"

Enemy::Enemy(sf::RenderWindow& window): mWindow(window) {
    this->Resize();
}

void Enemy::Draw(float deltaTime) {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(Enemy::mEnemy.getSize());

    float min = size.y / 2 + 10.0f;
    float max = windowSize.y - size.y / 2 - 10.0f;

    sf::Vector2f mousePosition(sf::Mouse::getPosition(Enemy::mWindow));
    // float y = Enemy::mMath.clamp(mousePosition.y, min, max);
    float y = mousePosition.y < min ? min : (mousePosition.y > max ? max : mousePosition.y);

    sf::Vector2f position(windowSize.x - 15.0f, y);
    Enemy::mEnemy.setPosition(position);

    Enemy::mWindow.draw(Enemy::mEnemy);
}

void Enemy::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(10.0f, windowSize.y / 7);

    Enemy::mEnemy = sf::RectangleShape(size);
    Enemy::mEnemy.setOrigin(size / 2.0f);
    Enemy::mEnemy.setPosition(sf::Vector2f(windowSize.x - 15.0f, size.y / 2 + 10.0f));
}