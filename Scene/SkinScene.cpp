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
    AddNewObject(new Engine::Image("shop/background_dark.jpg", 0, 0, w, h, 0,0));
    Engine::ImageButton *btn, *btn2, *btn3, *btn4, *btn5;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&SkinScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));

    btn2 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 200, 50,500, 500);
    btn2->SetOnClickCallback(std::bind(&SkinScene::FreezerskinOnClick, this));
    AddNewControlObject(btn2);
    AddNewObject(new Engine::Label("FreezerTurret", "pirulen.ttf", 36, 240, 280));

    btn3 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 800, 50,500, 500);
    btn3->SetOnClickCallback(std::bind(&SkinScene::LaserskinOnClick, this));
    AddNewControlObject(btn3);
    AddNewObject(new Engine::Label("LaserTurret", "pirulen.ttf", 36, 870, 280));

    btn4 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 200, 400,500, 500);
    btn4->SetOnClickCallback(std::bind(&SkinScene::FireskinOnClick, this));
    AddNewControlObject(btn4);
    AddNewObject(new Engine::Label("MachinGunTurret", "pirulen.ttf", 32, 230, 630));

    btn5 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 800, 400,500, 500);
    btn5->SetOnClickCallback(std::bind(&SkinScene::MissileskinOnClick, this));
    AddNewControlObject(btn5);
    AddNewObject(new Engine::Label("MissileTurret", "pirulen.ttf", 36, 850, 630));
}

void SkinScene::Terminate() {
    IScene::Terminate();
//    AudioHelper::StopSample(bgmInstance);
//    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void SkinScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("shop");
}

void SkinScene::FreezerskinOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("Freezerskin");
}

void SkinScene::LaserskinOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("Laserskin");
}

void SkinScene::FireskinOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("Fireskin");
}

void SkinScene::MissileskinOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("Missileskin");
}