#ifndef CUSTOMBULLET_HPP
#define CUSTOMBULLET_HPP
#include "Bullet.hpp"
#include "Engine/Player.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class CustomBullet : public Bullet {
public:
    explicit CustomBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, customTurret Data, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif //CUSTOMBULLET_HPP
