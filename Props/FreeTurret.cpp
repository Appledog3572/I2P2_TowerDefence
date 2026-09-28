#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FreezerBullet.hpp"
#include "Engine/Group.hpp"
#include "FreeTurret.h"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int FreeTurret::Price = 100;
FreeTurret::FreeTurret(float x, float y) :
        Turret("play/tower-base.png", "play/turret-4.png", x, y, 300, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void FreeTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FreezerBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("freeze.wav");
}
