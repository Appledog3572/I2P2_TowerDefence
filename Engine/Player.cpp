#include <fstream>
#include "Player.hpp"
#include "AudioHelper.hpp"

Player Player::player;

Player::Player() {
}

Player& Player::GetInstance(){
    return player;
}

void Player::ChangePlayer(int ID){
    std::ifstream fin("../Resource/players/" + std::to_string(ID) + ".txt");
    fin >> money;
    for (int i = 0; i < 3; ++i) {
        fin >> itemAmount[i];
    }
    fin >> BGM;
    fin >> SFX;

    AudioHelper::BGMVolume = BGM;
    AudioHelper::SFXVolume = SFX;

    for (int i = 0; i < 3; ++i) {
        fin >> customData[i].radius
            >> customData[i].fireRate
            >> customData[i].damage
            >> customData[i].speed
            >> customData[i].appearance
            >> customData[i].ability;
    }

    fin.close();
}

int Player::GetMoney(){
    return money;
}

void Player::SetMoney(int money){
    this->money = money;
}

int Player::GetItemAmount(int ID){
    return itemAmount[ID];
}

void Player::SetItemAmount(int ID, int amount){
    itemAmount[ID] = amount;
}

customTurret Player::GetCustomData(int ID){
    return customData[ID];
}

void Player::SetCustomData(int ID, customTurret Data){
    customData[ID] = Data;
}