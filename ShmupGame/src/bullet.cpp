#include "bullet.h"

Bullet::Bullet()
{
	damage = 0;
	speed = 0;
	isSpread = 0;
}

Bullet::Bullet(const WEAPON_TYPE weaponType, const sf::Vector2f* spaceshipPos)
{
	bulletShape.setPosition(*spaceshipPos);
	bulletShape.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
	bulletShape.setFillColor(sf::Color::Red);

	switch (weaponType)
	{
	case WEAPON_TYPE::REGULAR:
		damage = 1;
		speed = 5;
		isSpread = false;
		break;
	default:
		damage = 1;
		speed = 5;
		isSpread = false;
		break;
	}
}

void Bullet::SetDamage(const float newDamage)
{
	damage = newDamage;
}

void Bullet::SetSpeed(const float newSpeed)
{
	speed = newSpeed;
}

void Bullet::SetSpread(const bool newIsSpread)
{
	isSpread = newIsSpread;
}

sf::RectangleShape* Bullet::GetBulletShape()
{
	return &bulletShape;
}