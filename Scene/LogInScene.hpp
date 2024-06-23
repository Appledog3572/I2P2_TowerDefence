#ifndef LOGINSCENE_HPP
#define LOGINSCENE_HPP


#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"
#include "Engine/Player.hpp"
#include "UI/Component/Label.hpp"

class LogInScene final : public Engine::IScene {
private:
    float ticks;
public:
    Engine::Label* UIPlayerId;
    //Engine::Label* UIPlayerPassword;
    explicit LogInScene() = default;
    void Initialize() override;
    void Terminate() override;
    void LogInOnClick();
    void Update(float deltaTime) override;
    void OnKeyDown(int keyCode) override;
    //void ReadPlayerData(std::string PlayerID);
};
#endif //LOGINSCENE_HPP
