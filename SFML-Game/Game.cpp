
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
    CommandQueue& commands = mWorld.getCommandQueue();
    
	sf::Event event;
	
	while (mWindow.pollEvent(event))
	{
        mPlayer.handleEvent(event, commands);
 
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

        mPlayer.handleRealtimeInput(commands);
	}
}

void Game::update(sf::Time deltaTime)
{
    mWorld.update(deltaTime);
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}



