#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape shape;
	sf::Text text;
public:
	Button(sf::Vector2f size, sf::Font& font);
	Button(sf::Vector2f size, sf::String text, sf::Font& font);
	void setPosition(sf::Vector2f position);
	void setText(sf::String text);
	void on();
	void off();
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::String getText();
};

