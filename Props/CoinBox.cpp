#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <utility>

#include "Enemy/Enemy.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/IObject.hpp"
#include "Engine/IScene.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
#include "CoinBox.h"

PlayScene* CoinBox::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
CoinBox::CoinBox(float x, float y) :
        Image("play/CoinBox.png", x, y) {
}
void CoinBox::Update(float deltaTime) {
    Image::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    if (!Enabled)
        return;
}
void CoinBox::Draw() const {
    Image::Draw();
}