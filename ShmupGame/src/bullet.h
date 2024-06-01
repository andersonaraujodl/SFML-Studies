#pragma once
#include "main.h"

class Bullet
{
private:
	float damage;
	float speed;
	bool isSpread;

public:
	Bullet();

	void SetDamage(const float newDamage);
	void SetSpeed(const float newSpeed);
	void SetSpread(const bool newIsSpread);
};