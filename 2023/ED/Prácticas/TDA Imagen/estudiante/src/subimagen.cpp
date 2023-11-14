//
// Created by julia on 10/10/2023.
//

// Fichero: crop.cpp
// Recorta una imágen
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    int fila, col, fila_sub, col_sub; // Valores de coordeandas iniciales y dimensiones
    Image image, final;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> <fila> <col> <fila_sub> <col_sub>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    fila_sub = atoi(argv[5]);
    col_sub = atoi(argv[6]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;

    cout << endl;
    cout << "Fila y columna iniciales: (" << fila << "," << col << ")" << endl;
    cout << "Dimensiones finales: " << fila_sub << "x" << col_sub << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    // Recortar la imágen
    final = image.Crop(fila, col, fila_sub, col_sub);

    // Guardar la imagen resultado en el fichero
    if (final.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // EXTRA: comprobar si imágen es correcta
    // Image expected;
    // expected.Load("/home/julia/Desktop/DGIIM/2023/ED/TDA Imagen/expected/subimagen_pub.pgm");
    // cout << "Iguales? " << boolalpha << final.Iguales(expected) << endl;

    return 0;
}
