#include "LogInScene.hpp"
#include "StartScene.h"
#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/StartScene.h"
#include "Engine/Player.hpp"

#include <fstream>
#include <iostream>

int ID;

void LogInScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    //title
    AddNewObject(new Engine::Label("Tower Defense", "pirulen.ttf", 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));

    AddNewObject(new Engine::Image("win/text-box.png", halfW, halfH - 50, 500, 70, 0.5, 0.5));
    AddNewObject(UIPlayerId=new Engine::Label("", "pirulen.ttf", 48,halfW - 245, halfH - 50, 255, 255, 255, 255, 0, 0.5));
    //(new Engine::Image("win/text-box.png", halfW, halfH + 50, 500, 70, 0.5, 0.5));
    //AddNewObject(UIPlayerPassword=new Engine::Label("", "pirulen.ttf", 48,halfW +15, halfH / 4 + 60, 255, 255, 255, 255, 0, 0.5));
    //log in button
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&LogInScene::LogInOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Log In", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));

}
void LogInScene::Terminate() {
    IScene::Terminate();
}
void LogInScene::LogInOnClick() {
    std::string PlayerID=UIPlayerId->Text;
    std::ifstream fin("../Resource/players/" + PlayerID + ".txt");
    if(fin){
        Player::GetInstance().ChangePlayer(ID);
        fin.close();
        ID = std::stoi(UIPlayerId->Text);
        Engine::GameEngine::GetInstance().ChangeScene("start");
    }
}
void LogInScene::Update(float deltaTime) {

}
void LogInScene::OnKeyDown(int keyCode) {
    IScene::OnKeyDown(keyCode);
    if(keyCode>=ALLEGRO_KEY_A && keyCode<=ALLEGRO_KEY_Z){
        if(UIPlayerId->Text.size()<9){
            UIPlayerId->Text += ('A' + keyCode - 1);
        }
    }
    else if(keyCode>=ALLEGRO_KEY_0 && keyCode<=ALLEGRO_KEY_9){
        if(UIPlayerId->Text.size()<9){
            UIPlayerId->Text += ('0' + keyCode - 27);
        }
    }
    else if(keyCode==ALLEGRO_KEY_BACKSPACE){
        if(UIPlayerId->Text.begin()!=UIPlayerId->Text.end()){
            UIPlayerId->Text.pop_back();
        }
    }
}
