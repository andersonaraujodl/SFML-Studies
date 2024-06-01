#include "spaceship.h"
#include "bullet.h"

sf::CircleShape spaceship;

Spaceship::Spaceship(const float* size, const size_t* pointCount, const sf::FloatRect* windowBounds)
{
	spaceship.setPointCount(*pointCount);
	spaceship.setRadius(*size);

	const float startPosX = windowBounds->width / 2 - spaceship.getRadius();
	const float startPosY = windowBounds->height - (spaceship.getRadius() * 2);

	spaceship.setFillColor(sf::Color::Blue);
	spaceship.setPosition(sf::Vector2f(startPosX, startPosY));
}

sf::CircleShape* Spaceship::GetSpaceship()
{
	return &spaceship;
}

void Shoot()
{
	//Bullet()
}