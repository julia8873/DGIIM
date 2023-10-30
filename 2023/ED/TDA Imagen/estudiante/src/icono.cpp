//
// Created by julia on 10/10/2023.
//

// Fichero: icono.cpp
// Crea una imágen reducida por un factor (entero)
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {

    char *origen, *destino; // nombres de los ficheros
    int factor; // Valores de coordeandas iniciales y dimensiones
    Image image, final;

    // Comprobar validez de la llamada
    if (argc != 4) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: icono <FichImagenOriginal> <FichImagenDestino> <factor> \n";
        exit(1);
    }

    // Obtener argumentos
    origen = argv[1];
    destino = argv[2];
    factor = atoi(argv[3]);


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;


    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    cout << endl;
    cout << "Dimensiones finales: " << floor(image.get_rows()/factor) << "x"
         << floor(image.get_cols()/factor) << endl;

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows() << " filas x " << image.get_cols() << " columnas " << endl;

    // Reducir imágen
    final = image.Subsample(factor);

    // Guardar la imagen resultado en el fichero
    if (final.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // EXTRA: comprobar si imágen es correcta
    Image expected;
    expected.Load("/home/julia/Desktop/2023/ED/codigo/expected/icono_pub.pgm");
    cout << "Iguales? " << boolalpha << final.Iguales(expected) << endl;

    return 0;
}
