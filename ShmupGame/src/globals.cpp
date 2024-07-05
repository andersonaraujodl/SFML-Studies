#include "globals.h"

sf::Time GameGlobals::g_deltaTime;
sf::FloatRect GameGlobals::g_gameWindowBounds;
std::vector<Bullet*> GameGlobals::g_bullets;

void GameGlobals::SpawnEnemy(const float* time1, const float* time2)
{
	std::cout << "Spawn enemy: " << *time1 << " --- " << *time2 << std::endl;
}

const float* GameGlobals::GetMinSpawnTime()
{
	return &base_spawn_time_min;
}

const float* GameGlobals::GetMaxSpawnTime()
{
	return &base_spawn_time_max;
}