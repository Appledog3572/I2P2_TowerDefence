#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <list>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "PlayScene.hpp"
#include "CustomTurretScene.hpp"

std::vector<std::string> abilityList = {
        "None",
        "Double Shoot",
        "Frozen"
};
const int appearanceAmount = 4;
const int abilityAmount = abilityList.size();

std::string FtoStr(float value) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    return stream.str();
}

void CustomTurretScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Data = Player::GetInstance().GetCustomData(turretID);
    Engine::ImageButton *btn;
    //back button
    btn = new Engine::ImageButton("shop/plate2.png", "shop/plate.png", 25, -50,200, 200);
    btn->SetOnClickCallback(std::bind(&CustomTurretScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Image("shop/back_arrow.png", 125, 75, 75, 50, 0.5, 0.5));
    //turret preview
    preview = new Engine::Image("play/custom-" + std::to_string(Data.appearance) + ".png", w * 13 / 16, halfH, 500, 500, 0.5, 0.5);
    AddNewObject(preview);
    Slider *radius, *fireRate, *damage, *speed;
    //turret column
    AddNewObject(new Engine::Label("Turret", "pirulen.ttf", 28, 300, halfH / 2, 255, 255, 255, 255, 0.5, 0.5));
    //radius
    radius = new Slider(300 - halfW / 8, halfH * 3 / 4, w / 8, 4);
    radius->SetOnValueChangedCallback(std::bind(&CustomTurretScene::RadiusSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(radius);
    radiusUI = new Engine::Label(std::to_string((int)Data.radius), "pirulen.ttf", 28, 325 + halfW / 6, halfH * 3 / 4, 255, 255, 255, 255 ,0.5 ,0.5);
    AddNewObject(radiusUI);
    AddNewObject(new Engine::Label("Radius", "pirulen.ttf", 24, 275 - halfW / 5, halfH * 3 / 4, 255, 255, 255, 255 ,0.5 ,0.5));
    //fire rate
    fireRate = new Slider(300 - halfW / 8, halfH, w / 8, 4);
    fireRate->SetOnValueChangedCallback(std::bind(&CustomTurretScene::RateSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(fireRate);
    rateUI = new Engine::Label(FtoStr(Data.fireRate), "pirulen.ttf", 28, 325 + halfW / 6, halfH, 255, 255, 255, 255 ,0.5 ,0.5);
    AddNewObject(rateUI);
    AddNewObject(new Engine::Label("Fire", "pirulen.ttf", 24, 275 - halfW / 5, halfH - 15, 255, 255, 255, 255 ,0.5 ,0.5));
    AddNewObject(new Engine::Label("Rate", "pirulen.ttf", 24, 275 - halfW / 5, halfH + 15, 255, 255, 255, 255 ,0.5 ,0.5));
    //bullet column
    AddNewObject(new Engine::Label("Bullet", "pirulen.ttf", 28, 800, halfH / 2, 255, 255, 255, 255, 0.5, 0.5));
    //damage
    damage = new Slider(800 - halfW / 8, halfH * 3 / 4, w / 8, 4);
    damage->SetOnValueChangedCallback(std::bind(&CustomTurretScene::DamageSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(damage);
    damageUI = new Engine::Label(FtoStr(Data.damage), "pirulen.ttf", 28, 825 + halfW / 6, halfH * 3 / 4, 255, 255, 255, 255 ,0.5 ,0.5);
    AddNewObject(damageUI);
    AddNewObject(new Engine::Label("Damage", "pirulen.ttf", 24, 775 - halfW / 5, halfH * 3 / 4, 255, 255, 255, 255 ,0.5 ,0.5));
    //speed
    speed = new Slider(800 - halfW / 8, halfH, w / 8, 4);
    speed->SetOnValueChangedCallback(std::bind(&CustomTurretScene::SpeedSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(speed);
    speedUI = new Engine::Label(std::to_string((int)Data.speed), "pirulen.ttf", 28, 825 + halfW / 6, halfH, 255, 255, 255, 255 ,0.5 ,0.5);
    AddNewObject(speedUI);
    AddNewObject(new Engine::Label("Bullet", "pirulen.ttf", 24, 775 - halfW / 5, halfH - 15, 255, 255, 255, 255 ,0.5 ,0.5));
    AddNewObject(new Engine::Label("Speed", "pirulen.ttf", 24, 775 - halfW / 5, halfH + 15, 255, 255, 255, 255 ,0.5 ,0.5));
    //appearance
    AddNewObject(new Engine::Label("Appearance", "pirulen.ttf", 28, w * 5 / 16, h * 10 / 16, 255, 255, 255, 255, 0.5, 0.5));
    appearanceUI = new Engine::Label("Type " + std::to_string(Data.appearance), "pirulen.ttf", 24, w * 5 / 16, h * 11 / 16, 255, 255, 255, 255, 0.5, 0.5);
    AddNewObject(appearanceUI);
    //next button
    btn = new Engine::ImageButton("shop/next_arrow.png", "shop/next_arrow.png", w * 7 / 16 - 24, h * 11 / 16 - 24,50, 50);
    btn->SetOnClickCallback(std::bind(&CustomTurretScene::AppearanceNextOnClick, this));
    AddNewControlObject(btn);
    //back button
    btn = new Engine::ImageButton("shop/back_arrow.png", "shop/back_arrow.png", w * 3 / 16 - 24, h * 11 / 16 - 24,50, 50);
    btn->SetOnClickCallback(std::bind(&CustomTurretScene::AppearanceBackOnClick, this));
    AddNewControlObject(btn);
    //ability
    AddNewObject(new Engine::Label("Ability", "pirulen.ttf", 28, w * 5 / 16, h * 25 / 32, 255, 255, 255, 255, 0.5, 0.5));
    abilityUI = new Engine::Label(abilityList[Data.ability], "pirulen.ttf", 24, w * 5 / 16, h * 27 / 32, 255, 255, 255, 255, 0.5, 0.5);
    AddNewObject(abilityUI);
    //next button
    btn = new Engine::ImageButton("shop/next_arrow.png", "shop/next_arrow.png", w * 7 / 16 - 24, h * 27 / 32 - 24,50, 50);
    btn->SetOnClickCallback(std::bind(&CustomTurretScene::AbilityNextOnClick, this));
    AddNewControlObject(btn);
    //back button
    btn = new Engine::ImageButton("shop/back_arrow.png", "shop/back_arrow.png", w * 3 / 16 - 24, h * 27 / 32 - 24,50, 50);
    btn->SetOnClickCallback(std::bind(&CustomTurretScene::AbilityBackOnClick, this));
    AddNewControlObject(btn);
    //price
    AddNewObject(new Engine::Label("Total Cost: ", "pirulen.ttf", 28, halfW * 3 / 4, h * 15 / 16, 255, 255, 255, 255, 1, 0.5));
    costUI = new Engine::Label(std::to_string(Data.cost), "pirulen.ttf", 28, halfW * 3 / 4, h * 15 / 16, 255, 255, 255, 255, 0, 0.5);
    AddNewObject(costUI);
    //set slider value
    radius->SetValue(Data.radius / 1000);
    fireRate->SetValue(1 - (Data.fireRate / 5));
    damage->SetValue(Data.damage / 50);
    speed->SetValue(Data.speed / 1000);
    //BGM
    bgmInstance = AudioHelper::PlaySample("Sugar Cubes(shop).ogg", true, AudioHelper::BGMVolume);
}

void CustomTurretScene::Terminate() {
    IScene::Terminate();
    Player::GetInstance().SetCustomData(turretID, Data);
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
}

void CustomTurretScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("shop");
}

void CustomTurretScene::AppearanceNextOnClick(){
    if(Data.appearance == appearanceAmount) {
        Data.appearance = 1;
    }
    else {
        ++Data.appearance;
    }
    appearanceUI->Text = "Type " + std::to_string(Data.appearance);
    RemoveObject(preview->GetObjectIterator());
    preview = new Engine::Image("play/custom-" + std::to_string(Data.appearance) + ".png", Engine::GameEngine::GetInstance().GetScreenSize().x * 13 / 16, Engine::GameEngine::GetInstance().GetScreenSize().y / 2, 500, 500, 0.5, 0.5);
    AddNewObject(preview);
}

void CustomTurretScene::AppearanceBackOnClick(){
    if(Data.appearance == 1) {
        Data.appearance = appearanceAmount;
    }
    else {
        --Data.appearance;
    }
    appearanceUI->Text = "Type " + std::to_string(Data.appearance);
    RemoveObject(preview->GetObjectIterator());
    preview = new Engine::Image("play/custom-" + std::to_string(Data.appearance) + ".png", Engine::GameEngine::GetInstance().GetScreenSize().x * 13 / 16, Engine::GameEngine::GetInstance().GetScreenSize().y / 2, 500, 500, 0.5, 0.5);
    AddNewObject(preview);
}

void CustomTurretScene::AbilityNextOnClick(){
    if(Data.ability == abilityAmount - 1) {
        Data.ability = 0;
    }
    else {
        ++Data.ability;
    }
    abilityUI->Text = abilityList[Data.ability];
}

void CustomTurretScene::AbilityBackOnClick(){
    if(Data.ability == 0) {
        Data.ability = abilityAmount - 1;
    }
    else {
        --Data.ability;
    }
    abilityUI->Text = abilityList[Data.ability];
}

void CustomTurretScene::RadiusSlideOnValueChanged(float value){
    Data.radius = value * 1000;
    radiusUI->Text = std::to_string((int)Data.radius);
    Data.cost = GetCost();
    costUI->Text = std::to_string(Data.cost);
}

void CustomTurretScene::RateSlideOnValueChanged(float value){
    Data.fireRate = value >= 0.98 ? 0.1 : (1 - value) * 5;
    rateUI->Text = FtoStr(Data.fireRate);
    Data.cost = GetCost();
    costUI->Text = std::to_string(Data.cost);
}

void CustomTurretScene::DamageSlideOnValueChanged(float value){
    Data.damage = value * 50;
    damageUI->Text = FtoStr(Data.damage);
    Data.cost = GetCost();
    costUI->Text = std::to_string(Data.cost);
}

void CustomTurretScene::SpeedSlideOnValueChanged(float value){
    Data.speed = value * 1000;
    speedUI->Text = std::to_string((int)Data.speed);
    Data.cost = GetCost();
    costUI->Text = std::to_string(Data.cost);
}

int CustomTurretScene::GetCost() {
    float WeightRadius = 0.3;
    float WeightRate = 20;
    float WeightRatePlusDamage = 1.1;
    float WeightSpeed = 0.15;
    int price = WeightRadius * (Data.radius - 200)
            + pow((6 - Data.fireRate) * Data.damage, WeightRatePlusDamage)
            + WeightRate * (5 - Data.fireRate)
            + WeightSpeed * (Data.speed - 400);
    return price < 0 ? 0: price;
}