#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>
class Node{
    private:
        int id;
        char name[64];
        double encounterProb;
        bool visited;
        int neighborNum;
        int* neighbors;
        T extra;
    public:
        Node();
        Node(int id, const char* name, double prob, const T& extra = T{});
        ~Node();
        // Getters
        int getId() const;
        const char* getName() const;
        double getEncounterProb() const;
        bool isVisited() const;
        int getNeighborNum() const;
        const int* getNeighbor() const;
        T& getExtra();
        const T& getExtra() const;
        // Setters
        void setId(int id);
        void setName(const char* name);
        void setEncounterProb(double prob);
        void setVisited(bool visited);
        void setExtra(const T& extra);
        // Aristas
        void addNeighbor(int neighborId);
};

#include "Node.tpp";

#endif