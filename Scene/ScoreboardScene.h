#ifndef INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H
#define INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H

#include <allegro5/allegro_audio.h>
#include <memory>
#include <string>
#include "Engine/IScene.hpp"

struct compare{
    bool operator()(const std::tuple<std::string, std::string, std::string, std::string> &lhs, const std::tuple<std::string, std::string, std::string, std::string> &rhs) const{
        if(std::get<1>(lhs)==std::get<1>(rhs)){
            return std::get<0>(rhs) >= std::get<0>(lhs);
        }
        return stoi(std::get<1>(rhs)) <= stoi(std::get<1>(lhs));
    }
};

class ScoreboardScene final : public Engine::IScene {
private:
public:
    explicit ScoreboardScene() = default;

    void Initialize() override;

    void Terminate() override;

    void BackOnClick();

    void PrevOnClick();

    void NextOnClick();

    void ReadScore();

    void ShowScore(int number);

    void ClearScore();
};

void AddScoreboard(std::string name, int score, std::string date, std::string time);

#endif //INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_SCOREBOARDSCENE_H
