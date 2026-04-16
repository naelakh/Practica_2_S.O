#include <iostream>
#include <fstream>

using namespace std;

// global arrays 
float datos[100][3];
int   ids[100];
float galga[100];
float fuerza_izq[100];
float fuerza_der[100];
string estado[100];
int n = 0;

// read data from file 
void leerDatos() {
    ifstream archivo("datos_pinza.txt");

    if (!archivo) {
        cout << "Error: no se pudo abrir datos_pinza.txt" << endl;
        return;
    }

    while (n < 100 && archivo >> ids[n] >> galga[n] >> fuerza_izq[n] >> fuerza_der[n]) {
        datos[n][0] = galga[n];
        datos[n][1] = fuerza_izq[n];
        datos[n][2] = fuerza_der[n];
        n++;
    }

    if (n == 100) {
        cout << "Aviso: solo se han cargado los primeros 100 datos.\n";
    }

    archivo.close();
}

// organize the data by id
void ordenarPorID() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ids[j] > ids[j + 1]) {

                int tempID = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = tempID;

                float temp;

                temp = galga[j];
                galga[j] = galga[j + 1];
                galga[j + 1] = temp;

                temp = fuerza_izq[j];
                fuerza_izq[j] = fuerza_izq[j + 1];
                fuerza_izq[j + 1] = temp;

                temp = fuerza_der[j];
                fuerza_der[j] = fuerza_der[j + 1];
                fuerza_der[j + 1] = temp;

                for (int k = 0; k < 3; k++) {
                    temp = datos[j][k];
                    datos[j][k] = datos[j + 1][k];
                    datos[j + 1][k] = temp;
                }
            }
        }
    }
}

//show the data
void mostrarDatos() {
    for (int i = 0; i < n; i++) {
        cout << "ID: "     << ids[i]
             << " Galga: " << galga[i]
             << " Izq: "   << fuerza_izq[i]
             << " Der: "   << fuerza_der[i] << endl;
    }
}


//calculating the averages 
void calcularMedias(float &media_g, float &media_i, float &media_d) {
    float suma_g = 0;
    float suma_i = 0;
    float suma_d = 0;

    for (int i = 0; i < n; i++) {
        suma_g += galga[i];
        suma_i += fuerza_izq[i];
        suma_d += fuerza_der[i];
    }

    if (n > 0) {
        media_g = suma_g / n;
        media_i = suma_i / n;
        media_d = suma_d / n;
    } else {
        media_g = media_i = media_d = 0;
    }
}


//check stability for each one
void evaluarEstabilidad() {
    for (int i = 0; i < n; i++) {
        float diferencia = fuerza_izq[i] - fuerza_der[i];

        if (diferencia < 0) {
            diferencia = -diferencia;
        }

        if (diferencia > 0.15) {
            estado[i] = "INESTABLE";
        } else {
            estado[i] = "ESTABLE";
        }
    }
}

//save data in file resultados_pinza.txt
void guardarResultados(float media_g, float media_i, float media_d) {
    ofstream salida("resultado_pinza.txt");

    if (!salida) {
        cout << "Error al crear archivo de salida\n";
        return;
    }

    salida << "RESULTADOS DEL SISTEMA DE PINZA ROBOTICA\n";

    salida << "Datos:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " "
               << galga[i] << " "
               << fuerza_izq[i] << " "
               << fuerza_der[i] << endl;
    }

    salida << "\nMedias:\n";
    salida << "Galga = " << media_g << endl;
    salida << "Fuerza izquierda = " << media_i << endl;
    salida << "Fuerza derecha = " << media_d << endl;

    salida << "\nClasificacion:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " " << estado[i] << endl;
    }

    salida.close();
}


//main function
int main() {

    leerDatos();

    if (n == 0) {
        cout << "No hay datos para procesar.\n";
        return 1;
    }

    ordenarPorID();
    mostrarDatos();

    float media_g, media_i, media_d;
    calcularMedias(media_g, media_i, media_d);

    cout << "\nMedia galga: " << media_g << endl;
    cout << "Media fuerza izquierda: " << media_i << endl;
    cout << "Media fuerza derecha: " << media_d << endl << endl;

    evaluarEstabilidad();

    for (int i = 0; i < n; i++) {
        cout << "Estado muestra " << ids[i] << ": " << estado[i] << endl;
    }

    guardarResultados(media_g, media_i, media_d);

    return 0;
}
