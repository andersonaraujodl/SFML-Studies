#include "globals.h"

sf::Time GameGlobals::g_deltaTime;
sf::FloatRect GameGlobals::g_gameWindowBounds;
std::vector<Bullet*> GameGlobals::g_bullets;
std::vector<Enemy*> GameGlobals::g_enemies;

void GameGlobals::SpawnEnemy()
{
	const size_t POINT_COUNT = 4;
	Weapon startWeapon(WEAPON_TYPE::REGULAR);
	Enemy* newEnemy = new Enemy(&POINT_COUNT, &startWeapon, &g_gameWindowBounds);
	
	g_enemies.push_back(newEnemy);

	std::cout << "Spawn enemy: " << std::endl;
}

const float* GameGlobals::GetMinSpawnTime()
{
	return &base_spawn_time_min;
}

const float* GameGlobals::GetMaxSpawnTime()
{
	return &base_spawn_time_max;
}