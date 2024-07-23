#pragma once

#include "main.h"
#include "bullet.h"
#include "weapon.h"
#include "entity.h"

class Enemy : public Entity
{
private:
	sf::RectangleShape enemyShape;
	float damage;
	const float speed = 100;
	Weapon weapon;
	const float enemySize = 40.f;

public:
	Enemy(const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds);

	sf::RectangleShape* GetEnemyShape();
	sf::Vector2f GenerateRandomVec2f();
	bool Move();
};