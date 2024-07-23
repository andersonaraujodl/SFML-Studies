#pragma once
#include "main.h"
#include "bullet.h"
#include "enemy.h"

#include <cmath>

class GameGlobals
{
private:
	const float base_spawn_time_min = 3.0f; //default 3
	const float base_spawn_time_max = 11.0f; //default 10

	static sf::Time g_deltaTime;
	static sf::FloatRect g_gameWindowBounds;
	static std::vector<Bullet*> g_bullets;
	static std::vector<Enemy*> g_enemies;

public:
	static sf::Time* GetDeltaTime()
	{
		return &g_deltaTime;
	}

	static void SetDeltaTime(const sf::Time& deltaTime)
	{
		g_deltaTime = deltaTime;
	}

	static sf::FloatRect* GetGameWindowBounds()
	{
		return &g_gameWindowBounds;
	}

	static void SetGameWindowBounds(const sf::FloatRect* bounds)
	{
		g_gameWindowBounds = *bounds;
	}

	static std::vector<Bullet*>* GetBullets()
	{
		return &g_bullets;
	}

	static void SetBullets(const std::vector<Bullet*>* bullets)
	{
		g_bullets = *bullets;
	}

	static std::vector<Enemy*>* GetEnemies()
	{
		return &g_enemies;
	}

	static void SetEnemies(const std::vector<Enemy*>* enemies)
	{
		g_enemies = *enemies;
	}

	void SpawnEnemy();

	const float* GetMinSpawnTime();

	const float* GetMaxSpawnTime();
};