#ifndef MAPEDITORSCENE_HPP
#define MAPEDITORSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class ShopScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    explicit ShopScene() = default;

    void Initialize() override;

    void Terminate() override;

    void BackOnClick();

    void ItemOnClick(int number);

    void TurretOnClick(int number);
};

#endif //MAPEDITORSCENE_HPP
