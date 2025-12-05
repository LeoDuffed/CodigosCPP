#include <iostream>
#include "Game.h"
using namespace std;

int main(){
    cout<<"Introduce palabra secreta o presiona ENTER para jugar: ";
    string clave;
    getline(cin, clave);
    bool cheat = (clave == "mysticpath"); 
    Game game(65); 
    if(!game.init("data/dungeon.txt", "data/monsters.txt")){
        cout << "Error: no se pudo inicializar el juego." << endl;
        return 1;
    }
    game.run(cheat);
    cout << "\nGracias por jugar.\n";
    return 0;
}
    