#ifndef GALLERYTURRETSCENE_HPP
#define GALLERYTURRETSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class GalleryTurretScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    Engine::Image* preview;
    Engine::Label* damageUI;
    Engine::Label* rangeUI;
    Engine::Label* speedUI;
    Engine::Label* rateUI;
    Engine::Label* abilityUI;
    Engine::Label* costUI;
    explicit GalleryTurretScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void TurretOnClick(int number, bool custom);
};

#endif //GALLERYTURRETSCENE_HPP
