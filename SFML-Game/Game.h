#include <SFML/Graphics.hpp>

#include "World.hpp"

#include "Player.hpp"


class Game
{
	public:
		Game();
		void run();
		
	private:
		void processEvents();
		void update(sf::Time deltaTime);
		void render();
		
	private:
        bool mPaused;
		float speed;
		const sf::Time TIME_PER_FRAME = sf::seconds(1.0f/60.0f);
		sf::RenderWindow mWindow;
		Player mPlayer;
        World mWorld;
};
