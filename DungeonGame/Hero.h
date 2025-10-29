#ifndef HERO_H
#define HERO_H
#include <iostream>

struct Hero{
    char name[32];
    int hp;
    int atk;
    int def;
    int pos; // es el id de donde se encuentre;
    bool alive() const { return hp > 0; }
};

#endif