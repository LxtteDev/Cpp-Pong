#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Background {
    public:
        Background(sf::RenderWindow& window);

        void Draw();
        void Resize();

    private:
        sf::RenderWindow& mWindow;
        sf::RectangleShape divider;
};