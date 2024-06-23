#ifndef MISSILETURRET_HPP
#define MISSILETURRET_HPP
#include "Turret.hpp"
extern int Missile_level;
class MissileTurret: public Turret {
public:
	static const int Price;
    MissileTurret(float x, float y);
    void CreateBullet() override;
};
#endif // MISSILETURRET_HPP
