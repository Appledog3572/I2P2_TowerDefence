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
#include "Shovel.hpp"

PlayScene* Shovel::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
Shovel::Shovel(float x, float y) :
        Image("play/shovel.png", x, y) {
}
void Shovel::Update(float deltaTime) {
    Image::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    if (!Enabled)
        return;
}
void Shovel::Draw() const {
    Image::Draw();
}

