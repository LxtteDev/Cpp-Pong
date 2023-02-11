#include "../background/background.h"
#include "../player/player.h"

class Game {
    public:
        Game(sf::Vector2f size);
        ~Game();

    private:
        void display();

        sf::RenderWindow mWindow; 
        Background& mBackground;
        Player& mPlayer;

        bool open = 1;
        float deltaTime;
};
