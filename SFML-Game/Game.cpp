
#include "Game.h"

#include "ResourceHolder.cpp"

//temporary fix variable 
sf::Texture textr;

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mTexture(), mPlayer()
{
	speed = 75;
	
	ResourceHolder<sf::Texture, Textures::ID> textures;
	
	textures.load(Textures::Airplane, "plane.png");
	
	textr = textures.get(Textures::Airplane);
    
	mPlayer.setTexture(textr);
	mPlayer.setPosition(100.0f, 100.0f);
}

void Game :: run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (mWindow.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			processEvents();
			update(TIME_PER_FRAME);
		
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}
		
		render();
	}
}

void Game :: processEvents()
{
	sf::Event event;
	
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}

	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	if(mIsMovingUp)
		movement.y -= speed;
	if(mIsMovingLeft)
		movement.x -= speed;
	if(mIsMovingRight)
		movement.x += speed;
	if(mIsMovingDown)
		movement.y += speed;
		
	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (key) 
	{ 
		case sf::Keyboard::W:
			mIsMovingUp = isPressed;
			break;
		case sf::Keyboard::A:
			mIsMovingLeft = isPressed;
			break;
		case sf::Keyboard::D:
			mIsMovingRight = isPressed;
			break;
		case sf::Keyboard::S:
			mIsMovingDown = isPressed;
			break;
	}
}

