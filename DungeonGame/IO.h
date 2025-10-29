#ifndef IO_H
#define IO_H
#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Node.h"
#include "Monster.h"

// Cargamos la dungeon desde el archivo
bool loadDungeon(const char* path, Graph<int>& G, int& startId, int& treasureId, int& firstNodeRead);
// Cargamos montruos desde archivo
bool loadMonsters(const char* path, Monster* monsters, int& nMonsters, int maxMonsters);

#endif