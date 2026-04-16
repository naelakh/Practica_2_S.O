# Practica 2 :Pinza Robotica 
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
## 2. Estructura del repositorio :
Practica_2_SO
├── pinza.cpp              
├── script.sh              
├── datos_pinza.txt        
├── resultado_pinza.txt    
└── README.md
## 3. Requisitos del sistema : 
•	Sistema operativo: Linux (Ubuntu 22.04)
•	Compilador: g++
•	Terminal Bash.

Este proyecto no requiere librerias externas adicionales.
Utiliza unicamente librerias estandar de C++ como:
`iostream` / `fstream`
## 4. Compilación : 
`g++ -o pinza pinza.cpp`
## 5. Ejecución :
### Ejecución del programa:
`./pinza`
### Ejecución mediante script Bash:
`chmod +x script.sh`
`./script.sh`


