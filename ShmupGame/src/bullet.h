#pragma once
#include "main.h"

class Bullet
{
private:
	sf::RectangleShape bulletShape;
	const float BULLET_HEIGHT = 25.f;
	const float BULLET_WIDTH = 7.f;
	float damage;
	float speed;
	bool isSpread;

public:
	Bullet();
	Bullet(const WEAPON_TYPE weaponType, const sf::Vector2f* spaceshipPos);

	void SetDamage(const float newDamage);
	void SetSpeed(const float newSpeed);
	void SetSpread(const bool newIsSpread);

	sf::RectangleShape* GetBulletShape();
};