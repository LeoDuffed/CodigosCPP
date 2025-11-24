#include <iostream>
#include "Game.h"
using namespace std;

int main(){
    cout<<"Introduce palabra secreta o presiona ENTER para jugar: ";
    string clave;
    getline(cin, clave);
    bool cheat = (clave == "cheatPath");
    Game game(65); 
    if(!game.init("data/dungeon.txt", "data/monsters.txt")){
        cout << "Error: no se pudo inicializar el juego." << endl;
        return 1;
    }
    game.run(cheat);
    cout << "\nGracias por jugar.\n";
    return 0;
}

/* ToDo
    - Ponerle pesos a cambiar de nodo (camino con menos probabilidad de encuentro)
                ----- EXTRA -----
    - Agregar abilidades al heroe (puntos extras)
    - Guardar partida (puntos extras)
*/
