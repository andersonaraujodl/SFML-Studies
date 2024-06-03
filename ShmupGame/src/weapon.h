#pragma once
#include "bullet.h"
#include "main.h"

class Weapon
{
private:
	WEAPON_TYPE weaponType;

public:
	Weapon(const WEAPON_TYPE weaponType);
	Bullet* Shoot(const sf::Vector2f* spaceshipPos);
	WEAPON_TYPE * GetWeaponType();
	void SetWeaponType(const WEAPON_TYPE newWeaponType);

};