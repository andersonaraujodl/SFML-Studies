#pragma once
#include "main.h"
#include "bullet.h"
#include "weapon.h"

class Spaceship
{
private:
	sf::CircleShape spaceship;
	Weapon weapon;


public:
	Spaceship(const float* size, const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds);

	sf::CircleShape* GetSpaceship();

	Weapon* GetWeapon();
	void SetWeapon(const Weapon* newWeapon);

	Bullet* Shoot();
};