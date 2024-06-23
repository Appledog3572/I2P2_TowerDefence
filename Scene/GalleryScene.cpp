#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>

#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/Player.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "GalleryScene.hpp"

void GalleryScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&GalleryScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
    //title
    AddNewObject(new Engine::Label("Gallery", "pirulen.ttf", 52, halfW, 50, 200, 200, 200, 255, 0.5, 0.5));
    //turret button
    AddNewObject(new Engine::Image("win/box.png", halfW - 250, halfH * 3 / 4, 300, 300, 0.5, 0.5));
    AddNewObject(new Engine::Image("play/turret-1.png", halfW - 250, halfH * 3 / 4, 200, 200, 0.5, 0.5));
    btn = new Engine::ImageButton("play/dirt.png", "play/floor.png", halfW - 350, h * 5 / 8, 200, 100);
    btn->SetOnClickCallback(std::bind(&GalleryScene::TurretOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Turret", "pirulen.ttf", 35, halfW - 250, h * 5 / 8 + 50, 0, 0, 0, 255, 0.5, 0.5));
    //enemy button
    AddNewObject(new Engine::Image("win/box.png", halfW + 250, halfH * 3 / 4, 300, 300, 0.5, 0.5));
    AddNewObject(new Engine::Image("play/enemy-1.png", halfW + 250, halfH * 3 / 4, 400, 400, 0.5, 0.5));
    btn = new Engine::ImageButton("play/dirt.png", "play/floor.png", halfW + 150, h * 5 / 8, 200, 100);
    btn->SetOnClickCallback(std::bind(&GalleryScene::EnemyOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Enemy", "pirulen.ttf", 35, halfW + 250, h * 5 / 8 + 50, 0, 0, 0, 255, 0.5, 0.5));
    //BGM
    bgmInstance = AudioHelper::PlaySample("happy.ogg", true, AudioHelper::BGMVolume);
}

void GalleryScene::Terminate() {
    IScene::Terminate();
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void GalleryScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void GalleryScene::TurretOnClick(){
    Engine::GameEngine::GetInstance().ChangeScene("gallery-turret");
}

void GalleryScene::EnemyOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("gallery-enemy");
}