#include <SFML/Graphics.hpp>


int main() {   
	// Set size of the display window
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML test successful");

	// Set the shape(circle) and size(radius)
  sf::CircleShape shape(200.f);

	// Set the color 
  shape.setFillColor(sf::Color(0, 255, 0));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
			}
    }
    window.draw(shape);
    window.display();
  }
	
	return 0;
}