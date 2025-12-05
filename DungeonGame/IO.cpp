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

    char characters[32];
    int N = 0; // Cantidad de nodos a leer
    int A = 0; // Cantidad de aristas a leer

    in>>characters; // Nodes
    in>>N; // Cantidad de nodos
    if(!in || characters[0] == '\0' || N <= 0){
        std::cout<<"Formato invalido o Nodos faltantes\n";
        return false;
    }

    // Leemos los N nodos
    for (int i = 0; i < N; i++){
        int id;
        char name[64];
        double prob;
        in>>id;         
        in>>name;       
        in>>prob; // probabilidad de encuentro [0,1]
        if(!in){
            std::cout<<"Error leyendo el nodo "<<i<<"\n";
            return false;
        }
        if(firstNodeRead < 0) firstNodeRead = id; 
        if(!G.addNodes(id, name, prob)){
            std::cout<<"No se pudo agregar el nodo con el id "<<id<<"\n";
            return false;
        }
    }

    // Leemos las etiquetas START / TREASURE / EDGES
    bool gotEdges = false; 
    while(true){
        in>>characters; 
        if(!in){
            std::cout<<"Faltan etiquetas despues de los nodos\n";
            return false;
        }
        if(characters[0] == '\0'){
            std::cout<<"Etiqueta vacia despues de los nodos\n";
            return false;
        }

        if(characters[0] == 'S'){ // START 
            in>>startId; // id de inicio
            if(!in){
                std::cout<<"Start invalido\n";
                return false;
            }
            continue;               
        }

        if(characters[0] == 'T'){ // TREASURE 
            in>>treasureId; // id del tesoro
            if(!in || treasureId < 0){
                std::cout<<"Tesoro invalido\n";
                return false;
            }
            continue;
        }

        if(characters[0] == 'E'){ // EDGES 
            in>>A; 
            if(!in || A < 0){
                std::cout<<"Faltan o formato incorrecto de edges\n";
                return false;
            }
            gotEdges = true; 
            break;
        }

        // se leyó una etiqueta desconocida
        std::cout<<"Etiqueta desconocida: "<<characters<<"\n";
        return false;
    }

    // Leemos las A aristas
    if(!gotEdges){
        std::cout<<"No se encontro EDGES\n";
        return false;
    }
    for(int i = 0; i < A; i++){
        int a, b;
        in>>a>>b; // leemos el par de ids vecinos
        if(!in){
            std::cout<<"Error leyendo arista "<<i<<"\n";
            return false;
        }
        if(!G.addEdges(a,b)){ // agregamos arista en ambos sentidos
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
    int M = 0; // cantidad de monstruos que vamos a leer

    in>>characters;
    in>>M;
    if(!in || M <= 0){
        std::cout<<"Formato invalido o monstruos faltantes\n";
        return false;
    }
    if(M > maxMonsters){
        std::cout<<"Maximos de monstruos "<<maxMonsters<<"\n";
        return false;
    }

    for(int i = 0; i < M; i++){ // Para leer los n montruos
        Monster m;
        int id;
        char name[32];
        int hp;
        int atk;
        int def;
        double prob;
        int r_hp;
        int r_atk;
        int r_def;
        in>>id>>name>>hp>>atk>>def>>prob>>r_hp>>r_atk>>r_def;
        if(!in){
            std::cout<<"Error leyendo monstuio "<<i<<"\n";
            return false;
        }
        m.setId(id);
        m.setName(name);
        m.setHp(hp);
        m.setAtk(atk);
        m.setDef(def);
        m.setProb(prob);
        m.setRewardHp(r_hp);
        m.setRewardAtk(r_atk);
        m.setRewardDef(r_def);
        monster[nMonsters++] = m; 
    }
    return true;  
}
