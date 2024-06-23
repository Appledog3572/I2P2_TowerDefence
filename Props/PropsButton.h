#ifndef PROPSBUTTON_HPP
#define PROPSBUTTON_HPP
#include <string>

#include "UI/Component/ImageButton.hpp"
#include "Engine/Sprite.hpp"

class PlayScene;

class PropsButton : public Engine::ImageButton {
protected:
    PlayScene* getPlayScene();
public:
    Engine::Sprite Props;
    PropsButton(std::string img, std::string imgIn, Engine::Sprite Props, float x, float y);
    void Update(float deltaTime) override;
    void Draw() const override;
};
#endif //PROPSBUTTON_HPP