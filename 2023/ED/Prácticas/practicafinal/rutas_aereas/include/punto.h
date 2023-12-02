//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H

#include <string>

class Punto {
private:
    int latitud, longitud;
    std::string descripcion;

public:
    /**
     * @brief Constructor por defecto.
     * @details Crea un punto con latitud y longitud 0.
     *          La descripción es una cadena vacía.
     */
    Punto();

    /**
     * @brief Constructor con parámetros
     * @details Crea un punto con una latitud y longitud dadas
     * @param lat latitud del punto
     * @param lon longitud del punto
     * @param desc descripción del punto
     *
     */
    Punto(int lat, int lon, std::string desc);

    /**
     * @brief Coger la latitud
     * @return latitud del punto
     */
    int getLatitud();

    /**
     * @brief Coger la longitud
     * @return longitud del punto
     */
    int getLongitud();

    /**
     * @brief Coger la descripción
     * @return descripción del punto
     */
    std::string getDescripcion();


    /**
     * @brief Establece la latitud.
     * @param lat latitud a introducir.
     */
    void setLatitud(int lat);

    /**
     * @brief Establece la longitud.
     * @param lon longitud a introducir.
     */
    void setLongitud(int lon);

    /**
     * @brief Establece la descripción.
     * @param desc descripción a introducir.
     */
    void setDescripcion(std::string desc);

    /**
     * @brief Distancia entre dos puntos
     * @param otro punto con el que calcular la distancia
     * @return distancia entre ambos puntos
     */
    double distancia(Punto & otro);

};


#endif //PRACTICAFINAL_PUNTO_H
