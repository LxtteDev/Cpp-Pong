#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
    public:
        Game(sf::Vector2f size);
        ~Game();

    private:
        void display();

        sf::Window mWindow;    
        bool open = 1;
        float deltaTime;
};
