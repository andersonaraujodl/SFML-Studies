#include "bullet.h"

float damage;
float speed;
bool isSpread;

Bullet::Bullet()
{
	damage = 0;
	speed = 0;
	isSpread = 0;
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