//
// Created by julia on 10/10/2023.
//

// Fichero: zoom.cpp
// Crea una imágen de doble tamaño interpolando
//

#include <iostream>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {

    char *origen, *destino; // nombres de los ficheros
    int fila, col, lado; // Valores de coordeandas iniciales y dimensiones
    Image image, final;

    // Comprobar validez de la llamada
    if (argc != 6) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: zoom <FichImagenOriginal> <FichImagenDestino> <fila> <col> <lado> \n";
        exit(1);
    }

    // Obtener argumentos
    origen = argv[1];
    destino = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    lado = atoi(argv[5]);


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;

    cout << endl;
    cout << "Fila y columna iniciales: (" << fila << "," << col << ")" << endl;
    cout << "Dimensiones finales: " << lado << "x" << lado << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows() << " filas x " << image.get_cols() << " columnas " << endl;

    // Recortar imágen
    final = image.Crop(fila, col, lado, lado);
    // Calcular el zoom
    final = final.Zoom2X();

    // Guardar la imagen resultado en el fichero
    if (final.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // EXTRA: comprobar si imágen es correcta
    // Image expected;
    // expected.Load("/home/julia/Desktop/DGIIM/2023/ED/TDA Imagen/expected/zoom_pub.pgm");
    // cout << "Iguales? " << boolalpha << final.Iguales(expected) << endl;

    return 0;
}
