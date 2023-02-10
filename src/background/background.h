#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Background {
    public:
        Background(sf::RenderWindow& window);

        void Draw();
        void Resize();

    private:
        sf::RenderWindow& mWindow;
        std::vector<sf::RectangleShape> dividers;
};