#pragma once
#include <iostream>
#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

template <typename T>
int Graph<T>::indexOf(const T& v) const {
    for (int i = 0; i < count; i++) {
        if(vertices[i] == v) {
            return i;
        }
    }
    
    return -1;
}

template<typename T>
bool Graph<T>::addVertex(const T& v) {
    // Si llego al limite no puedo meter más
    if (count >= n) {
        return false;
    }

    // Ya existe
    if(indexOf(v) != -1) {
        return false;
    }

    vertices[count] = v;
    count++;

    return true;
}

template<typename T>
bool Graph<T>::addEdge(const T& v, const T& u, int weight, bool directed) {

    int iu = indexOf(u);
    int iv = indexOf(v);

    if(iu == -1 || iv == -1) return false;

    matrix[iu][iv] = weight;
    if(!directed) {
        matrix[iv][iu] = weight;
    }

    return true;
}

template<typename T>
void Graph<T>::printMatrix() const {
    cout << "\n------- MATRIX -------" << endl;

    cout << " \t\t";
    for (int i = 0; i < count; i++) {
        cout << vertices[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < count; i++) {
        cout << vertices[i] << "\t\t";
        for (int j = 0; j < count; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

template<typename T>
void Graph<T>::resetVisited(){
    for(int i = 0; i < count; i++){
        visited[i] = false;
    }
}

template<typename T>
void Graph<T>::BFS(const T& start){
    int startIndex = indexOf(start);
    if(startIndex == - 1){
        cout<<"Nodo inicial no encontrado"<<endl;
        return;
    }
    resetVisited();
    Queue<int> q;
    visited[startIndex] = true;
    q.enQueue(startIndex);
    while(!q.isEmpty()){
        int index = q.deQueue();
        cout<<vertices[index]<<"->";
        for(int neiIndex = 0; neiIndex < count; neiIndex++){
            if(matrix[index][neiIndex] != 0 && !visited[neiIndex]){
                visited[neiIndex] = true;
                q.enQueue(neiIndex);
            }
        }
    }
    cout<<""<<endl;
}

template<typename T>
void Graph<T>::DFS(const T& start){
    int startIndex = indexOf(start);
    if(startIndex == - 1){
        cout<<"Nodo inicial no encontrado"<<endl;
        return;
    }
    resetVisited();
    Stack<int> s;
    visited[startIndex] = true;
    s.push(startIndex);
    while(!s.isEmpty()){
        int index = s.pop();
        cout<<vertices[index]<<"->";
        for(int neiIndex = 0; neiIndex < count; neiIndex++){
            if(matrix[index][neiIndex] != 0 && !visited[neiIndex]){
                visited[neiIndex] = true;
                s.push(neiIndex);
            }
        }
    }
    cout<<""<<endl;
}

