# 🧮 Proyecto: Suma de Matrices de Fracciones en C++

Este proyecto consiste en una aplicación en C++ que permite **leer dos matrices de fracciones desde archivos**, **sumarlas si tienen las mismas dimensiones** y **guardar el resultado en un nuevo archivo**.

## 📁 Estructura del Proyecto

- `Fracciones.h` / `Fracciones.cpp`  
  Contiene la clase `Fracciones`, que representa una fracción con numerador y denominador. Incluye funciones para operaciones básicas (suma, resta, multiplicación y división), simplificación y visualización.

- `MatFrac.h` / `MatFrac.cpp`  
  Contiene la clase `MatFrac`, que representa una matriz de objetos `Fracciones`. Incluye funciones para leer una matriz desde archivo, sumarla con otra matriz y guardar la matriz resultante.

- `main.cpp`  
  Punto de entrada del programa. Coordina la lectura de las matrices, realiza la suma y guarda los resultados.

## 📥 Formato de Archivos de Entrada

Cada archivo de matriz debe tener el siguiente formato:

```
<filas> <columnas>
<num1> <den1> <num2> <den2> ...
<num3> <den3> <num4> <den4> ...
```

Ejemplo (`matriz1.txt` y `matriz2.txt`):

```
2 2
1 2 3 4
5 6 7 8
```

Este ejemplo representa la matriz:

```
[1/2   3/4]
[5/6   7/8]
```

## 🛠️ Cómo Compilar y Ejecutar

1. Compila el proyecto (puedes usar `g++`):

```bash
g++ -o sumaMatrices main.cpp MatFrac.cpp Fracciones.cpp
```

2. Ejecuta el programa y proporciona los nombres de archivo cuando se te solicite:

```bash
./sumaMatrices
```

3. El programa mostrará las dos matrices y su suma. Luego te pedirá un nombre de archivo para guardar la matriz resultado.

## 💡 Mensajes de Validación

- Si las matrices tienen diferentes dimensiones:
```
Operación imposible. Las matrices deben ser de las mismas dimensiones para poder sumarlas
```

- Si los archivos no se pueden leer:
```
No se pudo leer el archivo
```

## 📌 Ejemplo de Ejecución

```
Matriz 1:
1/2 3/4
5/6 7/8
+
Matriz 2:
1/2 1/4
1/6 1/8
=
Matriz resultado:
1/1 1/1
1/1 1/1
Nombre del archivo para guardar la matriz resultado: resultado.txt
```

## 👨‍💻 Autor

Leonardo (con ayuda de ChatGPT 😊)