#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
    public:
        Player(sf::RenderWindow& window);

        void Draw();
        void Resize();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape mPlayer;
};