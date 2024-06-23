#ifndef GALLERYENEMYSCENE_HPP
#define GALLERYENEMYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class GalleryEnemyScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    Engine::Image* preview;
    explicit GalleryEnemyScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void EnemyOnClick(int number);
};
#endif //GALLERYENEMYSCENE_HPP
