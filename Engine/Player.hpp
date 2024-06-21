#ifndef PLAYER_HPP
#define PLAYER_HPP
struct customTurret{
    float radius;
    float fireRate;
    float damage;
    float speed;
    int appearance;
    int ability;
    int cost;
};

class Player{
private:
    Player();
    static Player player;
    int money;
    int itemAmount[3];
    customTurret customData[3];
public:
    static Player& GetInstance();
    void ChangePlayer(int ID);
    int GetMoney();
    void SetMoney(int money);
    int GetItemAmount(int ID);
    void SetItemAmount(int ID, int amount);
    customTurret GetCustomData(int ID);
    void SetCustomData(int ID, customTurret Data);
};
#endif //PLAYER_HPP
