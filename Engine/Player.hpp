#ifndef PLAYER_HPP
#define PLAYER_HPP
struct customTurret{
    float radius = 500;
    float fireRate = 2;
    float damage = 2;
    float speed = 300;
    int appearance = 1;
    int ability = 0;
    int cost = 50;
};

class Player{
private:
    Player();
    static Player player;
    int money;
    int itemAmount[3];
    float BGM;
    float SFX;
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
    void SetVolume(float bgm, float sfx);
    void SavePlayer(int ID);
};
#endif //PLAYER_HPP
