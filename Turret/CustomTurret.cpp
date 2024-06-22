#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Bullet/CustomBullet.hpp"
#include "Engine/Group.hpp"
#include "CustomTurret.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

CustomTurret::CustomTurret(float x, float y, customTurret Data) :
        Turret("play/tower-base.png", "play/custom-" + std::to_string(Data.appearance) + ".png", x, y, Data.radius, Data.cost, Data.fireRate) {
    // Move center downward, since we the turret head is slightly biased upward.
    this->Data = Data;
    Anchor.y += 8.0f / GetBitmapHeight();
}
void CustomTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new CustomBullet(Position + normalized * 36, diff, rotation, Data, this));
    AudioHelper::PlayAudio("gun.wav");
}