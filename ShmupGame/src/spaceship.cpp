#include "spaceship.h"
#include "weapon.h"

sf::CircleShape spaceship;

Spaceship::Spaceship(const float* size, const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* windowBounds) : weapon(WEAPON_TYPE::REGULAR)
{
	weapon = *startWeapon;
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

Weapon* Spaceship::GetWeapon()
{
	return &weapon;
}

void Spaceship::SetWeapon(const Weapon* newWeapon)
{
	weapon = *newWeapon;
	std::cout << "DEBUG: Set Weapon: " << *weapon.GetWeaponType() << std::endl;

}

Bullet* Spaceship::Shoot()
{
	std::cout << "DEBUG: Shoot" << std::endl;
	Bullet* testBullet = weapon.Shoot(&spaceship.getPosition());
	return testBullet;
}