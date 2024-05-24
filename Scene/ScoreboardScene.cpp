#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <vector>
#include <set>
#include <fstream>
#include <list>

#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "ScoreboardScene.h"
#include "Engine/IObject.hpp"

int w, h, halfW, halfH, currentPage, totalPages;
std::ifstream *fin;
std::list<Engine::IObject*> scoreList;
std::set<std::tuple<std::string, std::string, std::string>, compare> pages;

void ScoreboardScene::Initialize() {
    w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    halfW = w / 2;
    halfH = h / 2;
    currentPage = 0;
    totalPages = 0;

    Engine::ImageButton *btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 700, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::PrevOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Prev Page", "pirulen.ttf", 48, halfW - 500, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 300, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::NextOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next Page", "pirulen.ttf", 48, halfW + 500, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 52, halfW, halfH * 1 / 2 - 150, 0, 200, 0, 255, 0.5, 0.5));

    fin=new std::ifstream("Resource/scoreboard.txt");
    ReadScore();
    ShowScore(currentPage);
}

void ScoreboardScene::Terminate() {
    fin->close();
    pages.clear();
    scoreList.clear();
    IScene::Terminate();
}

void ScoreboardScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void ScoreboardScene::PrevOnClick() {
    if(currentPage > 0){
        ScoreboardScene::ClearScore();
        ScoreboardScene::ShowScore(--currentPage);
    }
}

void ScoreboardScene::NextOnClick() {
    if(currentPage < totalPages-1){
        ScoreboardScene::ClearScore();
        ScoreboardScene::ShowScore(++currentPage);
    }
}

void ScoreboardScene::ReadScore() {
    int cnt=0;
    std::string name, score, time;
    while(*fin>>name>>score>>time){
        pages.insert(std::tuple<std::string, std::string, std::string>(name, score, time));
        ++cnt;
    }
    totalPages=cnt/10;
    if(cnt%10!=0){
        ++totalPages;
    }
}

void ScoreboardScene::ShowScore(int number) {
    int offset=1;
    auto itl=std::next(pages.begin(), 10*number);
    auto itr=itl;
    for(int i=0;i<10;++i){
        if(itr==pages.end()){
            break;
        }
        ++itr;
    }
    for(auto it=itl;it!=itr;++it){
        auto temp1=new Engine::Label(std::get<0>(*it), "pirulen.ttf", 44, halfW-400, halfH * 1 / 2 - 140 + offset * 55, 0, 150, 0, 255, 0.5, 0.5);
        auto temp2=new Engine::Label(std::get<1>(*it), "pirulen.ttf", 44, halfW-50, halfH * 1 / 2 - 140 + offset * 55, 0, 150, 0, 255, 0.5, 0.5);
        auto temp3=new Engine::Label(std::get<2>(*it), "pirulen.ttf", 44, halfW+400, halfH * 1 / 2 - 140 + offset * 55, 0, 150, 0, 255, 0.5, 0.5);
        AddNewObject(temp1);
        scoreList.push_back(temp1);
        AddNewObject(temp2);
        scoreList.push_back(temp2);
        AddNewObject(temp3);
        scoreList.push_back(temp3);
        ++offset;
    }
}

void ScoreboardScene::ClearScore() {
    for(auto &it : scoreList){
        RemoveObject(it->GetObjectIterator());
    }
    scoreList.clear();
}