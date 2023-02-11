#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
    public:
        Player(sf::RenderWindow& window);

        void Draw(float deltaTime);
        void Resize();
        sf::Vector2f getPosition();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape mPlayer;
};