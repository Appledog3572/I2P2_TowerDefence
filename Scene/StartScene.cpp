#include "StartScene.h"
#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/StartScene.h"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    //title
    AddNewObject(new Engine::Label("Tower Defense", "pirulen.ttf", 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("-Enhanced Edition-", "pirulen.ttf", 60, halfW, halfH / 3 + 150, 10, 255, 255, 255, 0.5, 0.5));

    //play button
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH / 2 + 200 , 400, 100);
    btn->SetOnClickCallback(std::bind(&StartScene::PlayOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Play", "pirulen.ttf", 48, halfW, halfH / 2 + 250, 0, 0, 0, 255, 0.5, 0.5));
    //settings button
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&StartScene::SettingsOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Settings", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
}
void StartScene::Terminate() {
    IScene::Terminate();
}
void StartScene::PlayOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void StartScene::SettingsOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}
void StartScene::LoadVolume() {
    std::string filename = "../Resource/volume.txt";
    std::ifstream fin(filename);
    float bv, sv;
    fin >> bv >> sv;

    AudioHelper::BGMVolume = bv;
    AudioHelper::SFXVolume = sv;
}
void StartScene::LogOutOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("login");
}