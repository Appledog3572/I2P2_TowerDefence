#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/Player.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "GalleryTurretScene.hpp"

const int TurretCount = 4;
const int NumberPerRow = 4;
const std::vector<std::vector<std::string>> basicStats={
        {"1", "200", "500", "0.5", "None", "50"},
        {"2", "300", "800", "0.25", "Double", "200"},
        {"4", "1000", "100", "4", "Tracking", "300"},
        {"1.5", "300", "400", "1.5", "Frozen", "100"}
};
const std::vector<std::string> customAbilityNames = {"None", "Double", "Frozen"};

static std::string FtoStr(float value) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    return stream.str();
}

void GalleryTurretScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&GalleryTurretScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
    //title
    AddNewObject(new Engine::Label("Turret", "pirulen.ttf", 52, halfW, 50, 200, 200, 200, 255, 0.5, 0.5));
    //turret button
    AddNewObject(new Engine::Label("Basic", "pirulen.ttf", 40, 200, halfH / 2 + 25, 200, 200, 200, 255, 0, 0));
    for (int i=0;i<TurretCount;++i) {
        btn = new Engine::ImageButton("win/box.png", "win/box-hover.png", 200 + 150 * i, halfH / 2 + 100, 100, 100);
        btn->SetOnClickCallback(std::bind(&GalleryTurretScene::TurretOnClick, this, i + 1, false));
        AddNewControlObject(btn);
        AddNewObject(new Engine::Image("play/tower-base.png", 250 + 150 * i, halfH / 2 + 150, 0, 0, 0.5, 0.5));
        AddNewObject(new Engine::Image("play/turret-" + std::to_string(i + 1) + ".png", 250 + 150 * i, halfH / 2 + 150 - 8, 0, 0, 0.5, 0.5));
    }
    //custom button
    AddNewObject(new Engine::Label("Custom", "pirulen.ttf", 40, 200, halfH / 2  + 225, 200, 200, 200, 255, 0, 0));
    for (int i=0;i<3;++i) {
        btn = new Engine::ImageButton("win/box.png", "win/box-hover.png", 200 + 150 * i, halfH / 2 + 300, 100, 100);
        btn->SetOnClickCallback(std::bind(&GalleryTurretScene::TurretOnClick, this, i, true));
        AddNewControlObject(btn);
        AddNewObject(new Engine::Image("play/tower-base.png", 250 + 150 * i, halfH / 2 + 50 + 300, 0, 0, 0.5, 0.5));
        AddNewObject(new Engine::Image("play/custom-" + std::to_string(Player::GetInstance().GetCustomData(i).appearance) + ".png", 250 + 150 * i, halfH / 2 + 50 + 300 - 8, 0, 0, 0.5, 0.5));
    }
    //initial preview
    AddNewObject(new Engine::Image("win/box.png", w * 13 / 16, halfH * 3 / 4, 400, 400, 0.5, 0.5));
    AddNewObject(new Engine::Image("play/tower-base.png", w * 13 / 16, halfH * 3 / 4, 300, 300, 0.5, 0.5));
    preview = new Engine::Image("play/turret-1.png", w * 13 / 16, halfH * 3 / 4 - 30, 300, 300, 0.5, 0.5);
    AddNewObject(preview);
    //description
    AddNewObject(new Engine::Label("Damage: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220, 200, 200, 200, 255, 0, 0));
    damageUI = new Engine::Label(basicStats[0][0], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220, 200, 200, 200, 255, 0, 0);
    AddNewObject(damageUI);
    AddNewObject(new Engine::Label("Range: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220 + 40, 200, 200, 200, 255, 0, 0));
    rangeUI = new Engine::Label(basicStats[0][1], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220 + 40, 200, 200, 200, 255, 0, 0);
    AddNewObject(rangeUI);
    AddNewObject(new Engine::Label("Speed: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220 + 80, 200, 200, 200, 255, 0, 0));
    speedUI = new Engine::Label(basicStats[0][2], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220 + 80, 200, 200, 200, 255, 0, 0);
    AddNewObject(speedUI);
    AddNewObject(new Engine::Label("Fire Rate: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220 + 120, 200, 200, 200, 255, 0, 0));
    rateUI = new Engine::Label(basicStats[0][3], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220 + 120, 200, 200, 200, 255, 0, 0);
    AddNewObject(rateUI);
    AddNewObject(new Engine::Label("Ability: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220 + 160, 200, 200, 200, 255, 0, 0));
    abilityUI = new Engine::Label(basicStats[0][4], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220 + 160, 200, 200, 200, 255, 0, 0);
    AddNewObject(abilityUI);
    AddNewObject(new Engine::Label("Cost: ", "pirulen.ttf", 32, w * 13 / 16 - 200, halfH * 3 / 4 + 220 + 200, 200, 200, 200, 255, 0, 0));
    costUI = new Engine::Label(basicStats[0][5], "pirulen.ttf", 32, w * 27 / 32, halfH * 3 / 4 + 220 + 200, 200, 200, 200, 255, 0, 0);
    AddNewObject(costUI);
    //BGM
    bgmInstance = AudioHelper::PlaySample("happy.ogg", true, AudioHelper::BGMVolume);
}

void GalleryTurretScene::Terminate() {
    IScene::Terminate();
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void GalleryTurretScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("gallery");
}

void GalleryTurretScene::TurretOnClick(int number, bool custom) {
    RemoveObject(preview->GetObjectIterator());
    if (custom) {
        customTurret temp = Player::GetInstance().GetCustomData(number);
        preview = new Engine::Image("play/custom-" + std::to_string(Player::GetInstance().GetCustomData(number).appearance) + ".png", Engine::GameEngine::GetInstance().GetScreenSize().x * 13 / 16, Engine::GameEngine::GetInstance().GetScreenSize().y / 2 * 3 / 4 - 30, 300, 300, 0.5, 0.5);
        damageUI->Text = FtoStr(temp.damage);
        rangeUI->Text = FtoStr(temp.radius);
        speedUI->Text = FtoStr(temp.speed);
        rateUI->Text = FtoStr(temp.fireRate);
        abilityUI->Text = customAbilityNames[temp.ability];
        costUI->Text = std::to_string(temp.cost);
    }
    else {
        preview = new Engine::Image("play/turret-" + std::to_string(number) + ".png", Engine::GameEngine::GetInstance().GetScreenSize().x * 13 / 16, Engine::GameEngine::GetInstance().GetScreenSize().y / 2 * 3 / 4 - 30, 300, 300, 0.5, 0.5);
        damageUI->Text = basicStats[number - 1][0];
        rangeUI->Text = basicStats[number - 1][1];
        speedUI->Text = basicStats[number - 1][2];
        rateUI->Text = basicStats[number - 1][3];
        abilityUI->Text = basicStats[number - 1][4];
        costUI->Text = basicStats[number - 1][5];
    }
    AddNewObject(preview);
}