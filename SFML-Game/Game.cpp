
#include "Game.h"

//temporary fix variable 
sf::Texture textr;

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer(), mWorld(mWindow) {}

void Game :: run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (mWindow.isOpen())
	{
        if(!mPaused){
        
            timeSinceLastUpdate += clock.restart();
		
            while (timeSinceLastUpdate > TIME_PER_FRAME)
            {
                processEvents();
                update(TIME_PER_FRAME);
		
                timeSinceLastUpdate -= TIME_PER_FRAME;
            }
		
            render();
        }
        else
        {
            processEvents();
            clock.restart();
        }
	}
}

void Game :: processEvents()
{
	sf::Event event;
	
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				mWindow.close();
				break;
            case sf::Event::GainedFocus:
                mPaused = false;
                break;
            case sf::Event::LostFocus:
                mPaused = true;
                break;
		}

	}
}

void Game::update(sf::Time deltaTime)
{
    mWorld.update(deltaTime);

	sf::Vector2f movement(0.0f, 0.0f);
	
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed;
		
	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}



