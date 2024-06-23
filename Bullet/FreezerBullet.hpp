#ifndef FREEZERBULLET_HPP
#define FREEZERBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine
class FreezerBullet : public Bullet {
public:
    //int Freezer_level = 1;
    explicit FreezerBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void level_up();
};
#endif //FREEZERBULLET_HPP
