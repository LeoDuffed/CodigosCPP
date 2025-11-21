#ifndef NODE_H
#define NODE_H
#include "LinkedList.h"

template<typename T>
class Node{
    private:
        int id;
        char name[64];
        double encounterProb;
        bool visited;
        LinkedList<int> neighbors;
        T extra;
    public:
        Node();
        Node(int id, const char* name, double prob, const T& extra = T{});
        ~Node() = default;
        // Getters
        int getId() const;
        const char* getName() const;
        double getEncounterProb() const;
        bool isVisited() const;
        int getNeighborNum() const;
        const LinkedList<int>& getNeighbors() const;
        LinkedList<int>& getNeighbors();
        // Setters
        void setId(int id);
        void setName(const char* name);
        void setEncounterProb(double prob);
        void setVisited(bool visited);
        // Aristas
        void addNeighbor(int neighborId);
        bool hasNeighbor(int neighborId) const;
};

#include "Node.tpp"

#endif
