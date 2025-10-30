#include "IO.h"

bool loadDungeon(const char* path, Graph<int>& G, int& startId, int& treasureId, int& firstNodeRead){
    startId = -1;
    treasureId = -1;
    firstNodeRead = -1;

    std::ifstream in(path);
    if(!in.is_open()){
        std::cout<<"No se pudo abrir "<<path<<"\n";
        return false;
    }
    char characters[32]; // es donde se guardan las palabras del archivo (las salas)
    int N = 0; // Cantidad de nodos que va a haber
    int A = 0; // Cantidad de aristas que va a haber

    // Buscar Nodes
    in >> characters >> N;
    if(!in || characters[0] == '\0' || N <= 0){
        std::cout<<"Formato invalido o Nodos faltantes\n";
        return false;
    }
    // Leemos los n nodos
    for (int i = 0; i < N; i++){
        int id;
        char name[64];
        double prob;
        in >> id >> name >> prob;
        if(!in){
            std::cout<<"Error leyendo el nodo "<<i<<"\n";
            return false;
        }
        if(firstNodeRead < 0) firstNodeRead = id;
        if(!G.addCorners(id, name, prob, 0)){
            std::cout<<"No se pudo agregar el nodo con el id "<<id<<"\n";
            return false;
        }
    }
    // Leemos la linea con TREASURE
    in>>characters>>treasureId;
    if(!in || characters[0] == '\0'){
        std::cout<<"Falta el tesoro, gg\n";
        return false;
    }
    if(treasureId < 0){
        std::cout<<"El tesoro es invalido\n";
        return false;   
    }

    // _____________________________________
    // Hay que revisar esta parte del codigo

    std::streampos pos = in.tellg();
    in>>characters;
    if(!in){
        std::cout<<"Falta edges\n";
        return false;
    }
    if(characters[0] == 'S'){ // asumimos que es START
        in>>startId;
        if(!in){
            std::cout<<"Start invlaido\n";
            return false;
        }
        // Cnbase al .txt el siguiente deberia de ser EDGES
        in>>characters>>A; // A = edges = aristas
        if(!in || characters[0] == '\0' || A < 0){
            std::cout<<"Faltan o formato incorrecto de edges\n";
            return false;
        }
    } else { // Si no hay Start, entonces deberia de ser Edges (conbase al formato del .txt)
        in.seekg(pos);
        in>>characters>>A;
        if(!in || characters[0] == '\0' || A < 0){
            std::cout<<"Falta o formato incorrecto de edges 2\n"; // Le puse dos para el debug
            return false;
        }
    }
    // _____________________________________

    // Leer A (aristas)
    for(int i = 0; i < A; i++){
        int a, b;
        in>>a>>b;
        if(!in){
            std::cout<<"Error leyendo arista "<<i<<"\n";
            return false;
        }
        if(!G.addEdges(a,b)){
            std::cout<<"No se pudo agregar la arita "<<a<<" - "<<b<<"\n";
            return false;
        }
    }
    return true;
}

bool loadMonsters(const char* path, Monster* monster, int& nMonsters, int maxMonsters){
    nMonsters = 0;
    std::ifstream in(path);
    if(!in.is_open()){
        std::cout<<"No se pudo abrir "<<path<<"\n";
        return false;
    }
    char characters[32];
    int M = 0;
    in>>characters>>M; 
    if(!in || M <= 0){
        std::cout<<"Formato invalido o monstruos faltantes\n";
        return false;
    }
    if(M > maxMonsters){
        std::cout<<"Maximos de monstruos "<<maxMonsters<<"\n";
        return false;
    }
    for(int i = 0; i < M; i++){
        Monster m;
        in>>m.id>>m.name>>m.hp>>m.atk>>m.def>>m.prob>>m.r_hp>>m.r_atk>>m.r_def;
        if(!in){
            std::cout<<"Error leyendo monstuio "<<i<<"\n";
            return false;
        }
        monster[nMonsters++] = m;
    }
    return true;
}
