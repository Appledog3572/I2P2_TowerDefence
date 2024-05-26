#include <functional>
#include <string>
#include <stack>
#include <iostream>
#include <chrono>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "WinScene.hpp"
#include "PlayScene.hpp"
#include "Engine/IScene.hpp"
#include "ScoreboardScene.h"

std::string name;
std::stack<char> nameStack;

void WinScene::Initialize() {
	ticks = 0;
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int halfW = w / 2;
	int halfH = h / 2;
    AddNewObject(new Engine::Image("win/text-box.png", halfW, halfH / 4 + 60, 500, 70, 0.5, 0.5));
    AddNewObject(UIName=new Engine::Label(name, "pirulen.ttf", 48,halfW - 230, halfH / 4 + 60, 255, 255, 255, 255, 0, 0.5));
	AddNewObject(new Engine::Image("win/benjamin-sad.png", halfW, halfH, 0, 0, 0.5, 0.5));
	AddNewObject(new Engine::Label("You Win!", "pirulen.ttf", 48, halfW, halfH / 4 -10, 255, 255, 255, 255, 0.5, 0.5));
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));
	bgmId = AudioHelper::PlayAudio("win.wav");
}
void WinScene::Terminate() {
    std::string Name=UIName->Text;
    if(Name.empty()){
        Name="UNKNOWN";
    }
    AddScoreboard(Name, Score, getNowTime()[0], getNowTime()[1]);
	IScene::Terminate();
	AudioHelper::StopBGM(bgmId);
}
void WinScene::Update(float deltaTime) {
	ticks += deltaTime;
	if (ticks > 4 && ticks < 100 &&
		dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"))->MapId == 2) {
		ticks = 100;
		bgmId = AudioHelper::PlayBGM("happy.ogg");
	}
}
void WinScene::BackOnClick() {
	// Change to select scene.
	Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void WinScene::OnKeyDown(int keyCode){
    IScene::OnKeyDown(keyCode);
    if(keyCode>=ALLEGRO_KEY_A && keyCode<=ALLEGRO_KEY_Z){
        if(UIName->Text.size()<9){
            UIName->Text += ('A' + keyCode - 1);
        }
    }
    else if(keyCode>=ALLEGRO_KEY_0 && keyCode<=ALLEGRO_KEY_9){
        if(UIName->Text.size()<9){
            UIName->Text += ('0' + keyCode - 27);
        }
    }
    else if(keyCode==ALLEGRO_KEY_BACKSPACE){
        if(UIName->Text.begin()!=UIName->Text.end()){
            UIName->Text.pop_back();
        }
    }
}

std::vector<std::string> getNowTime(){
    auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm* ptm = localtime(&tt);
    char date[60] = { 0 };
    char time[10] = { 0 };
    sprintf(date, "%d/%02d/%02d",
            (int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday);
    sprintf(time, "%02d:%02d",
            (int)ptm->tm_hour, (int)ptm->tm_min);

    return std::vector<std::string>{date, time};
}