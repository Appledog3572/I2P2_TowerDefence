#ifndef SKINSCENE_HPP
#define SKINSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class SkinScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    explicit SkinScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void FreezerskinOnClick();
    void LaserskinOnClick();
    void FireskinOnClick();
    void MissileskinOnClick();
};
#endif //SKINSCENE_HPP
