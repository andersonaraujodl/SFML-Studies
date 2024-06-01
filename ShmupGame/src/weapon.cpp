#include "weapon.h"
#include "bullet.h"

BULLET_TYPE bulletType;

void Shoot(const BULLET_TYPE* type, Bullet* bullet)
{
	bulletType = *type;

	switch (bulletType)
	{
	case BULLET_TYPE::REGULAR:
		bullet->SetDamage(1);
		bullet->SetSpeed(5);
		bullet->SetSpread(false);
		break;
	default:
		bullet->SetDamage(1);
		bullet->SetSpeed(5);
		bullet->SetSpread(false);
		break;
	}
}