#pragma once
#include "NeighborNode.h"

template <typename T>
NeighborNode<T>::NeighborNode(const T& v): data(v), next(nullptr){}
