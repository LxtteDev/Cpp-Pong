#include "game.h"

Game::Game(sf::Vector2f size):
    mWindow(sf::VideoMode(size.x, size.y), "Pong"),
    mBackground(Background(mWindow)),
    mPlayer(Player(mWindow)),
    mBall(Ball(mWindow)),
    mScore(Score(mWindow)),
    mEnemy(Enemy(mWindow, mBall))
{
    std::cout << "Creating game" << std::endl;

    this->display();

    std::cout << "Closing game" << std::endl;
}

Game::~Game() {
}

void Game::display() {
    sf::Clock clock;

    while (this->open) {
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();
        this->deltaTime = deltaSeconds;

        sf::Event e;
		while (this->mWindow.pollEvent(e))
			if (e.type == sf::Event::Closed)
                this->open=0;
            else if (e.type == sf::Event::Resized) {
                this->mWindow.setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
                Game::mBackground.Resize();
                Game::mPlayer.Resize();
                Game::mBall.Resize();
                Game::mEnemy.Resize();
            }

        // this->mWindow.clear();

        Game::mBackground.Draw(this->deltaTime);
        Game::mPlayer.Draw(this->deltaTime);
        Game::mEnemy.Draw(this->deltaTime);
        Game::mBall.Draw(this->deltaTime, Game::mPlayer.getPosition(), Game::mEnemy.getPosition());
        Game::mScore.draw(this->deltaTime);

        this->mWindow.display();
    }

    this->mWindow.close();
}
