#include "../background/background.h"

class Game {
    public:
        Game(sf::Vector2f size);
        ~Game();

    private:
        void display();

        sf::RenderWindow mWindow; 
        Background& mBackground;

        bool open = 1;
        float deltaTime;
};
