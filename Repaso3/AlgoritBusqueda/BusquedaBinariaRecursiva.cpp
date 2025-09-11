#include <iostream>

template<std::size_t N>
void IniciarArreglo(int (&array)[N]) {
    for (std::size_t i = 0; i < N; ++i) array[i] = static_cast<int>(i); 
}

template<std::size_t N>
int BusquedaBinaria(const int (&array)[N], int l, int r, int key) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (array[mid] == key) return mid;
    if (array[mid] < key) return BusquedaBinaria(array, mid + 1, r, key);
    return BusquedaBinaria(array, l, mid - 1, key);
}

template<std::size_t N>
void squema(const int (&array)[N], int key) {
    int l = 0, r = static_cast<int>(N) - 1; 
    int pos = BusquedaBinaria(array, l, r, key);
    if (pos != -1)
        std::cout << "Key " << key << " encontrado en índice " << pos << "\n";
    else
        std::cout << "Key " << key << " no encontrado\n";
}

int main() {
    int array[20];
    int key = 7;
    IniciarArreglo(array);
    squema(array, key);
    return 0;
}
