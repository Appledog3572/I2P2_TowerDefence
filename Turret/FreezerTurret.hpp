//
// Created by st103 on 2024/5/26.
//

#ifndef FREEZERTURRET_HPP
#define FREEZERTURRET_HPP
#include "Turret.hpp"
extern int Freezer_level;
class FreezerTurret: public Turret {
public:
    //int level = 1;
    //int upgradeCost = 100;
    //bool canUpgrade = true;
    static const int Price;
    FreezerTurret(float x, float y);
    void CreateBullet() override;
    void Upgrade() override;
};
void Freezer_Upgrade();
#endif //FREEZERTURRET_HPP
