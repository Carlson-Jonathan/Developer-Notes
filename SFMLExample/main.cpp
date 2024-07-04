/**************************************************************************************************
 * This is an example of how to use the SFML framework for making C++ games. You must have the SFML
 * framework installed. Get it from: https://www.sfml-dev.org/
 * Note that not all of this code is used in the example, but there is some extra just for an 
 * example of how to use them or get them to work (buttons, network, etc).
 * To compile this example code, use:
 * g++ main.o -o executable.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
 **************************************************************************************************/
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
using namespace std;

int main() {

	short screenWidth = 1400;
	short screenHeight = 900;	

   sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Examples");
   sf::Music music;
	sf::Text text;
	sf::Font font; 
	sf::Texture dragonTex;
	sf::Clock clock;
	window.setFramerateLimit(60);

	// Used for animations
	short dragonPositionX = 0.f,
	 	   dragonPositionY = 0.f;

	// Images
	if (!dragonTex.loadFromFile("dragon.png")) cout << "unable to load image" << endl;
	sf::IntRect dragonSourceSprite(0, 161, 191, 161);
 	sf::Sprite sprite(dragonTex, dragonSourceSprite);

	// Shapes
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    // Fonts and text
	if (!font.loadFromFile("Fonts/Sweet Maple.otf")) cout << "Font not found" <<	endl; 
	text.setFont(font); 
	text.setString("SFML Examples by Jonathan Carlson");
	text.setCharacterSize(48); 
	text.setFillColor(sf::Color::Yellow);
	// text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	// Music
	if (!music.openFromFile("song.ogg"))
        return -1; // error
	music.play();

	text.setPosition(sf::Vector2f(screenWidth / 4, 0));
	//center text
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
	               textRect.top  + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(screenWidth / 2, 100));

	shape.setPosition(sf::Vector2f(screenWidth / 2 - 100.f, screenHeight / 2 - 100.f));
	float velocityX = 0, velocityY = 0;
   
   // Master window loop. 
   while (window.isOpen()) {

   	// Event Handler (button detectors)
	   sf::Event event;
      while (window.pollEvent(event)) {

   	   if (event.type == sf::Event::Closed)
            window.close();

      	// Catches window resize events. Adjusts resolution to match window resize.
         if (event.type == sf::Event::Resized) {
          	// update the view to the new size of the window
          	screenWidth  = event.size.width;
          	screenHeight = event.size.height;
           	sf::FloatRect visibleArea(0, 0, screenWidth, screenHeight);
           	window.setView(sf::View(visibleArea));
         }

         shape.setPosition(sf::Vector2f(screenWidth / 2 - 100.f, screenHeight / 2 - 100.f));
      }

      window.clear(sf::Color(102, 255, 255));

      /********************************************************************************************
      * All stuff between these lines gets drawn to the screen.
      *********************************************************************************************/      

	sprite.setPosition(sf::Vector2f(dragonPositionX, dragonPositionY));

      window.draw(shape);
		window.draw(text);
		window.draw(sprite);

		if(clock.getElapsedTime().asSeconds() > 0.15f) { 	// Determines animation speed - changes image once every 0.2 seconds.
			
			if(dragonSourceSprite.left == 382) 					// Numbers represent pixel position on the sprite sheet.
				dragonSourceSprite.left = 0;
			else
				dragonSourceSprite.left += 191;					// Dragon sprite sheet images are 191 pixels apart.

			sprite.setTextureRect(dragonSourceSprite);
			clock.restart();

		}

		if(dragonPositionX >= screenWidth - 191) {
			dragonSourceSprite.top = 483;
			velocityX = -4;
		}

		if(dragonPositionX <= 0) {
			dragonSourceSprite.top = 161;
			velocityX = 4;
		}

		if(dragonPositionY >= screenHeight - 161) {
			velocityY = -2;
			dragonSourceSprite.top = 0;
		}

		if(dragonPositionY <= 0) {
			velocityY = 2;
			dragonSourceSprite.top = 322;
		}

		dragonPositionX += velocityX;
		dragonPositionY += velocityY;

      /********************************************************************************************
      * End of Drawing loop.
      *********************************************************************************************/
      window.display();
   }

    return 0;
}
