#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Hero.h"
#include "Graph.h"
#include "Monster.h"

class Game{
    public:
        enum {MAX_MONSTERS = 64};
        Game(int maxNodes = 64);
        // Se inicializa con archivos, si falla I/O o los datos son invalidos da false
        bool init(const char* dungeonFile, const char* monsterFile);
        // Funcion para ejecutar el juego, si cheatBFS = true se muestra el cheat path
        void run(bool cheatBFS);
    private:
        Graph<int> graph;
        int startId;
        int treasureId;
        Hero hero;
        Monster monster[MAX_MONSTERS];
        int nMonsters;
        // funcion para la probabilidad de encuentro si la sala no se ha visitado
        bool encounterProb(int roomId);
        // funcion para elegir un montruo
        Monster chooseMonster() const;
        // combates por turnos, si gana el hero = true
        bool combat(Monster m);
        // Para ver vecinos disponibles
        void showNeighbors(int id) const;
        // funcion de exploracion manual
        void explorationLoop();
        // Funcion para mostrar el chear path
        void showCheatPath() const;
        // Helpers
        static int max2i(int a, int b) { return (a > b) ? a : b; }
};

#endif