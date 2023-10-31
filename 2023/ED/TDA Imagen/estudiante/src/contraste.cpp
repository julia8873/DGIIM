
// Fichero: contraste.cpp
// Crea una imágen con diferente contraste
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {

    char *origen, *destino; // nombres de los ficheros
    byte e1, e2, s1, s2; // Parámetros para ajustar el contraste
    Image image;

    // Comprobar validez de la llamada
    if (argc != 7) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: contraste <FichImagenOriginal> <FichImagenDestino> <e1> <e2> <s1> <s2> \n";
        exit(1);
    }

    // Obtener argumentos
    origen = argv[1];
    destino = argv[2];
    e1 = atoi(argv[3]);
    e2 = atoi(argv[4]);
    s1 = atoi(argv[5]);
    s2 = atoi(argv[6]);


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

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows() << " filas x " << image.get_cols() << " columnas " << endl;

    // Aplicar diferente contraste
    image.AdjustContrast(e1, e2, s1, s2);

    // Guardar la imagen resultado en el fichero
    if (image.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // EXTRA: comprobar si imágen es correcta
    // Image expected;
    // expected.Load("/home/julia/Desktop/DGIIM/2023/ED/TDA Imagen/img/vacas.pgm");
    // cout << "Iguales? " << boolalpha << image.Iguales(expected) << endl;

    return 0;
}
