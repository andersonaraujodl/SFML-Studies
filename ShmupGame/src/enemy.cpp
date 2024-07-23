#include "enemy.h"
#include "weapon.h"
#include "globals.h"

Enemy::Enemy(const size_t* pointCount, const Weapon* startWeapon, const sf::FloatRect* curWindowBounds) : weapon(WEAPON_TYPE::REGULAR)
{
	weapon = *startWeapon;
	enemyShape.setSize(sf::Vector2f(enemySize, enemySize));

	enemyShape.setPosition(GenerateRandomVec2f());
	enemyShape.setSize(sf::Vector2f(enemySize, enemySize));
	enemyShape.setFillColor(sf::Color::Red);
}

sf::RectangleShape* Enemy::GetEnemyShape()
{
	return &enemyShape;
}

bool Enemy::Move()
{
	//TODO Check Collision
	enemyShape.move(0, speed * GameGlobals::GetDeltaTime()->asSeconds());
	
	return enemyShape.getPosition().y > GameGlobals::GetGameWindowBounds()->height + enemySize;
}

sf::Vector2f Enemy::GenerateRandomVec2f()
{
	sf::FloatRect* windowsBounds = GameGlobals::GetGameWindowBounds();

	float randomXFloat = (float)(rand());
	float randX = std::fmod(randomXFloat, (windowsBounds->width - (enemySize * 3))) + (enemySize);
	std::cout << "Float: " << randomXFloat << "Rand X: " << randX << std::endl;
	return sf::Vector2f(randX, -enemySize);
}