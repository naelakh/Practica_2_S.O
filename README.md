# Practica 2 :Pinza Robotica 

---

## 1. Descripción :
Este repositorio contiene una practica de sistemas operativos desarrollada con **C++ y Bash** cuyo objetivo es procesar, organizar y analizar datos de sensores obtenidos de *una pinza robotica*.

El sistema trabaja con datos de: 
-	Galga extensométrica
-	Fuerza en el dedo izquierdo
-	Fuerza en el dedo derecho .
  
El proyecto resuelve el problema mediante:
-	Lectura de datos desde un archivo **( datos_pinza.txt)**
-	Almacenamiento en arrays y matrices
-	Organizacion de los datos
-	Calculo de valores medios de los sensores
-	Analisis de estabilidad del sistema
-	Generacion de un archivo de resultados **(resultado_pinza.txt)** .
  
El programa utiliza conceptos fundamentales como:
-	Lectura y escritura de archivos ( `ifstream`,`ofstream`)
-	Uso de arrays y matrices
-	Control de procesos en **Bash**
  
---

## 2. Estructura del repositorio :

```bash
Practica_2_SO/
├── pinza.cpp
├── script.sh
├── datos_pinza.txt
├── resultado_pinza.txt
└── README.md
```
---
## 3. Requisitos del sistema : 

- Sistema operativo: Linux (Ubuntu 22.04)
- Compilador: g++
- Terminal Bash.

Este proyecto no requiere librerias externas adicionales.

Utiliza unicamente librerias estandar de C++ como :

`iostream` y  `fstream` . 
---

## 4. Compilación y ejecución :

### 4.1 Compilación:
```bash
g++ -o pinza pinza.cpp
```
### 4.2 Ejecución del programa:
```bash
./pinza
```
### 4.3 Ejecución mediante script Bash:
```bash
chmod +x script.sh
```
```bash
./script.sh
```
## 5.Funcionamiento del programa en C++ :
El programa en C++ realiza las siguientes operaciones:
-	Lectura de datos desde un archivo
-	Almacenamiento en arrays y matrices
-	Organizacion de datos (ordenación por ID)
-	Calculo de valores medios
-	Analisis de estabilidad del sistema
-	Generacion de un archivo de salida **( resultado_pinza.txt )**
---
## 6.Funcionamiento del script Bash :

El script Bash se encarga de automatizar la ejecucion del programa:

-	Compila el codigo C++ utilizando `g++ -o pinza pinza.cpp `
-	Ejecuta el programa  `./pinza`
-	Lanza el proceso 
-	Espera a que el proceso finalice con `wait`
-	Comprueba si este proceso sigue activo con `kill -0`
-	Finaliza el proceso de forma controlada si es necesario con `kill`





