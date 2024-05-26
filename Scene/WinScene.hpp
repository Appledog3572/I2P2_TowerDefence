#ifndef WINSCENE_HPP
#define WINSCENE_HPP
#include <allegro5/allegro_audio.h>
#include "Engine/IScene.hpp"
#include "PlayScene.hpp"


class WinScene final : public Engine::IScene {
private:
	float ticks;
	ALLEGRO_SAMPLE_ID bgmId;
public:
    Engine::Label* UIName;
	explicit WinScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void BackOnClick();
    void OnKeyDown(int keyCode) override;
};

std::vector<std::string> getNowTime();

#endif // WINSCENE_HPP
