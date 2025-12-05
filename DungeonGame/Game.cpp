#include "Game.h"
#include "IO.h"
#include "Node.h"
#include "NeighborList.h"
#include <fstream>
#include <string>
#include <cstdlib>

Game::Game(int maxNodes): graph(maxNodes), startId(-1), treasureId(-1), nMonsters(0){
    // Con esta linea es "completamente" randon rand() 
    srand((unsigned)time(nullptr));
    // Hero por defecto
    hero.setName("DUFF");
    hero.setHp(30);
    hero.setAtk(5);
    hero.setDef(2);
    hero.setPos(-1);
}

bool Game::init(const char* dungeonFile, const char* monsterFile){
    // Cargamos el grafo y los parametros start y treause
    int firstNodeRead = -1;
    if(!loadDungeon(dungeonFile, graph, startId, treasureId, firstNodeRead)){
        std::cout<<"Error cargando al mapa\n";
        return false;
    }
    hero.setPos(startId);
    // Cargamos montruos
    if(!loadMonsters(monsterFile, monster, nMonsters, MAX_MONSTERS)){
        std::cout<<"Error cargando montruos\n";
        return false;
    }
    return true;
}

void Game::run(bool cheatBFS){
    std::cout<<"¿Cargar partida desde save.txt? (s/n): ";
    char loadOpt;
    std::cin>>loadOpt;
    std::cin.ignore(10000, '\n');
    if(loadOpt == 's' || loadOpt == 'S'){
        if(loadGame("save.txt")){
            std::cout<<"Partida cargada.\n";
        } else {
            std::cout<<"No se pudo cargar la partida, se inicia una nueva.\n";
            hero.setPos(startId);
        }
    }
    if(cheatBFS){
        showCheatPath();
    }
    explorationLoop();
}

void Game::showCheatPath() const{
    std::cout<<"La ruta mas segura: ";
    graph.printCheatDijstrak(startId, treasureId);
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
    for(int i = 0; i < nMonsters; i++) total += monster[i].getProb();
    if(total <= 0.0){
        // fallback
        return monster[0];
    }
    double u = ((double)rand()/(double)RAND_MAX)*total;
    for(int i = 0; i < nMonsters; i++){
        if(u <= monster[i].getProb()) return monster[i];
        u -= monster[i].getProb();
    }
    return monster[nMonsters-1];
}

bool Game::saveGame(const char* path) const{
    std::ofstream out(path);
    if(!out.is_open()){
        std::cout<<"No se pudo abrir "<<path<<" para guardar\n";
        return false;
    }
    out<<"HERO "<<hero.getName()<<" "<<hero.getHp()<<" "<<hero.getAtk()<<" "<<hero.getDef()<<" "<<hero.getPos()<<"\n";
    int cap = graph.maxCapability();
    int visitedCount = 0;
    for(int i = 0; i < cap; i++){
        const Node<int>* n = graph.search(i);
        if(n && n->isVisited()){
            ++visitedCount;
        }
    }
    out<<"VISITED "<<visitedCount;
    for(int i = 0; i < cap; i++){
        const Node<int>* n = graph.search(i);
        if(n && n->isVisited()){
            out<<" "<<i;
        }
    }
    out<<"\n";
    if(!out){
        std::cout<<"Error escribiendo el archivo de guardado\n";
        return false;
    }
    std::cout<<"Partida guardada en "<<path<<"\n";
    return true;
}

bool Game::loadGame(const char* path){
    std::ifstream in(path);
    if(!in.is_open()){
        std::cout<<"No se pudo abrir "<<path<<" para cargar\n";
        return false;
    }
    std::string tag;
    in>>tag;
    if(tag != "HERO"){
        std::cout<<"Formato de guardado invalido (falta HERO)\n";
        return false;
    }
    std::string name;
    int hp, atk, def, pos;
    in>>name>>hp>>atk>>def>>pos;
    if(!in){
        std::cout<<"Datos de HERO incompletos\n";
        return false;
    }
    int cap = graph.maxCapability();
    for(int i = 0; i < cap; i++){
        Node<int>* n = graph.search(i);
        if(n) n->setVisited(false);
    }
    in>>tag;
    if(tag != "VISITED"){
        std::cout<<"Formato de guardado invalido (falta VISITED)\n";
        return false;
    }
    int cnt;
    in>>cnt;
    if(!in || cnt < 0){
        std::cout<<"Cantidad de visitados invalida\n";
        return false;
    }
    for(int i = 0; i < cnt; i++){
        int id;
        in>>id;
        if(!in){
            std::cout<<"Error leyendo id visitado\n";
            return false;
        }
        Node<int>* n = graph.search(id);
        if(!n){
            std::cout<<"Id visitado "<<id<<" no existe en el grafo\n";
            return false;
        }
        n->setVisited(true);
    }
    if(pos < 0 || pos >= cap || !graph.search(pos)){
        std::cout<<"Posicion del heroe invalida en guardado\n";
        return false;
    }
    hero.setName(name.c_str());
    hero.setHp(hp);
    hero.setAtk(atk);
    hero.setDef(def);
    hero.setPos(pos);
    std::cout<<"Guardado cargado desde "<<path<<"\n";
    return true;
}

bool Game::combat(Monster m){
    std::cout<<"Aparecio "<<m.getName()<<"! (HP= "<<m.getHp()<<", ATK= "<<m.getAtk()<<", DEF= "<<m.getDef()<<")\n";
    bool heroTurn = true;

    while(hero.alive() && m.getHp() > 0){
        std::cout<<"[Turno de "<<(heroTurn ? hero.getName() : m.getName())<<"] Presiona Enter para continuar...\n";
        std::cin.get();
        if(heroTurn){
            int dmg = hero.getAtk() - m.getDef();
            if(dmg < 1) dmg = 1;
            m.setHp(m.getHp() - dmg);
            std::cout<<hero.getName()<<" golpea "<<dmg<<" -> HP de "<<m.getName()<<" "<<(m.getHp() <= 0 ? 0 : m.getHp())<<"\n";
        } else {
            int dmg = m.getAtk() - hero.getDef();
            if(dmg < 1) dmg = 1;
            hero.setHp(hero.getHp() - dmg);
            std::cout<<m.getName()<<" golpea "<<dmg<<" -> HP de "<<hero.getName()<<" "<<hero.getHp()<<"\n";
        }
        heroTurn = !heroTurn;
    }
    if(hero.alive()){
        std::cout<<hero.getName()<<" vencio a "<<m.getName()<<"!\n";
        hero.addHp(m.getRewardHp());
        hero.addAtk(m.getRewardAtk());
        hero.addDef(m.getRewardDef());
        std::cout<<"\nSube stats: +"<<m.getRewardHp()<<" HP +"<<m.getRewardAtk()<<" ATK +"<<m.getRewardDef()<<" DEF\n";
        std::cout<<"Nuevas stats: "<<hero.getHp()<<" HP, "<<hero.getAtk()<<" ATK, "<<hero.getDef()<<" DEF!\n";
        return true;
    } else {
        std::cout<<hero.getName()<<" ha sido vencido, GG\n";
        return false;
    }
}

void Game::showNeighbors(int id) const {
    const Node<int>* n = graph.search(id);
    if(!n) return;
    std::cout<<"\nVecinos disponibles: \n";
    const LinkedList<int>& nei = n->getNeighbors();
    NeighborList<int>* cur = nei.getHead();
    while(cur){
        int v = cur->data;
        const Node<int>* nv = graph.search(v);
        if(nv){
            std::cout<<" ["<<v<<"] "<<nv->getName()<<"\n";
        } else {
            std::cout<<" ["<<v<<"] (desconocido)\n";
        }
        cur = cur->next;
    }
}

void Game::explorationLoop(){
    while(hero.alive()){
        if(hero.getPos() == treasureId){
            std::cout<<"Llegaste al tesoro!\nNo ganas nada gg.";
            return;
        }
        Node<int>* section = graph.search(hero.getPos());
        std::cout<<"\nEstas en: ["<<hero.getPos()<<"] "<<(section ? section->getName() : "(?)")<<"\n";
        // Si no ha visitado la casilla se podria encontar a un monstruo
        bool wasVisited = (section ? section->isVisited() : false);
        if(!wasVisited && encounterProb(hero.getPos())){
            Monster m = chooseMonster();
            if(!combat(m)){
                return; // murio el heroe (gg)
            }
        }
        if(section && !wasVisited){
            section->setVisited(true);
        }
        // Mostramos a los vecinos para ver a donde se puede mover
        showNeighbors(hero.getPos());
        std::cout<<"Elige a donde moverte (o 'g' para guardar en save.txt): ";
        std::string input;
        std::cin>>input;
        std::cin.ignore(10000, '\n');
        if(input == "g" || input == "G" || input == "save"){
            saveGame("save.txt");
            continue;
        }
        char* end = nullptr;
        long parsed = std::strtol(input.c_str(), &end, 10);
        if(end == input.c_str() || *end != '\0'){
            std::cout<<"Entrada invalida\n";
            continue;
        }
        int nxt = static_cast<int>(parsed);
        // Validamos que exista el id que ingresaron
        bool ok = false;
        if(section){
            const LinkedList<int>& nei = section->getNeighbors();
            NeighborList<int>* cur = nei.getHead();
            while(cur){
                if(cur->data == nxt){
                    ok = true;
                    break;
                }
                cur = cur->next;
            }
        }
        if(!ok){
            std::cout<<"Movimiento invalido\n";
            continue;
        }
        hero.setPos(nxt);
    }
}
