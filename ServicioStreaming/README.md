# 🎬 DUFF Streaming Service – Proyecto Final en C++

## 📌 Descripción general

Este proyecto simula una plataforma de streaming, similar a servicios como Netflix o Prime Video. Permite al usuario cargar datos de películas y series desde archivos `.csv`, visualizarlos, filtrarlos por calificación o género, explorar episodios de series, y calificar videos directamente desde el menú del programa.

El programa está completamente desarrollado en **C++** utilizando **herencia**, **polimorfismo**, **sobrecarga de funciones** y el uso de **structs** para representar episodios. También se emplea manejo de archivos y uso de punteros dinámicos.

---

## 🎯 Objetivos del proyecto

- Aplicar conceptos avanzados de programación orientada a objetos en C++.
- Crear un sistema de gestión de contenido multimedia (películas y series).
- Practicar el manejo de archivos para cargar datos dinámicamente.
- Implementar un menú interactivo para facilitar la navegación del usuario.

---

## 🗂️ Estructura del proyecto

```
📁 Proyecto
│
├── main.cpp              # Archivo principal con el menú del usuario
├── Video.h / Video.cpp   # Clase abstracta base para todos los videos
├── Movies.h / Movies.cpp # Clase derivada para representar películas
├── Serie.h / Serie.cpp   # Clase derivada para representar series
├── Episodio.h            # Struct que representa cada episodio
├── StreamHub.h / StreamHub.cpp # Clase que gestiona el catálogo general de videos
├── db/
│   ├── movies.csv         # Archivo con datos de películas
│   └── series.csv         # Archivo con datos de series y episodios

```

---

## ⚙️ Requisitos del sistema

- Compilador C++ compatible con C++11 o superior (recomendado: `g++`)
- Sistema operativo: Linux, macOS o Windows
- Archivos CSV ubicados en la carpeta `db/` con el formato adecuado

---

## 🔔 Importante: 

Antes de utilizar cualquiera de las funciones del programa, es necesario cargar los datos desde los archivos movies.csv y series.csv seleccionando la opción 1 del menú.
Esto permitirá que el sistema tenga acceso a la información de películas y series, y que todas las demás opciones del menú funcionen correctamente.

---

## 🧠 Conceptos aplicados

- 🧱 **Herencia**: La clase `Video` es una clase abstracta, de la cual heredan `Movies` y `Serie`.
- 🔄 **Polimorfismo**: Se emplea `virtual` y `override` para permitir el comportamiento específico según el tipo de video.
- ➕ **Sobrecarga de funciones**: En `Serie`, el método `addEpisod()` está sobrecargado para aceptar datos separados o un `struct Episodio`.
- 🧩 **Uso de structs**: El `struct Episodio` permite manejar múltiples episodios por serie de forma limpia y organizada.
- 📂 **Manejo de archivos**: Se leen archivos `.csv` para cargar datos de películas y series dinámicamente.

---

## 📥 Instrucciones de compilación y ejecución

### 🔧 Opción 1: Usando `g++`

1. Abre tu terminal y navega al directorio del proyecto.
2. Compila el programa con:

```bash
g++ main.cpp StreamHub.cpp Serie.cpp Movies.cpp Video.cpp -o DUFF
```

3. Ejecuta el programa con:

```bash
./DUFF
```

---

### 🔧 Opción 2: Usando `clang++`

1. Abre tu terminal y navega a la carpeta donde están los archivos del proyecto.
2. Compila el programa con:

```bash
clang++ main.cpp StreamHub.cpp Serie.cpp Movies.cpp Video.cpp -o DUFF
```

3. Ejecuta el programa con:

```bash
./DUFF
```

---

## 📋 Instrucciones de uso

Una vez ejecutado el programa, se mostrará el siguiente menú:

```
1. Cargar archivo de datos
2. Mostrar videos por calificación o género
3. Mostrar series con cierta calificación
4. Mostrar películas con cierta calificación
5. Mostrar los episodios de una determinada serie con una calificación determinada
6. Calificar un video
0. Salir
```

🔹 **Opción 1:** Carga los datos desde `db/movies.csv` y `db/series.csv`  
🔹 **Opción 2:** Permite filtrar cualquier video por calificación o por género  
🔹 **Opción 3 y 4:** Muestra solamente series o películas con una calificación específica  
🔹 **Opción 5:** Busca una serie por nombre y muestra sus episodios que coincidan con una calificación dada  
🔹 **Opción 6:** Permite modificar la calificación de un video por título

---

## 📄 Formato esperado de los archivos CSV

**movies.csv**

```
id,nombre,hora,min,genero,calificacion
1,Inception,2,28,ciencia ficcion,5
...
```

**series.csv**

```
id,nombre,hora,min,genero,calificacion,tituloCap,temporada,calificacionCap
10,Breaking Bad,0,50,drama,5,Pilot,1,5
...
```

---

## 🙋 Autor

Este proyecto fue desarrollado por **Leo** como parte de un ejercicio final de programación orientada a objetos en C++. Puedes revisar más proyectos en su [GitHub](https://github.com/LeoDuffed).

---

## ✅ Notas finales

- Se emplea memoria dinámica para gestionar los episodios de cada serie.
- El uso de `dynamic_cast` permite distinguir entre películas y series en tiempo de ejecución.
- El sistema está limitado a 100 videos y 10 episodios por serie como máximo, por simplicidad.

---

¡Disfruta explorando el mundo del streaming al estilo C++! 🎥📺

🛠️ Este archivo README fue elaborado con la ayuda de ChatGPT, una inteligencia artificial desarrollada por OpenAI, a partir del análisis automático del código fuente del proyecto.