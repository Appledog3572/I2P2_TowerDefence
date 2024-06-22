#ifndef CUSTOMTURRETSCENE_HPP
#define CUSTOMTURRETSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include <vector>
#include "Engine/IScene.hpp"
#include "Engine/Player.hpp"

class CustomTurretScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    int turretID;
    customTurret Data;
    Engine::Image* preview;
    Engine::Label* radiusUI;
    Engine::Label* rateUI;
    Engine::Label* damageUI;
    Engine::Label* speedUI;
    Engine::Label* appearanceUI;
    Engine::Label* abilityUI;
    Engine::Label* costUI;
    explicit CustomTurretScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick();
    void AppearanceNextOnClick();
    void AppearanceBackOnClick();
    void AbilityNextOnClick();
    void AbilityBackOnClick();
    void RadiusSlideOnValueChanged(float value);
    void RateSlideOnValueChanged(float value);
    void DamageSlideOnValueChanged(float value);
    void SpeedSlideOnValueChanged(float value);
    int GetCost();
};
#endif //CUSTOMTURRETSCENE_HPP
