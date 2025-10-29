#include "IO.h"

bool loadDungeon(const char* path, Graph<int>& G, int& startId, int& treasureId, int& firstNodeRead){
    startId = -1;
    treasureId = -1;
    firstNodeRead = -1;

    ifstream in(path);;
    if(!in.is_open()){
        
    }
}