#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <vector>
#include <set>
#include <fstream>

#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "ScoreboardScene.h"

int w, h, halfW, halfH, currentPage, totalPages;
std::ifstream fin("Resource/scoreboard.txt");
std::vector<std::set<std::pair<std::string, std::string>, compare>> pages;

void ScoreboardScene::Initialize() {
    w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    halfW = w / 2;
    halfH = h / 2;
    currentPage = 0;
    totalPages = 0;
    ReadScore();
    ShowScore(currentPage);

    Engine::ImageButton *btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::BackOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 700, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::PrevOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Prev Page", "pirulen.ttf", 48, halfW - 500, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 300, halfH * 3 / 2 + 50,400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::NextOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next Page", "pirulen.ttf", 48, halfW + 500, halfH * 3 / 2 + 100, 0, 0, 0, 255, 0.5, 0.5));

    AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 52, halfW, halfH * 1 / 2 - 150, 0, 200, 0, 255, 0.5, 0.5));
}

void ScoreboardScene::Terminate() {
    fin.close();
    IScene::Terminate();
}

void ScoreboardScene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void ScoreboardScene::PrevOnClick(int stage) {
    if(currentPage > 0){
        ScoreboardScene::ClearScore();
        ScoreboardScene::ShowScore(--currentPage);
    }
}

void ScoreboardScene::NextOnClick(int stage) {
    if(currentPage < totalPages-1){
        ScoreboardScene::ClearScore();
        ScoreboardScene::ShowScore(++currentPage);
    }
}

void ScoreboardScene::ReadScore() {
    int cnt=0;
    std::string name, score;
    std::set<std::pair<std::string, std::string>, compare> temp;
    ++totalPages;
    while(fin>>name>>score){
        temp.insert(std::pair<std::string, std::string>(name, score));
        ++cnt;
        if(cnt==10){
            break;
        }
    }
    pages.push_back(temp);
}

void ScoreboardScene::ShowScore(int number) {
    int offset=1;
    if(pages[number].empty()){
        ReadScore();
    }
    for(auto it: pages[number]){
        AddNewObject(new Engine::Label(it.first + "  " + it.second, "pirulen.ttf", 44, halfW, halfH * 1 / 2 - 140 + offset * 55, 0, 150, 0, 255, 0.5, 0.5));
        ++offset;
    }
}

void ScoreboardScene::ClearScore() {
    //RemoveObject();
}