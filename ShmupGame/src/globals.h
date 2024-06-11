#pragma once
#include "main.h"
#include "bullet.h"

class GameGlobals
{
private:
	static sf::Time g_deltaTime;
	static sf::FloatRect g_gameWindowBounds;
	static std::vector<Bullet*> g_bullets;

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
};