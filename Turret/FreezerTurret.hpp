//
// Created by st103 on 2024/5/26.
//

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
