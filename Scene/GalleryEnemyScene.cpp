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
#include "GalleryEnemyScene.hpp"

const int EnemyCount = 11;
const int NumberPerRow = 4;

void GalleryEnemyScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&GalleryEnemyScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
    //title
    AddNewObject(new Engine::Label("Enemy", "pirulen.ttf", 52, halfW, 50, 200, 200, 200, 255, 0.5, 0.5));
    //enemy button
    for (int i=0;i<EnemyCount/(NumberPerRow + 1) + 1;++i) {
        for (int j=0;j<(i == EnemyCount/(NumberPerRow + 1) ? ((EnemyCount % NumberPerRow) == 0 ? NumberPerRow : (EnemyCount % NumberPerRow)) : NumberPerRow);++j) {
            btn = new Engine::ImageButton("win/box.png", "win/box-hover.png", 200 + 150 * j, halfH / 2 + 150 * i, 100, 100);
            btn->SetOnClickCallback(std::bind(&GalleryEnemyScene::EnemyOnClick, this, 4 * i + j + 1));
            AddNewControlObject(btn);
            AddNewObject(new Engine::Image("play/gallery-enemy-" + std::to_string(4 * i + j + 1) + ".png", 250 + 150 * j, halfH / 2 + 50 + 150 * i, 0, 0, 0.5, 0.5));
        }
    }
    //initial preview
    AddNewObject(new Engine::Image("win/box.png", w * 13 / 16, halfH * 3 / 4, 400, 400, 0.5, 0.5));
    preview = new Engine::Image("play/gallery-enemy-1.png", w * 13 / 16, halfH * 3 / 4, 300, 300, 0.5, 0.5);
    AddNewObject(preview);
    //BGM
    bgmInstance = AudioHelper::PlaySample("happy.ogg", true, AudioHelper::BGMVolume);
}

void GalleryEnemyScene::Terminate() {
    IScene::Terminate();
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void GalleryEnemyScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("gallery");
}

void GalleryEnemyScene::EnemyOnClick(int number) {
    RemoveObject(preview->GetObjectIterator());
    preview = new Engine::Image("play/gallery-enemy-" + std::to_string(number) + ".png", Engine::GameEngine::GetInstance().GetScreenSize().x * 13 / 16, Engine::GameEngine::GetInstance().GetScreenSize().y / 2 * 3 / 4, 300, 300, 0.5, 0.5);
    AddNewObject(preview);
}