#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FreezerBullet.hpp"
#include "Engine/Group.hpp"
#include "FreezerTurret.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
int Freezerskinchoose = 1;

const int FreezerTurret::Price = 100;
FreezerTurret::FreezerTurret(float x, float y) :
        Turret("play/tower-base.png", Freezer_level == 5?"play/turret-8.png":(Freezerskinchoose == 1?"play/turret-4.png" : "play/turret-7.png"), x, y, 300+20*Freezer_level, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void FreezerTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FreezerBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("freeze.wav");
}
void FreezerTurret::Upgrade() {
    if (canUpgrade) {
        level++;
        // 更新砲塔屬性，例如攻擊力、射速等
        // 提升升級費用
        Freezer_level = level;
        upgradeCost += 50; // 示例
        // 根據需求更新 canUpgrade 狀態，例如達到最高等級後不能再升級
        if (level >= MAX_LEVEL) {
            canUpgrade = false;
        }
    }
}
