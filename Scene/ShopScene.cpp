#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>

#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "ShopScene.hpp"
#include "Engine/AudioHelper.hpp"

void ShopScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    Engine::ImageButton *btn;
    //background
    AddNewObject(new Engine::Image("shop/background_dark.jpg", 0, 0, w, h, 0,0));
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&ShopScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
    //title
    AddNewObject(new Engine::Image("shop/clerk2.png", w * 13 / 16, halfH / 5 - 10, 100, 100, 0.5, 0.5));
    AddNewObject(new Engine::Image("shop/plate2.png", w * 13 / 16, halfH / 4, 350, 300, 0.5, 0.5));
    AddNewObject(new Engine::Label("Shop", "pirulen.ttf", 52, w * 13 / 16 + 10, halfH / 4 + 30, 200, 200, 200, 255, 0.5, 0.5));
    //clerk
    AddNewObject(new Engine::Image("shop/Yang1.png", w * 14 / 16, halfH + 20, halfW * 3 / 8, 0, 0.5, 0.5));
//    AddNewObject(new Engine::Image("shop/Yang2.png", w * 13 / 16, halfH, halfW * 4 / 8, halfH, 0.5, 0.5));
    //table
    AddNewObject(new Engine::Image("shop/table.png", w * 5 / 8, h * 5 / 8, halfW * 3 / 4, halfH * 3 / 4 + 75, 0, 0));
    //shelves
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j){
            AddNewObject(new Engine::Image("shop/shelve.png", halfW / 4 + j * (w * 3 / 16), halfH + i * (h * 3 / 8), halfW / 4, halfH / 9, 0.5, 0));
        }
    }
    //item button
    for(int i=0;i<3;++i){
        AddNewObject(new Engine::Image("shop/item" + std::to_string(i + 1) + ".png", halfW / 4 + i * (w * 3 / 16), halfH * 3 / 4, h / 4, h / 4, 0.5, 0.5));
//        btn = new Engine::ImageButton("shop/item2.png", "shop/empty.png", halfW / 4 + i * (w * 3 / 16), halfH * 3 / 4,h / 4, h / 4, 0.5, 0.5);
//        btn->SetOnClickCallback(std::bind(&ShopScene::ItemOnClick, this, i));
//        AddNewControlObject(btn);
    }
    //custom turret button
    for(int i=0;i<3;++i){
        AddNewObject(new Engine::Image("shop/item" + std::to_string(i + 1) + ".png", halfW / 4 + i * (w * 3 / 16), h * 3 / 4, h / 4, h / 4, 0.5, 0.5));
    }
    bgmInstance = AudioHelper::PlaySample("Sugar Cubes(shop).ogg", true, AudioHelper::BGMVolume);
}

void ShopScene::Terminate() {
    IScene::Terminate();
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void ShopScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void ShopScene::ItemOnClick(int number){
    std::cout<<"test\n";
}

void ShopScene::TurretOnClick(int number){

}