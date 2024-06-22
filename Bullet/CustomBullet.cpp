#include <allegro5/base.h>
#include <random>
#include <string>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "CustomBullet.hpp"
#include "Engine/Group.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

class Turret;

CustomBullet::CustomBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, customTurret Data, Turret* parent) :
        Bullet("play/bullet-1.png", Data.speed, Data.damage, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void CustomBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

