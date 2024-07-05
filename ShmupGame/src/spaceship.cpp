#include "spaceship.h"
#include "weapon.h"

//Spaceship::Spaceship(const float* size, const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds) : weapon(WEAPON_TYPE::REGULAR)
//{
//	weapon = *startWeapon;
//	spaceship.setPointCount(*pointCount);
//	spaceship.setRadius(*size);
//
//	const float startPosX = curWindowBounds->width / 2 - spaceship.getRadius();
//	const float startPosY = curWindowBounds->height - (spaceship.getRadius() * 2);
//
//	spaceship.setFillColor(sf::Color::Blue);
//	spaceship.setPosition(sf::Vector2f(startPosX, startPosY));
//}

//sf::CircleShape* Entity::GetEntity()
//{
//	return &shape;
//}
//
//Weapon* Entity::GetWeapon()
//{
//	return &weapon;
//}
//
//void Entity::SetWeapon(const Weapon* newWeapon)
//{
//	weapon = *newWeapon;
//}
//
//Bullet* Entity::Shoot()
//{
//	Bullet* bullet = weapon.Shoot(&shape.getPosition(), shape.getRadius());
//	return bullet;
//}