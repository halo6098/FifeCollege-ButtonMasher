// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


// entry point for the program
int main()
{
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();

	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	// Game Loop
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			}
		}

		// TODO: Update game state

		// TODO: Draw graphics
		gameWindow.clear(sf::Color::Magenta);

		// Draw  E V E R Y   T H I N G
		gameWindow.draw(buttonSprite);

		gameWindow.display();
	}

	// exit point for the program
	return 0;
}