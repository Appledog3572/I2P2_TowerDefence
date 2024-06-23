#include "MapEditScene.hpp"

#include <fstream>
#include <iostream>

#include "PlayScene.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Tool/ToolButton.hpp"

Engine::Point MapEditScene::GetClientSize() {
    return Engine::Point(MapWidth * BlockSize, MapHeight * BlockSize);
}
void MapEditScene::Initialize() {
    AddNewObject(TileMapGroup = new Group());
    AddNewControlObject(UIGroup = new Group());
    ReadMap();
    ConstructUI();
    bgmId = AudioHelper::PlayBGM("play.ogg");
}
void MapEditScene::Terminate() {
    state = -1;
    //SaveMap();
    mapData.clear();
    mapState.clear();
    //TileMapGroup->Clear();
    //UIGroup->Clear();
    AudioHelper::StopBGM(bgmId);
    IScene::Terminate();
}
void MapEditScene::Draw() const {
    IScene::Draw();
}
void MapEditScene::OnMouseDown(int button, int mx, int my) {
    IScene::OnMouseDown(button, mx, my);
}
void MapEditScene::OnMouseMove(int mx, int my) {
    IScene::OnMouseMove(mx, my);
}
void MapEditScene::OnMouseUp(int button, int mx, int my) {
    IScene::OnMouseUp(button, mx, my);
    int x = mx / BlockSize;
    int y = my / BlockSize;
    if(x == 0 && y == 0 || x == 19 && y == 12) return;
    if((button & 1) && state != -1) {
        for(auto it: TileMapGroup->GetObjects()){
            if((int)it->Position.x/BlockSize==x && (int)it->Position.y/BlockSize==y){
                TileMapGroup->RemoveObject(it->GetObjectIterator());
                TileMapGroup->Update(0);
                break;
            }
        }
        if(state == 0) {
            mapState[y][x] = TILE_DIRT;
            mapData[y * MapWidth + x] = 0;
            TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-0.png", x * BlockSize, y * BlockSize, BlockSize, BlockSize));
        }
        else if(state == 1) {
            mapState[y][x] = TILE_FLOOR;
            mapData[y * MapWidth + x] = 1;
            TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-1.png", x * BlockSize, y * BlockSize, BlockSize, BlockSize));
        }
        else if(state == 3) {
            mapState[y][x] = TILE_EMPTY;
            mapData[y * MapWidth + x] = 3;
        }
    }
}
void MapEditScene::OnKeyDown(int keyCode) {

}
void MapEditScene::ReadMap() {
    std::string filename = "../Resource/map0.txt";

    // Read map file.
    //mapData.clear();
    //mapState.clear();
    char c;
    std::ifstream fin(filename);
    while (fin >> c) {
        switch (c) {
        case '0': mapData.push_back(0); break;
        case '1': mapData.push_back(1); break;
        case '2': mapData.push_back(2); break;
        case '3': mapData.push_back(3); break;
        case '\n':
        case '\r':
            if (static_cast<int>(mapData.size()) / MapWidth != 0)
                throw std::ios_base::failure("Map data is corrupted.");
            break;
        default: throw std::ios_base::failure("Map data is corrupted.");
        }
    }
    fin.close();
    // Validate map data.
    if (static_cast<int>(mapData.size()) != MapWidth * MapHeight)
        throw std::ios_base::failure("Map data is corrupted.");
    // Store map in 2d array.
    mapState = std::vector<std::vector<TileType>>(MapHeight, std::vector<TileType>(MapWidth));
    for (int i = 0; i < MapHeight; i++) {
        for (int j = 0; j < MapWidth; j++) {
            const int num = mapData[i * MapWidth + j];
            if(num == 2) {
                mapState[i][j] = TILE_OCCUPIED;
                TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-2.png", j * BlockSize, i * BlockSize, BlockSize, BlockSize));
            }
            else if (num == 1) {
                mapState[i][j] = TILE_FLOOR;
                TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-1.png", j * BlockSize, i * BlockSize, BlockSize, BlockSize));
            }
            else if(num == 0) {
                mapState[i][j] = TILE_DIRT;
                TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-0.png", j * BlockSize, i * BlockSize, BlockSize, BlockSize));
            }
            else if(num == 3) {
                mapState[i][j] = TILE_EMPTY;
                TileMapGroup->AddNewObject(new Engine::Image("mapedit/block-3.png", j * BlockSize, i * BlockSize, BlockSize, BlockSize));
            }
        }
    }
}
void MapEditScene::ConstructUI() {
    // Background
	UIGroup->AddNewObject(new Engine::Image("play/sand.png", 1280, 0, 320, 832));
	// Text
	UIGroup->AddNewObject(new Engine::Label("Map Editing", "pirulen.ttf", 32, 1294, 0));

    Engine::ImageButton* btn;
	// Button 0 dirt
	btn = new Engine::ImageButton("mapedit/block-0.png", "mapedit/block-0-hovered.png", 1294, 136, 64, 64, 0, 0);
	btn->SetOnClickCallback(std::bind(&MapEditScene::UIBtnClicked, this, 0));
	UIGroup->AddNewControlObject(btn);
    // button 1 floor
    btn = new Engine::ImageButton("mapedit/block-1.png", "mapedit/block-1-hovered.png", 1370, 136, 64, 64, 0, 0);
    btn->SetOnClickCallback(std::bind(&MapEditScene::UIBtnClicked, this, 1));
    UIGroup->AddNewControlObject(btn);
    // button 2 wall
    btn = new Engine::ImageButton("mapedit/block-2.png", "mapedit/block-2-hovered.png", 1446, 136, 64, 64, 0, 0);
    btn->SetOnClickCallback(std::bind(&MapEditScene::UIBtnClicked, this, 2));
    UIGroup->AddNewControlObject(btn);
    // button 3 erase
    btn = new Engine::ImageButton("mapedit/block-3.png", "mapedit/block-3-hovered.png", 1522, 136, 64, 64, 0, 0);
    btn->SetOnClickCallback(std::bind(&MapEditScene::UIBtnClicked, this, 3));
    UIGroup->AddNewControlObject(btn);
    // button save
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", 1315,  567, 250, 100);
    btn->SetOnClickCallback(std::bind(&MapEditScene::SaveOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("SAVE", "pirulen.ttf", 48, 1440, 617, 0, 0, 0, 255, 0.5, 0.5));
    // button back
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", 1315, 682, 250, 100);
    btn->SetOnClickCallback(std::bind(&MapEditScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("back", "pirulen.ttf", 48, 1440, 732, 0, 0, 0, 255, 0.5, 0.5));
    // button play
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", 1315, 452, 250, 100);
    btn->SetOnClickCallback(std::bind(&MapEditScene::PlayOnClick, this, 0));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("play", "pirulen.ttf", 48, 1440, 502, 0, 0, 0, 255, 0.5, 0.5));

}
void MapEditScene::UIBtnClicked(int id) {
    state = id;
}
void MapEditScene::SaveMap() {
    std::ofstream fout("../Resource/map0.txt", std::ios_base::trunc);
    for (int i = 0; i < MapHeight; i++) {
        for (int j = 0; j < MapWidth; j++) {
            char c;
            if(mapData[i * MapWidth + j] == 0) c = '0';
            else if(mapData[i * MapWidth + j] == 1) c = '1';
            else if(mapData[i * MapWidth + j] == 2) c = '2';
            else if(mapData[i * MapWidth + j] == 3) c = '3';
            fout << c;
        }
        fout << '\n';
    }
    fout.close();
}
void MapEditScene::SaveOnClick() {
    SaveMap();
}
void MapEditScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void MapEditScene::PlayOnClick(int stage) {
    mapData.clear();
    mapState.clear();
    PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
    scene->MapId = stage;
    Engine::GameEngine::GetInstance().ChangeScene("play");
}
