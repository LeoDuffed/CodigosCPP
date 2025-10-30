#include <iostream>
#include "Game.h"
using namespace std;

/**
 * main.cpp
 * Juego: Dungeon Crawler
 * ----------------------
 * - Carga el mapa (dungeon.txt) y los monstruos (monsters.txt)
 * - Si al inicio escribes la palabra secreta "mysticpath",
 *   se activa el modo CHEAT BFS, que muestra la ruta más corta.
 * - De lo contrario, se juega normalmente.
 */

int main(){
    cout << "=== Dungeon Crawler ===" << endl;
    cout << "Introduce palabra secreta o presiona ENTER para jugar: ";

    string clave;
    getline(cin, clave);
    bool cheat = (clave == "mysticpath");

    Game game(64); // capacidad máxima de vértices = 64

    if(!game.init("data/dungeon.txt", "data/monsters.txt")){
        cout << "Error: no se pudo inicializar el juego." << endl;
        return 1;
    }

    game.run(cheat);

    cout << "\nGracias por jugar Dungeon Crawler.\n";
    return 0;
}
