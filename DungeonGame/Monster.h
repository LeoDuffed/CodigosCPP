#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <cstring>

class Monster{
public:
    Monster(): id(0), name{0}, hp(0), atk(0), def(0), prob(0.0), r_hp(0), r_atk(0), r_def(0) {}
    Monster(int newId, const char* newName, int hpValue, int atkValue, int defValue, double probValue, int rewardHp, int rewardAtk, int rewardDef):
        id(newId), name{0}, hp(hpValue), atk(atkValue), def(defValue), prob(probValue), r_hp(rewardHp), r_atk(rewardAtk), r_def(rewardDef) {
        setName(newName);
    }

    int getId() const { return id; }
    void setId(int value) { id = value; }

    const char* getName() const { return name; }
    void setName(const char* newName){
        if(!newName){
            name[0] = '\0';
            return;
        }
        std::strncpy(name, newName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    int getHp() const { return hp; }
    void setHp(int value) { hp = value; }
    void addHp(int delta) { hp += delta; }

    int getAtk() const { return atk; }
    void setAtk(int value) { atk = value; }
    void addAtk(int delta) { atk += delta; }

    int getDef() const { return def; }
    void setDef(int value) { def = value; }
    void addDef(int delta) { def += delta; }

    double getProb() const { return prob; }
    void setProb(double value) { prob = value; }

    int getRewardHp() const { return r_hp; }
    void setRewardHp(int value) { r_hp = value; }
    int getRewardAtk() const { return r_atk; }
    void setRewardAtk(int value) { r_atk = value; }
    int getRewardDef() const { return r_def; }
    void setRewardDef(int value) { r_def = value; }
private:
    int id;
    char name[32];
    int hp;
    int atk;
    int def;
    double prob;
    int r_hp; // Rencompensas al heroe al ganar de hp
    int r_atk; // Rencompensas al heroe al ganar de atk
    int r_def; // Rencompensas al heroe al ganar de def
};

#endif
