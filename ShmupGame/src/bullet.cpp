#include "bullet.h"
#include "globals.h"

//TODO Create Entity to enherit Bullet from this
Bullet::Bullet()
{
	damage = 0;
	speed = 0;
	isSpread = 0;
}

Bullet::Bullet(const WEAPON_TYPE weaponType, const sf::Vector2f* spaceshipPos, const sf::Vector2f* setBulletSize)
{
	bulletShape.setPosition(*spaceshipPos);
	bulletSize = *setBulletSize;
	bulletShape.setSize(bulletSize);
	bulletShape.setFillColor(sf::Color::Red);
	
	switch (weaponType)
	{
	case WEAPON_TYPE::REGULAR:
		damage = 1;
		speed = -200;
		isSpread = false;
		break;
	default:
		damage = 1;
		speed = -200;
		isSpread = false;
		break;
	}

	Move();
}

Bullet::~Bullet()
{
	std::cout << "DEBUG: DESTROYED" << std::endl;
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

bool Bullet::Move()
{
	//TODO Check Collision
	bulletShape.move(0, speed * GameGlobals::GetDeltaTime()->asSeconds());

	return bulletShape.getPosition().y < - bulletSize.y;
}