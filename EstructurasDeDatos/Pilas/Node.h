#ifndef NODE_H
#define NODE_H

// Cambio: ajustar plantilla Node y definir correctamente el constructor.
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    explicit Node(const T& v) : data(v), next(nullptr) {}
};

#endif
