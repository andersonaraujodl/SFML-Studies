#pragma once
#include "main.h"

class Spaceship
{
private:
	sf::CircleShape spaceship;


public:
	Spaceship(const float* size, const size_t* pointCount, const sf::FloatRect* windowBounds);

	sf::CircleShape* GetSpaceship();

	void Shoot();
};