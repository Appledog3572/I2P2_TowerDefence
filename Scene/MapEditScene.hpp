#ifndef MAPEDITSCENE_HPP
#define MAPEDITSCENE_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <string>
#include <allegro5/allegro_audio.h>

#include "Engine/IScene.hpp"
#include "Engine/Sprite.hpp"
#include "Turret/Turret.hpp"
#include "UI/Component/Label.hpp"

namespace Engine {
    class Image;
}

class MapEditScene final : public Engine::IScene {
private:
    enum TileType {
        TILE_DIRT = 0,
        TILE_FLOOR = 1,
        TILE_OCCUPIED = 2,
        TILE_EMPTY = 3
    };
    ALLEGRO_SAMPLE_ID bgmId;
    int state = -1;
public:
    static const int MapWidth = 20, MapHeight = 13;
    static const int BlockSize = 64;
    static const Engine::Point SpawnGridPoint;
    static const Engine::Point EndGridPoint;
    static const std::vector<int> code;
    int MapId;
    Group* TileMapGroup;
    Group* GroundEffectGroup;
    Group* DebugIndicatorGroup;
    Group* UIGroup;
    Engine::Image* imgTarget;
    std::vector<int> mapData;
    std::vector<std::vector<TileType>> mapState;
    std::vector<std::vector<int>> mapDistance;
    std::list<std::pair<int, float>> enemyWaveData;
    std::list<int> keyStrokes;

    static Engine::Point GetClientSize();
    explicit MapEditScene() = default;
    void Initialize() override;
    void Terminate() override;
    void Draw() const override;
    void OnMouseDown(int button, int mx, int my) override;
    void OnMouseMove(int mx, int my) override;
    void OnMouseUp(int button, int mx, int my) override;
    void OnKeyDown(int keyCode) override;

    void ReadMap();
    void ConstructUI();
    void UIBtnClicked(int id);
    bool CheckSpaceValid(int x, int y);
    void SaveMap();
    void SaveOnClick();
    void BackOnClick();
    void PlayOnClick(int stage);
};
#endif //MAPEDITSCENE_HPP
