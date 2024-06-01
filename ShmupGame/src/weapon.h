#pragma once

enum BULLET_TYPE
{
	REGULAR,
	DOUBLE,
	TRIPLE,
	LASER,
	SPREAD,
	BULLET_COUNT
};

class Weapon
{
private:
	BULLET_TYPE bulletType;

public:
	void Shoot(BULLET_TYPE* bulletType);

};