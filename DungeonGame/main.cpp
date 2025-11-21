#include <iostream>
#include "Game.h"
using namespace std;

int main(){
    cout<<"Introduce palabra secreta o presiona ENTER para jugar: ";
    string clave;
    getline(cin, clave);
    bool cheat = (clave == "cheatPath");
    Game game(64); // capacidad máxima de vértices = 64
    if(!game.init("data/dungeon.txt", "data/monsters.txt")){
        cout << "Error: no se pudo inicializar el juego." << endl;
        return 1;
    }
    game.run(cheat);
    cout << "\nGracias por jugar.\n";
    return 0;
}


/* Cosas que implementar

    - Maybe despues de meter el cheat code, poder jugar
    - Agregar abilidades al heroe
    - Guardar partida
    - Que se disfruten mas las batallas
*/
