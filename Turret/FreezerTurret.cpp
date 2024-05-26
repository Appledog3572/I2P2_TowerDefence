#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FreezerBullet.hpp"
#include "Engine/Group.hpp"
#include "FreezerTurret.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int FreezerTurret::Price = 100;
FreezerTurret::FreezerTurret(float x, float y) :
        Turret("play/tower-base.png", "play/turret-4-freeze.png", x, y, 300, Price, 1.5) {
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
