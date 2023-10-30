/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Julia Miralles
 */

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_


#include <cstdlib>
#include <stack>

struct element {
    int value; // Current value to store
    int maximum; // Current max value in the structure

    // Sobrecargar el operador <<
    friend std::ostream& operator<<(std::ostream& os, const element& elem) {
        os <<  elem.value << "," << elem.maximum;
        return os;
    }
};


/**
  @brief T.D.A. MaxQueue

  Una instancia del tipo de dato abstracto MaxQueue que permite manejar colas mediante pilas.

  El TDA MaxQueue proporciona además distintas herramientas para la manipulación de dichas colas.

  Para poder usar el TDA MaxQueue se debe incluir el fichero

  \#include <MaxQueue.h>


  @author Julia Miralles
  @date Octubre 2023

**/

class MaxQueue {

    /**
         @page page_repMaxQueue Representación del TDA MaxQueue

         @section sec_Image_A Título A

         Contenido de la sección A.

         @section sec_Image_B Título  B

         Contenido de la sección B.

         Referencia a la \ref sec_Image_A
       **/

private :

    /**
      @brief Pila usada para simular una cola

      Contiene los métodos ya implementados de la STL
    **/
    std::stack<element> s;

public :
    /**
     * @brief Función para conocer si una MaxQueue está vacía.
     * @return Si la MaxQueue está vacía
     * @post la MaxQueue no se modifica.
     */
    bool empty() const;

    /**
      * @brief Tamaño de la MaxQueue.
      * @return El número de elementos de la MaxQueue.
      * @post la MaxQueue no se modifica.
      */
    int get_size() const;

    /**
      * @brief Imprime el primer elemento de la MaxQueue.
      * @return Primer elemento de la MaxQueue.
      * @pre La MaxQueue no está vacía.
      * @post La MaxQueue no se modifica.
      */
    element front() const;

    /**
      * @brief Borra el primer elemento de la MaxQueue.
      * @return La MaxQueue menos el primer elemento (en el top).
      * @pre La MaxQueue no está vacía.
      */
    void pop();

    /**
      * @brief Añade un elemento a la MaxQueue.
      * @return MaxQueue más el elemento.
      * @param n Elemento a Añadir
      */
    void push(int n);

};

#endif //  _MAXQUEUE_