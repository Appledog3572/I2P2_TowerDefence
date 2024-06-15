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
    int ItemPrice[3] = {1, 2, 3};
    Engine::Label* MoneyDisplay;
    Engine::Label* ItemAmountDisplay[3];
    explicit ShopScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void ItemOnClick(int number);
    void TurretOnClick(int number);
    void SkinOnClick();
};

#endif //MAPEDITORSCENE_HPP
