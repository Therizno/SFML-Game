#include <SFML/Graphics.hpp>

#include "World.hpp"

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
		float speed;
		const sf::Time TIME_PER_FRAME = sf::seconds(1.0f/60.0f);
		sf::RenderWindow mWindow;
		sf::Sprite mPlayer;
        World mWorld;
};
