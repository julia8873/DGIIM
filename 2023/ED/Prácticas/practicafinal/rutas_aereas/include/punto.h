//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H

#include <string>

class Punto {
private:
    double latitud, longitud;
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
    Punto(double lat, double lon, std::string desc);

    /**
     * @brief Coger la latitud
     * @return latitud del punto
     */
    double getLatitud() const;

    /**
     * @brief Coger la longitud
     * @return longitud del punto
     */
    double getLongitud() const;

    /**
     * @brief Coger la descripción
     * @return descripción del punto
     */
    std::string getDescripcion() const;

    /**
     * @brief Establece la latitud.
     * @param lat latitud a introducir.
     */
    void setLatitud(double lat);

    /**
     * @brief Establece la longitud.
     * @param lon longitud a introducir.
     */
    void setLongitud(double lon);

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

    /**
     * @brief Sobrecarga del operador <
     * @param p punto a comparar
     * @return true si el punto es menor
     * @return false si el punto es mayor
     */
    bool operator<(const Punto& p) const;

    /**
     * @brief Sobrecarga del operador ==
     * @param p punto a comparar
     * @return true si los puntos son iguales
     * @return false si no son iguales
     */
    bool operator==(const Punto& p) const;

    /**
     * @brief Sobrecarga del operador de salida
     * @param os flujo de salida
     * @param p punto a imprimir
     */
    friend std::ostream & operator<<(std::ostream & os, const Punto & p);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is flujo de entrada
     * @param p punto a leer
     */
    friend std::istream & operator>>(std::istream & is, Punto & p);

};




#endif //PRACTICAFINAL_PUNTO_H
