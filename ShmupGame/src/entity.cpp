#include "entity.h"

Entity::Entity()
{
	//default constructor
}


Entity::Entity(const float* size, const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds) : weapon(WEAPON_TYPE::REGULAR)
{
	weapon = *startWeapon;
	shape.setPointCount(*pointCount);
	shape.setRadius(*size);

	const float startPosX = curWindowBounds->width / 2 - shape.getRadius();
	const float startPosY = curWindowBounds->height - (shape.getRadius() * 2);

	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(sf::Vector2f(startPosX, startPosY));
}

sf::CircleShape* Entity::GetEntity()
{
	return &shape;
}

Weapon* Entity::GetWeapon()
{
	return &weapon;
}

void Entity::SetWeapon(const Weapon* newWeapon)
{
	weapon = *newWeapon;
}

Bullet* Entity::Shoot()
{
	Bullet* bullet = weapon.Shoot(&shape.getPosition(), shape.getRadius());
	return bullet;
}