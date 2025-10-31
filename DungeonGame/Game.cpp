#include "Game.h"
#include "IO.h"
#include "Node.h"

Game::Game(int maxCorners): graph(maxCorners), startId(-1), treasureId(-1), nMonsters(0){
    // Con esta linea es "completamente" randon rand() 
    srand((unsigned)time(nullptr));
    // Hero por defecto
    hero.name[0] = 'D';
    hero.name[1] = 'U';
    hero.name[2] = 'F';
    hero.name[3] = 'F';
    hero.name[4] = '\0';
    hero.hp = 20;
    hero.atk = 5;
    hero.def = 2;
    hero.pos = -1;
}

bool Game::init(const char* dungeonFile, const char* monsterFile){
    // Cargamos el grafo y los parametros start y treause
    int firstNodeRead = -1;
    if(!loadDungeon(dungeonFile, graph, startId, treasureId, firstNodeRead)){
        std::cout<<"Error cargando al mapa\n";
        return false;
    }
    if(startId < 0) startId = firstNodeRead; // si no hubo START, usamos el primer leido
    if(startId < 0 || treasureId < 0){
        std::cout<<"Id's de inicio o tesoro invalido\n";
        return false;
    }
    hero.pos = startId;
    // Cargamos montruos
    if(!loadMonsters(monsterFile, monster, nMonsters, MAX_MONSTERS)){
        std::cout<<"Error cargando montruos\n";
        return false;
    }
    if(nMonsters <= 0){
        std::cout<<"No hay montruos disponibles\n";
        return false;
    }
    return true;
}

void Game::run(bool cheatBFS){
    if(cheatBFS){
        showCheatPath();
        return;
    }
    explorationLoop();
}

void Game::showCheatPath() const{
    std::cout<<"Cheat path: ";
    graph.printCheatBFS(startId, treasureId);
}

bool Game::encounterProb(int roomID){
    Node<int>* n = graph.search(roomID);
    if(!n) return false;
    if(n->isVisited()) return false;
    // Probabilidad de encuentro del 0 al 1
    double u = (double)rand()/(double)RAND_MAX;
    if(u < n->getEncounterProb()){
        return true;
    }
    return false;
}

Monster Game::chooseMonster() const{
    double total = 0.0;
    for(int i = 0; i < nMonsters; i++) total += monster[i].prob;
    if(total <= 0.0){
        // fallback
        return monster[0];
    }
    double u = ((double)rand()/(double)RAND_MAX)*total;
    for(int i = 0; i < nMonsters; i++){
        if(u <= monster[i].prob) return monster[i];
        u -= monster[i].prob;
    }
    return monster[nMonsters-1];
}

bool Game::combat(Monster m){
    std::cout<<"Aparecio "<<m.name<<"! (HP= "<<m.hp<<", ATK= "<<m.atk<<", DEF= "<<m.def<<")\n";
    bool heroTurn = true;

    while(hero.alive() && m.hp > 0){
        if(heroTurn){
            int dmg = hero.atk - m.def;
            if(dmg < 1) dmg = 1;
            m.hp -= dmg;
            std::cout<<hero.name<<" golpea "<<dmg<<" -> HP de "<<m.name<<" "<<m.hp<<"\n";
        } else {
            int dmg = m.atk - hero.def;
            if(dmg < 1) dmg = 1;
            hero.hp -= dmg;
            std::cout<<m.name<<" golpea "<<dmg<<" -> HP de "<<hero.name<<" "<<hero.hp<<"\n";
        }
        heroTurn = !heroTurn;
    }
    if(hero.alive()){
        std::cout<<hero.name<<" vencio a "<<m.name<<"!\n";
        hero.hp += m.r_hp;
        hero.atk += m.r_atk;
        hero.def += m.r_def;
        std::cout<<"Sube stats: +"<<m.r_hp<<" HP +"<<m.r_atk<<" ATK +"<<m.r_def<<" DEF\n";
        std::cout<<"Nuevas stats: "<<hero.hp<<" HP, "<<hero.atk<<" ATK, "<<hero.def<<" DEF!\n";
        return true;
    } else {
        std::cout<<hero.name<<" ha sido vencido, GG\n";
        return false;
    }
}

void Game::showNeighbors(int id) const {
    const Node<int>* n = graph.search(id);
    if(!n) return;
    std::cout<<"Vecinos disponibles: \n";
    const int* vs = n->getNeighbor();
    int k = n->getNeighborNum();
    for(int i = 0; i < k; i++){
        int v = vs[i];
        const Node<int>* nv = graph.search(v);
        if(nv){
            std::cout<<" ["<<v<<"] "<<nv->getName()<<"\n";
        } else {
            std::cout<<" ["<<v<<"] (desconocido)\n";
        }
    }
}

void Game::explorationLoop(){
    while(hero.alive()){
        if(hero.pos == treasureId){
            std::cout<<"!Llegaste al tesoro!!!\n";
            return;
        }
        Node<int>* section = graph.search(hero.pos);
        std::cout<<"\nEstas en: ["<<hero.pos<<"] "<<(section ? section->getName() : "(?)")<<"\n";
        // Si no ha visitado la casilla, hay posibilidad de que se tope con un monstruo
        bool wasVisited = (section ? section->isVisited() : false);
        if(!wasVisited && encounterProb(hero.pos)){
            Monster m = chooseMonster();
            if(!combat(m)){
                return; // murio el heroe
            }
        }
        if(section && !wasVisited){
            section->setVisited(true);
        }
        // Mostramos a los vecinos para ver a donde se puede mover
        showNeighbors(hero.pos);
        std::cout<<"Elige a donde moverte: ";
        int nxt;
        std::cin>>nxt;
        // Validamos que exista el id que ingresaron
        bool ok = false;
        if(section){
            const int* vs = section->getNeighbor();
            int k = section->getNeighborNum();
            for(int i = 0; i < k; i++){
                if(vs[i] == nxt){
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            std::cout<<"Movimiento invalido\n";
            continue;
        }
        hero.pos = nxt;
    }
}
