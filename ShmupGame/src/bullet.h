#pragma once
#include "main.h"

class Bullet
{
private:
	sf::RectangleShape bulletShape;
	float damage;
	float speed;
	bool isSpread;
	sf::Vector2f bulletSize;
	sf::FloatRect windowBounds;

public:
	Bullet();
	Bullet(const WEAPON_TYPE weaponType, const sf::Vector2f* spaceshipPos, const sf::Vector2f* setBulletSize);

	~Bullet();

	void SetDamage(const float newDamage);
	void SetSpeed(const float newSpeed);
	void SetSpread(const bool newIsSpread);

	sf::RectangleShape* GetBulletShape();

	bool Move();
};