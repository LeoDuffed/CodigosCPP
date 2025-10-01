
# 🧭 Proyecto: Operaciones con Vectores en ℝ³ en C++

Este proyecto consiste en una aplicación en C++ que permite **crear vectores tridimensionales (x, y, z)**, **realizar operaciones de suma y resta entre ellos**, y **guardar hasta seis vectores en un arreglo**, además de calcular la suma total de todos los vectores almacenados.

## 📁 Estructura del Proyecto

- `Vector.h` / `Vector.cpp`  
  Contiene la clase `Vector`, que representa un vector tridimensional. Incluye funciones para establecer y obtener coordenadas, realizar suma y resta de vectores, y mostrar el vector en consola.

- `ArregloVectores.h` / `ArregloVectores.cpp`  
  Contiene la clase `ArregloVectores`, que permite almacenar hasta seis objetos `Vector` en un arreglo. Incluye funciones para agregar nuevos vectores, mostrar todos los vectores almacenados y calcular la suma total de todos ellos.

- `main.cpp`  
  Punto de entrada del programa. Pide al usuario que ingrese dos vectores, muestra sus operaciones básicas y luego los guarda en un arreglo donde se imprimen y se calcula la suma total.

## ⚙️ Funcionalidad principal

1. Solicita al usuario que ingrese los valores **x, y, z** del primer y segundo vector.
2. Muestra ambos vectores por separado.
3. Calcula y muestra:
   - La **suma** de los dos vectores.
   - La **resta** del primero menos el segundo.
4. Crea un objeto de tipo `ArregloVectores` e inserta los dos vectores.
5. Muestra todos los vectores almacenados en el arreglo.
6. Muestra la suma total de todos los vectores agregados.

## 🧪 Ejemplo de ejecución interactiva

```
Vector 1:
Ingresa el valor de 'x': 1
Ingresa el valor de 'y': 2
Ingresa el valor de 'z': 3
[ 1 , 2 , 3 ]

Vector 2:
Ingresa el valor de 'x': 4
Ingresa el valor de 'y': 5
Ingresa el valor de 'z': 6
[ 4 , 5 , 6 ]

Resultado SUMA:
[ 5 , 7 , 9 ]

Resultado RESTA:
[ -3 , -3 , -3 ]

Vectores en el arreglo:
Vector 1 :
[ 1 , 2 , 3 ]
Vector 2 :
[ 4 , 5 , 6 ]

Suma total de los vectores en el arreglo:
[ 5 , 7 , 9 ]
```

## 🛠️ Cómo compilar y ejecutar (en macOS o Linux)

1. Abre la terminal en la carpeta del proyecto.
2. Compila con `g++`:

```bash
g++ -std=c++17 -o vectores main.cpp Vector.cpp ArregloVectores.cpp
```

3. Ejecuta el programa:

```bash
./vectores
```

## 📦 Clases implementadas

### `Vector`

- `Vector()` – Constructor por defecto (0,0,0)
- `Vector(int x, int y, int z)` – Constructor con parámetros
- `setX()`, `setY()`, `setZ()` – Setters
- `getX()`, `getY()`, `getZ()` – Getters
- `MostrarVec()` – Muestra el vector en consola
- `suma(x, y, z)` – Devuelve un nuevo vector con la suma
- `resta(x, y, z)` – Devuelve un nuevo vector con la resta

### `ArregloVectores`

- `agregarVec(Vector)` – Agrega un nuevo vector al arreglo
- `sumaVectores()` – Retorna la suma total de los vectores almacenados
- `MostrarArreglo()` – Muestra todos los vectores guardados

## 💡 Consideraciones

- El arreglo tiene una capacidad máxima de 6 vectores.
- Si intentas agregar más de 6 vectores, el programa te avisará que el arreglo está lleno.
- La suma total se calcula solo con los vectores almacenados (hasta `vecSave`).

## 👨‍💻 Autor

Leonardo Martínez (con ayuda de ChatGPT 😊)
