#ifndef FREETURRET_HPP
#define FREETURRET_HPP
#include "Turret/Turret.hpp"

class FreeTurret: public Turret {
public:
    static const int Price;
    FreeTurret(float x, float y);
    void CreateBullet() override;
};
#endif //FREETURRET_HPP