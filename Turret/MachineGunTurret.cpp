#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FireBullet.hpp"
#include "Engine/Group.hpp"
#include "MachineGunTurret.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
int MachineGunskinchoose = 1;
const int MachineGunTurret::Price = 50;
MachineGunTurret::MachineGunTurret(float x, float y) :
	Turret("play/tower-base.png", Fire_level == 5?"play/turret-9.png":(MachineGunskinchoose == 1?"play/turret-1.png":"play/turret-7.png"), x, y, 200+20*Fire_level, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
