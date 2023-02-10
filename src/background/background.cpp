#include "background.h"

Background::Background(sf::RenderWindow& window): mWindow(window) {
    // TODO Create dashed bar
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f dividerSize(10, windowSize.y);

    Background::divider = sf::RectangleShape(dividerSize);
    Background::divider.setOrigin(dividerSize / 2.0f);
    Background::divider.setPosition(windowSize / 2.0f);
}

void Background::Draw() {
    this->mWindow.draw(Background::divider);
}

void Background::Resize() {
    sf::Vector2f windowSize(this->mWindow.getView().getSize());
    sf::Vector2f dividerSize(10, windowSize.y);

    Background::divider.setSize(dividerSize);
    Background::divider.setOrigin(dividerSize / 2.0f);
    Background::divider.setPosition(windowSize / 2.0f);

}