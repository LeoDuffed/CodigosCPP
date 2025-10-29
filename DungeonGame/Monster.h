#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>

struct Monster{
    int id;
    char name[32];
    int hp;
    int atk;
    int def;
    double prob;
    int r_hp; // Rencompensas al heroe al ganar de hp
    int t_atk; // Rencompensas al heroe al ganar de atk
    int r_def; // Rencompensas al heroe al ganar de def
};

#endif