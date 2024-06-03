#include "weapon.h"

Weapon::Weapon(const WEAPON_TYPE newWeaponType)
{
	weaponType = newWeaponType;
}

Bullet* Weapon::Shoot(const sf::Vector2f* spaceshipPos)
{
	Bullet newBullet(weaponType, spaceshipPos);
	return &newBullet;
}

WEAPON_TYPE* Weapon::GetWeaponType()
{
	return &weaponType;
}

void Weapon::SetWeaponType(const WEAPON_TYPE newWeaponType)
{
	weaponType = newWeaponType;
	std::cout << "DEBUG: Set Weapon Type: " << weaponType << std::endl;

}