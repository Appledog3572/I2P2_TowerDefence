//
// Created by suzixun on 2024/6/15.
//
#include <allegro5/color.h>

#include "Engine/GameEngine.hpp"
#include "Engine/IScene.hpp"
#include "Scene/PlayScene.hpp"
#include "PropsButton.h"

PlayScene* PropsButton::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
PropsButton::PropsButton(std::string img, std::string imgIn, Engine::Sprite Props, float x, float y) :
        ImageButton(img, imgIn, x, y), Props(Props) {
}
void PropsButton::Update(float deltaTime) {
    ImageButton::Update(deltaTime);
    /*
    if (getPlayScene()->GetMoney() >= money) {
        Enabled = true;
        Base.Tint = Turret.Tint = al_map_rgba(255, 255, 255, 255);
    } else {
        Enabled = false;
        Base.Tint = Turret.Tint = al_map_rgba(0, 0, 0, 160);
    }
     */
}
void PropsButton::Draw() const {
    ImageButton::Draw();
    Props.Draw();
}