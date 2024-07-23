#include "weapon.h"

Weapon::Weapon()
{
	//default constructor;
}

Weapon::Weapon(const WEAPON_TYPE newWeaponType)
{
	weaponType = newWeaponType;

	switch (weaponType)
	{
	case REGULAR:
		bulletHeight = 25.f;
		bulletWidth = 7.f;
		break;
	case DOUBLE:
		break;
	case TRIPLE:
		break;
	case LASER:
		break;
	case SPREAD:
		break;
	case BULLET_COUNT:
		break;
	default:
		bulletHeight = 25.f;
		bulletWidth = 7.f;
		break;
	}
}

Bullet* Weapon::Shoot(const sf::Vector2f* spaceshipPos, const float spaceshipRadius)
{
	sf::Vector2f bulletPos = sf::Vector2f(spaceshipPos->x + spaceshipRadius, spaceshipPos->y);
	sf::Vector2f bulletSize = sf::Vector2f(bulletWidth, bulletHeight);
	Bullet* newBullet = new Bullet(weaponType, &bulletPos, &bulletSize);

	return newBullet;
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