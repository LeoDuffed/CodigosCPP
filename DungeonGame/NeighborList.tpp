#pragma once
#include "NeighborList.h"

template <typename T>
NeighborList<T>::NeighborList(const T& v): data(v), next(nullptr){}
