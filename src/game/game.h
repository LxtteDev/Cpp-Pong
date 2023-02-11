#include "../background/background.h"
#include "../player/player.h"
#include "../ball/ball.h"

class Game {
    public:
        Game(sf::Vector2f size);
        ~Game();

    private:
        void display();

        sf::RenderWindow mWindow; 
        Background& mBackground;
        Player& mPlayer;
        Ball& mBall;

        bool open = 1;
        float deltaTime;
};
