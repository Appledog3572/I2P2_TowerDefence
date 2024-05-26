#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "ToolButton.hpp"
#include "Engine/Sprite.hpp"

class PlayScene;

class Shovel: public Engine::Image {
protected:
    PlayScene* getPlayScene();

public:
    bool Enabled = true;
    bool Preview = false;
    Shovel(float x, float y);
    void Update(float deltaTime) override;
    void Draw() const override;
};
#endif //SHOVEL_HPP
