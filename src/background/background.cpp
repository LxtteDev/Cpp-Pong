#include "background.h"

Background::Background(sf::RenderWindow& window): mWindow(window) {
    this->Resize();
}

void Background::Draw() {
    for (sf::RectangleShape divider : Background::dividers) {
        this->mWindow.draw(divider);
    }
}

void Background::Resize() {
    Background::dividers.clear();

    sf::Vector2f windowSize(this->mWindow.getView().getSize());

    int count = ( windowSize.y - std::fmod(windowSize.y, 15.0f) ) / 15;
    int offset = windowSize.y - count * 15.0f + 5.0f;

    for (int i = 0; i < count; i++) {
        sf::Vector2f size(10.0f, 10.0f);
        sf::Vector2f position(windowSize.x / 2, i * 15.0f + offset);

        sf::RectangleShape divider(size);
        divider.setOrigin(size / 2.0f);
        divider.setPosition(position);
        dividers.push_back(divider);
    }
}