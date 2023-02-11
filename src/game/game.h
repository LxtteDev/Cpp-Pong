#include "../background/background.h"
#include "../player/player.h"
#include "../enemy/enemy.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
    public:
        Game(sf::Vector2f size);
        ~Game();

    private:
        void display();

        sf::RenderWindow mWindow; 
        Background& mBackground;

        Ball& mBall;
        Player& mPlayer;
        Enemy& mEnemy;

        bool open = 1;
        float deltaTime;
};

#endif