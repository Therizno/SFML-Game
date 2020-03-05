#include <SFML/Graphics.hpp>

class Game
{
	public:
		Game();
		void run();
		
	private:
		void processEvents();
		void update(sf::Time deltaTime);
		void render();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		
	private:
		bool mIsMovingUp;
		bool mIsMovingLeft;
		bool mIsMovingRight;
		bool mIsMovingDown; 
		float speed;
		const sf::Time TIME_PER_FRAME = sf::seconds(1.0f/60.0f);
		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;
};
