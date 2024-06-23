#ifndef FREEZERSKIN_HPP
#define FREEZERSKIN_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class Freezerskin final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    explicit Freezerskin() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void Select1OnClick();
    void Select2OnClick();
    Engine::Label *left;
    Engine::Label *right;
};
#endif //FREEZERSKIN_HPP