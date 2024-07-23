#pragma once
#include "bullet.h"
#include "main.h"

class Weapon
{
private:
	WEAPON_TYPE weaponType;
	float bulletHeight;
	float bulletWidth;

public:
	Weapon();
	Weapon(const WEAPON_TYPE weaponType);
	Bullet* Shoot(const sf::Vector2f* spaceshipPos, const float spaceshipRadius);
	WEAPON_TYPE * GetWeaponType();
	void SetWeaponType(const WEAPON_TYPE newWeaponType);

};