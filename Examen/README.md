# 🧮 Proyecto: Operaciones con Números Complejos en C++

Este proyecto consiste en una aplicación en C++ que permite **crear números complejos**, **realizar operaciones de suma y resta entre ellos**, y **guardar hasta seis números complejos en un arreglo**, además de calcular la **resta total de todos los números almacenados**.

## 📁 Estructura del Proyecto

- `NumComplejo.h` / `NumComplejos.cpp`  
  Contiene la clase `NumComplejo`, que representa un número complejo en forma `a + bi`. Incluye funciones para establecer y obtener los valores reales e imaginarios, realizar suma y resta de números complejos, y mostrar el número en consola.

- `ArregloComplejos.h` / `ArregloComplejos.cpp`  
  Contiene la clase `ArregloComplejos`, que permite almacenar hasta seis objetos `NumComplejo` en un arreglo. Incluye funciones para agregar nuevos números complejos, mostrar todos los almacenados y calcular la **resta acumulada** de todos ellos.

- `main.cpp`  
  Punto de entrada del programa. Genera automáticamente 10 números complejos, los intenta agregar al arreglo y muestra el resultado de la resta total.

## ⚙️ Funcionalidad principal

1. Crea un arreglo para guardar hasta 6 números complejos.
2. Intenta agregar 10 números complejos con valores secuenciales (`(1 + 2i)`, `(2 + 3i)`, ..., `(10 + 11i)`).
3. Muestra un mensaje si no se pudo agregar un número (por estar lleno el arreglo).
4. Calcula y muestra la **resta total** de todos los números complejos almacenados.
5. Muestra todos los números complejos que fueron almacenados.

## 🖨️ Salida del Programa

Al ejecutar el programa actual, esta es la salida esperada en consola:

```
El arreglo esta lleno
No se pudo agregar: 7 + 8i
El arreglo esta lleno
No se pudo agregar: 8 + 9i
El arreglo esta lleno
No se pudo agregar: 9 + 10i
El arreglo esta lleno
No se pudo agregar: 10 + 11i
La resta total de los complejos en el arreglo es: -20 - 25i
```

Esta salida muestra cómo se llenan los primeros seis espacios del arreglo y cómo se gestiona el intento de insertar más elementos. Finalmente, se muestra el resultado de la resta acumulada de los números almacenados.

## 🛠️ Cómo compilar y ejecutar (en macOS o Linux)

1. Abre la terminal en la carpeta del proyecto.
2. Compila con `g++`:

```bash
g++ -std=c++17 -o complejos main.cpp NumComplejos.cpp ArregloComplejos.cpp
```

3. Ejecuta el programa:

```bash
./complejos
```

## 📦 Clases implementadas

### `NumComplejo`

- `NumComplejo()` – Constructor por defecto (1 + 1i)
- `NumComplejo(int a, int b)` – Constructor con parámetros
- `setA()`, `setB()` – Setters
- `getA()`, `getB()` – Getters
- `imprimir()` – Muestra el número complejo en consola
- `suma(a2, b2)` – Devuelve un nuevo número complejo con la suma
- `resta(a2, b2)` – Devuelve un nuevo número complejo con la resta

### `ArregloComplejos`

- `agregar(NumComplejo)` – Agrega un nuevo número complejo al arreglo
- `restaTotal()` – Retorna la resta total acumulada de los números almacenados
- `mostrarArray()` – Muestra todos los números complejos guardados

## 💡 Consideraciones

- El arreglo tiene una capacidad máxima de 6 números complejos.
- Si intentas agregar más de 6, el programa avisa que el arreglo está lleno.
- La resta total se calcula acumulando las restas entre los elementos agregados (comenzando desde el primer elemento).

## 👨‍💻 Autor

Leonardo Martínez (con ayuda de ChatGPT 😊)
