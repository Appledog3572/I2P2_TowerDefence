#include <fstream>
#include "Player.hpp"

Player Player::player;

Player::Player() {
}

Player& Player::GetInstance(){
    return player;
}

void Player::ChangePlayer(int ID){
//    std::ifstream fin("Resource/player" + std::to_string(ID) + ".txt");
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