#ifndef CoinBox_HPP
#define CoinBox_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "PropsButton.h"
#include "Engine/Sprite.hpp"

class PlayScene;

class CoinBox: public Engine::Image {
protected:
    PlayScene* getPlayScene();

public:
    bool Enabled = true;
    bool Preview = false;
    CoinBox(float x, float y);
    void Update(float deltaTime) override;
    void Draw() const override;
};
#endif //CoinBox_HPP