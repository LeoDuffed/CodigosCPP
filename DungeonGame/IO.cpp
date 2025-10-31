// Implementación de lectura/escritura del mapa y monstruos.
// Nota: Se usa únicamente iostream/fstream y C-strings, manteniendo el estilo del proyecto.
#include "IO.h"

bool loadDungeon(const char* path, Graph<int>& G, int& startId, int& treasureId, int& firstNodeRead){
    // Valores por defecto (inicializamos como inválidos)
    startId = -1;
    treasureId = -1;
    firstNodeRead = -1;

    // Abrimos el archivo de dungeon
    std::ifstream in(path);
    if(!in.is_open()){
        std::cout<<"No se pudo abrir "<<path<<"\n";
        return false;
    }

    // Arreglo temporal para leer etiquetas como NODES/START/TREASURE/EDGES
    char characters[32];
    int N = 0; // Cantidad de nodos a leer
    int A = 0; // Cantidad de aristas a leer

    // 1) Leemos la cabecera de NODES
    in >> characters;     // Esperado: "NODES" (no validamos literal para mantener flexibilidad original)
    in >> N;              // Cantidad de nodos
    if(!in || characters[0] == '\0' || N <= 0){
        std::cout<<"Formato invalido o Nodos faltantes\n";
        return false;
    }

    // 2) Leemos los N nodos: id name prob
    for (int i = 0; i < N; i++){
        int id;
        char name[64];
        double prob;
        in >> id;         // id del nodo
        in >> name;       // nombre SIN espacios (diseño del archivo)
        in >> prob;       // probabilidad de encuentro [0,1]
        if(!in){
            std::cout<<"Error leyendo el nodo "<<i<<"\n";
            return false;
        }
        if(firstNodeRead < 0) firstNodeRead = id;  // Guardamos el primero por si falta START
        if(!G.addCorners(id, name, prob, 0)){      // Insertamos el vértice en el grafo
            std::cout<<"No se pudo agregar el nodo con el id "<<id<<"\n";
            return false;
        }
    }

    // 3) Leemos etiquetas START / TREASURE en cualquier orden, hasta encontrar EDGES
    bool gotEdges = false;  // bandera de control para saber cuándo parar
    while(true){
        in >> characters;        // Leemos la etiqueta siguiente (START/TREASURE/EDGES)
        if(!in){
            std::cout<<"Faltan etiquetas despues de los nodos\n";
            return false;
        }
        if(characters[0] == '\0'){
            std::cout<<"Etiqueta vacia despues de los nodos\n";
            return false;
        }

        if(characters[0] == 'S'){   // START X
            in >> startId;          // id de inicio
            if(!in){
                std::cout<<"Start invalido\n";
                return false;
            }
            continue;               // seguimos leyendo más etiquetas
        }

        if(characters[0] == 'T'){   // TREASURE X
            in >> treasureId;       // id del tesoro
            if(!in || treasureId < 0){
                std::cout<<"Tesoro invalido\n";
                return false;
            }
            continue;               // seguimos leyendo más etiquetas
        }

        if(characters[0] == 'E'){   // EDGES A
            in >> A;                // cantidad de aristas
            if(!in || A < 0){
                std::cout<<"Faltan o formato incorrecto de edges\n";
                return false;
            }
            gotEdges = true;        // ya podemos pasar a leer las aristas
            break;
        }

        // Si llegamos aquí, se leyó una etiqueta desconocida
        std::cout<<"Etiqueta desconocida: "<<characters<<"\n";
        return false;
    }

    // 4) Leemos las A aristas: pares "a b" (grafo no dirigido)
    if(!gotEdges){
        std::cout<<"No se encontro EDGES\n";
        return false;
    }
    for(int i = 0; i < A; i++){
        int a, b;
        in >> a >> b;              // leemos el par de ids vecinos
        if(!in){
            std::cout<<"Error leyendo arista "<<i<<"\n";
            return false;
        }
        if(!G.addEdges(a,b)){      // agregamos arista en ambos sentidos
            std::cout<<"No se pudo agregar la arita "<<a<<" - "<<b<<"\n";
            return false;
        }
    }
    return true;                    // carga exitosa del mapa
}

bool loadMonsters(const char* path, Monster* monster, int& nMonsters, int maxMonsters){
    // Inicializamos el conteo
    nMonsters = 0;

    // Abrimos archivo de monstruos
    std::ifstream in(path);
    if(!in.is_open()){
        std::cout<<"No se pudo abrir "<<path<<"\n";
        return false;
    }

    // Helper local para comentarios (misma lógica que en loadDungeon)
    auto skipComments = [&in](){
        while(true){
            in >> std::ws;               // consumir espacios/saltos
            int c = in.peek();
            if(c == '#'){
                char dump[512];
                in.getline(dump, sizeof(dump));
                continue;
            }
            break;
        }
    };

    char characters[32];
    int M = 0;  // cantidad de monstruos a leer

    // 1) Cabecera: MONSTERS M
    in >> characters;   // etiqueta (no validamos literal para mantener estilo original)
    in >> M;            // cantidad
    if(!in || M <= 0){
        std::cout<<"Formato invalido o monstruos faltantes\n";
        return false;
    }
    if(M > maxMonsters){
        std::cout<<"Maximos de monstruos "<<maxMonsters<<"\n";
        return false;
    }

    // 2) Leemos M monstruos: id name hp atk def prob r_hp r_atk r_def
    for(int i = 0; i < M; i++){
        Monster m;
        in >> m.id        // id
           >> m.name      // nombre (sin espacios)
           >> m.hp        // vida
           >> m.atk       // ataque
           >> m.def       // defensa
           >> m.prob      // probabilidad de aparición
           >> m.r_hp      // recompensa hp
           >> m.r_atk     // recompensa atk
           >> m.r_def;    // recompensa def
        if(!in){
            std::cout<<"Error leyendo monstuio "<<i<<"\n";
            return false;
        }
        monster[nMonsters++] = m; // guardamos en el arreglo provisto
    }
    return true;  // carga exitosa de monstruos
}
