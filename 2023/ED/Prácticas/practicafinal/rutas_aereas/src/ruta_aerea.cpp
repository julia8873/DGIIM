//
// Created by julia on 12/12/23.
//

/*
 * Este programa obtiene un mapa del mundo sobre el que se ha pintado una ruta elegida. Para
    tal objetivo el usuario insertará un fichero con un conjunto de países (ver especificación del
    fichero paises en la sección 2.3.2) y un almacén de rutas y una imagen de un mapa del mundo
    junto con la imagen del avión mostrada en la figura 2 y su máscara. Un ejemplo del resultado
    deseado es el que se muestra en figura 1. Además se debe indicar el directorio donde se
    almacena las banderas de cada país (en el ejemplo siguiente dir_banderas). Para probar esta
    función, deberá llamarse desde la línea de órdenes de la siguiente manera:
    prompt% ruta_aerea paises.txt mapa.ppm dir_banderas almacen_rutas.txt
    avion.ppm mascara_avion.pgm

    El programa en primer lugar mostrará en la consola todas las rutas existentes en el almacén
    de rutas y pedirá al usuario que inserte el código de una ruta. Tras esto el programa almacenará en disco una
    imagen ppm que cuyo nombre es el código de la ruta escogida y
    también mostrará en la consola la secuencia de países por los que pasa la ruta. En la imagen
    aparece en la localización del país por donde pasa la bandera del país. Además entre cada dos
    puntos de la ruta se pintará el avión al comienzo, punto intermedio y final.
    La traslación de un par (latitud,longitud) a un (i,j)-pixel de la imagen se hace mediante la
    siguiente ecuación:
     columna=(totalcolumnas/360.0)∗(180+longitud)
    fila=(totalfilas/180.0)∗(90−latitud )

    Siendo totalcolumnas y totalfilas el numero de filas y numero de columnas de la imagen con el
    mapa.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <imagen.h>
#include <paises.h>
#include <punto.h>
#include <almacenRutas.h>
#include <ruta.h>
#include <imagenES.h>
#include <cmath>

using namespace std;

int main(int argc, char * argv[]) {

    if (argc != 6) {
        cout << "Los parametros son :" << endl;
        cout << "1.-El fichero de paises" << endl;
        cout << "2.-La imagen del mapa" << endl;
        cout << "3.-El directorio de banderas" << endl;
        cout << "4.-El almacen de rutas" << endl;
        cout << "5.-La imagen del avion" << endl;
        cout << "6.-La mascara del avion" << endl;
        return 0;
    }

    // Leemos el fichero de paises
    Paises paises;
    ifstream f(argv[1]);
    if (!f) {
        cout << "Error al abrir el fichero " << argv[1] << endl;
        return 0;
    }
    f >> paises;


    //Leemos el mapa
    Imagen mapa;
    mapa.Leer(argv[2]);

    // Leemos el directorio de banderas
    string dir_banderas = argv[3];

    // Leemos el almacen de rutas
    AlmacenRutas almacen;
    ifstream f2(argv[4]);
    if(!f2){
        cout << "Error al abrir el fichero " << argv[4] << endl;
        return 0;
    }
    f2 >> almacen;

    // Leemos el avion
    Imagen avion;
    avion.Leer(argv[5]);


    // Leemos máscara avión
    Imagen mascara;
    mascara.Leer(argv[6]);

}