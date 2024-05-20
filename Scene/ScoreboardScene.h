#ifndef INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H
#define INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H

#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

class ScoreboardScene final : public Engine::IScene {
private:
public:
    explicit ScoreboardScene() = default;

    void Initialize() override;

    void Terminate() override;

    void BackOnClick(int stage);

    void PrevOnClick(int stage);

    void NextOnClick(int stage);

    void ReadScore();

    void ShowScore(int number);

    void ClearScore();
};

struct compare{
    bool operator()(const std::pair<std::string, std::string> &lhs, const std::pair<std::string, std::string> &rhs) const{
        return stoi(rhs.second) <= stoi(lhs.second);
    }
};
#endif //INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H
