#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>

#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Fireskin.hpp"
#include "Engine/AudioHelper.hpp"
extern int Fireskinchoose;

void Fireskin::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("shop/background_dark.jpg", 0, 0, w, h, 0,0));
    Engine::ImageButton *btn, *btn2, *btn3, *btn4, *btn5;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&Fireskin::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));

    AddNewObject(new Engine::Image("play/turret-1.png", halfW/3-70, 100, 500, 500, 0,0));
    AddNewObject(new Engine::Image("play/turret-7.png", halfW/3+630, 100, 500, 500, 0,0));

    btn2 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 200, 400,500, 500);
    btn2->SetOnClickCallback(std::bind(&Fireskin::Select1OnClick, this));
    AddNewControlObject(btn2);
    left = new Engine::Label("Select", "pirulen.ttf", 36, 350, 630);
    AddNewObject(left);

    btn3 = new Engine::ImageButton("skin/woodbutton.png", "skin/woodbutton2.png", 900, 400,500, 500);
    btn3->SetOnClickCallback(std::bind(&Fireskin::Select2OnClick, this));
    AddNewControlObject(btn3);
    right = new Engine::Label("Select", "pirulen.ttf", 36, 1050, 630);
    AddNewObject(right);

}

void Fireskin::Terminate() {
    IScene::Terminate();
//    AudioHelper::StopSample(bgmInstance);
//    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void Fireskin::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("skin");
}

void Fireskin::Select1OnClick() {
    MachineGunskinchoose = 1;
    RemoveObject(right->GetObjectIterator());
    right = new Engine::Label("Select", "pirulen.ttf", 36, 1050, 630);
    AddNewObject(right);
    RemoveObject(left->GetObjectIterator());
    left = new Engine::Label("Selected", "pirulen.ttf", 36, 310, 630);
    AddNewObject(left);
}

void Fireskin::Select2OnClick() {
    MachineGunskinchoose = 2;
    RemoveObject(left->GetObjectIterator());
    left = new Engine::Label("Select", "pirulen.ttf", 36, 350, 630);
    AddNewObject(left);
    RemoveObject(right->GetObjectIterator());
    right = new Engine::Label("Selected", "pirulen.ttf", 36, 1010, 630);
    AddNewObject(right);
}