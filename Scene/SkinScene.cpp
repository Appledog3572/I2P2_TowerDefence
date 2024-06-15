#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>

#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "SkinScene.hpp"
#include "Engine/AudioHelper.hpp"

void SkinScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&SkinScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
}

void SkinScene::Terminate() {
    IScene::Terminate();
//    AudioHelper::StopSample(bgmInstance);
//    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void SkinScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("shop");
}