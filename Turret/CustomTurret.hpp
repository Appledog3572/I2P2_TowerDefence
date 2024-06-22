#ifndef CUSTOMTURRET_HPP
#define CUSTOMTURRET_HPP
#include "Turret.hpp"
#include "Engine/Player.hpp"

class CustomTurret: public Turret {
public:
    customTurret Data;
    CustomTurret(float x, float y, customTurret Data);
    void CreateBullet() override;
};
#endif //CUSTOMTURRET_HPP
