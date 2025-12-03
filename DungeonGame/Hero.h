#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <cstring>

class Hero{
public:
    Hero(): name{0}, hp(0), atk(0), def(0), pos(-1) {}
    Hero(const char* newName, int hpValue, int atkValue, int defValue, int posValue): name{0}, hp(hpValue), atk(atkValue), def(defValue), pos(posValue) {
        setName(newName);
    }

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

    int getPos() const { return pos; }
    void setPos(int value) { pos = value; }

    bool alive() const { return hp > 0; }
private:
    char name[32];
    int hp;
    int atk;
    int def;
    int pos; // es el id de donde se encuentre
};

#endif
