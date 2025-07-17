#include "Button.h"

Button::Button(sf::Vector2f size, sf::Font& font):shape(size)
{
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
}

Button::Button(sf::Vector2f size, sf::String string, sf::Font& font):shape(size)
{
    text.setFont(font);
    text.setCharacterSize(18);
    text.setString(string);
    text.setFillColor(sf::Color::Black);
}

void Button::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);
    text.setPosition(sf::Vector2f(position.x + 15, position.y + 6));
}

void Button::setText(sf::String string)
{
    text.setString(string);
}

void Button::on()
{
    shape.setFillColor(sf::Color::Green);
    text.setFillColor(sf::Color::White);
}

void Button::off()
{
    shape.setFillColor(sf::Color::White);
    text.setFillColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(text);
}

sf::Vector2f Button::getPosition()
{
    return shape.getPosition();
}

sf::String Button::getText()
{
    return text.getString();
}
