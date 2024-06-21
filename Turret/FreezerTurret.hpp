#ifndef FREEZERTURRET_HPP
#define FREEZERTURRET_HPP
#include "Turret.hpp"

class FreezerTurret: public Turret {
public:
    static const int Price;
    FreezerTurret(float x, float y);
    void CreateBullet() override;
};
#endif //FREEZERTURRET_HPP
