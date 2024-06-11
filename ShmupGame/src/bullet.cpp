#include "bullet.h"
#include "globals.h"

//TODO Create Entity to enherit Bullet from this

Bullet::Bullet()
{
	damage = 0;
	speed = 0;
	isSpread = 0;
}

Bullet::Bullet(const WEAPON_TYPE weaponType, const sf::Vector2f* spaceshipPos, const sf::Vector2f* bulletSize)
{
	bulletShape.setPosition(*spaceshipPos);
	bulletShape.setSize(*bulletSize);
	bulletShape.setFillColor(sf::Color::Red);

	switch (weaponType)
	{
	case WEAPON_TYPE::REGULAR:
		damage = 1;
		speed = -5;
		isSpread = false;
		break;
	default:
		damage = 1;
		speed = -5;
		isSpread = false;
		break;
	}

	Move();
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

void Bullet::Move()
{
	bulletShape.move(0, speed * GameGlobals::GetDeltaTime()->asSeconds() * 20);

}