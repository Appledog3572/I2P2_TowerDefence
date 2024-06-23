#ifndef GALLERYSCENE_HPP
#define GALLERYSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class GalleryScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    explicit GalleryScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void TurretOnClick();
    void EnemyOnClick();
};
#endif //GALLERYSCENE_HPP
