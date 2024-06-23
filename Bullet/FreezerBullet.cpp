#include <allegro5/base.h>
#include <random>
#include <string>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "FreezerBullet.hpp"
#include "Engine/Group.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
int Freezer_level = 1;
class Turret;

FreezerBullet::FreezerBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
        Bullet("play/bullet-7-freeze.png", 400, 1.5+Freezer_level*0.1, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void FreezerBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
    enemy->AddSpeed(0.85-0.05*Freezer_level, 1);
}
void FreezerBullet::level_up() {
    Freezer_level++;
}