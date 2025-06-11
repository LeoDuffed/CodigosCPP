# 🎬 DUFF: Sistema de Streaming en C++

Este proyecto es un sistema tipo servicio de streaming (inspirado en plataformas como Netflix o Prime Video), desarrollado en C++ como práctica de programación orientada a objetos.

Permite cargar películas y series desde archivos `.csv`, navegar por ellas según criterios como género o calificación, y calificar contenidos de forma interactiva desde consola.

---

## 🚀 ¿Qué hace este programa?

- Carga automáticamente películas y series desde archivos `movies.csv` y `Series.csv`.
- Muestra videos filtrados por:
  - Calificación
  - Género
- Muestra series que tienen ciertos episodios con calificación específica.
- Permite calificar cualquier video ingresando su nombre.
- Organiza la información con clases orientadas a objetos (`Video`, `Movies`, `Serie`, `Episodio`, `StreamHub`).
- Menú interactivo por consola.

---

## 🧠 Estructura del proyecto

### Clases principales:

- **Video (abstracta):** clase base para `Movies` y `Serie`. Contiene atributos comunes (`id`, `nombre`, `hora`, `min`, `genero`, `calificacion`) y un método virtual puro `mostrarVideos()`.

- **Movies:** hereda de `Video`. Representa una película, sobreescribe el método para mostrarla en consola.

- **Serie:** hereda de `Video`. Cada objeto guarda hasta 10 episodios usando un arreglo de `struct Episodio` con título, temporada y calificación. Tiene métodos para agregar y mostrar capítulos.

- **Episodio (struct):** estructura auxiliar usada por `Serie` para representar los capítulos.

- **StreamHub:** clase central que guarda un arreglo de hasta 50 videos (películas o series) y permite:
  - Agregar videos
  - Mostrar videos filtrados
  - Buscar capítulos por calificación y nombre de serie
  - Calificar videos

---

## 🗂 Archivos principales

| Archivo | Descripción |
|--------|-------------|
| `main.cpp` | Control del menú y carga de datos desde archivos `.csv` |
| `Video.h / Video.cpp` | Clase base abstracta |
| `Movies.h / Movies.cpp` | Clase para películas |
| `Serie.h / Serie.cpp` | Clase para series y sus episodios |
| `Episodio.h` | Struct auxiliar para `Serie` |
| `StreamHub.h / StreamHub.cpp` | Clase gestora de todo el sistema |

---

## 📁 Estructura de los CSV

### `movies.csv`
```
id,nombre,hora,min,genero,calificacion
1,Inception,2,28,ciencia ficcion,5
...
```

### `Series.csv`
```
id,nombre,hora,min,genero,calificacion,tituloEpisodio,temporadaEpisodio,califEpisodio
101,Stranger Things,0,50,fantasia,5,Capítulo 1,1,4
...
```

---

## 📋 Cómo usarlo

1. Asegúrate de tener un compilador C++ compatible con C++11 o superior.
2. Coloca los archivos `movies.csv` y `Series.csv` en el mismo directorio que el ejecutable.
3. Compila el programa (por ejemplo con `g++`):
   ```bash
   g++ main.cpp StreamHub.cpp Movies.cpp Serie.cpp Video.cpp -o DUFF
   ```
4. Ejecuta:
   ```bash
   ./DUFF
   ```

---

## 🎯 Ejemplo de flujo

```txt
Bienvenido a servicio de streaming DUFF
Menu:
1. Cargar archivo de datos
2. Mostrar videos por calificación o género
3. Mostrar series con cierta calificación
4. Mostrar películas con cierta calificación
5. Mostrar episodios de una serie con cierta calificación
6. Calificar un video
0. Salir
```

---

## 💡 Notas extra

- El sistema funciona solo con entradas exactas. Asegúrate de escribir correctamente los títulos.
- Puedes modificar el número máximo de series o episodios desde las constantes internas.
- Este código puede adaptarse fácilmente para cargar JSON, mejorar con `std::vector`, o agregar una interfaz gráfica.

---

## 👨‍💻 Autor

Desarrollado por **Leo** como proyecto final de programación en C++ con POO.  
Repositorio creado para compartir con otros estudiantes y profesores como referencia de un sistema POO completo en consola.
