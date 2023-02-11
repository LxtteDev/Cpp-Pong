#include "player.h"

float clamp(float value, float lower, float upper) {
    return value < lower ? lower : (value > upper ? upper : value);
}

Player::Player(sf::RenderWindow& window): mWindow(window) {
    this->Resize();
}

void Player::Draw(float deltaTime) {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(Player::mPlayer.getSize());

    float min = size.y / 2 + 10.0f;
    float max = windowSize.y - size.y / 2 - 10.0f;

    sf::Vector2f mousePosition(sf::Mouse::getPosition(Player::mWindow));
    float y = clamp(mousePosition.y, min, max);

    sf::Vector2f position(15.0f, y);
    Player::mPlayer.setPosition(position);

    Player::mWindow.draw(Player::mPlayer);
}

void Player::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f size(10.0f, windowSize.y / 7);

    Player::mPlayer = sf::RectangleShape(size);
    Player::mPlayer.setOrigin(size / 2.0f);
    Player::mPlayer.setPosition(sf::Vector2f(15.0f, size.y / 2 + 10.0f));
}

sf::Vector2f Player::getPosition() {
    return Player::mPlayer.getPosition();
}