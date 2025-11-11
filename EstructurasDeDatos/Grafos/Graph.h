#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
class Graph {
    private:
        int n;
        int count;
        T* vertices;
        int** matrix;
        int indexOf(const T& v) const;

    public:
        Graph(int capacity): n(capacity), count(0){
            vertices = new T[n];
            matrix = new int*[n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
                
            }
        }

        ~Graph() {
            for (int i = 0; i < n; i++ ){
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] vertices;
        }

        bool addVertex(const T& v);
        bool addEdge(const T& v, const T& u, int weight = 1, bool directed = false);

        void primtMatrix () const;
};

#include "Graph.tpp"

#endif 
