#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"
class StartScene final : public Engine::IScene {
public:
    explicit StartScene() = default;
    void Initialize() override;
    void Terminate() override;
    void PlayOnClick();
    void SettingsOnClick();
    void LoadVolume();
    void LogOutOnClick();
};
#endif //STARTSCENE_H
