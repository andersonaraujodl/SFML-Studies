#pragma once
#include "main.h"
#include "bullet.h"
#include "weapon.h"

class Entity
{
private:
	sf::CircleShape shape;
	Weapon weapon;

public:
	Entity();
	Entity(const float* size, const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds);

	sf::CircleShape* GetEntity();

	Weapon* GetWeapon();
	void SetWeapon(const Weapon* newWeapon);

	Bullet* Shoot();
};