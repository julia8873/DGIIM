/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Julia Miralles Martínez
 * @author Andrés Alejo Martínez
 */

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_


#include <cstdlib>
#include <queue>

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
  @brief T.D.A. MaxStack

  Una instancia del tipo de dato abstracto MaxStack que permite manejar pilas mediante colas.

  El TDA MaxStack proporciona además distintas herramientas para la manipulación de dichas pilas.

  Para poder usar el TDA MaxStack se debe incluir el fichero

  \#include <maxstack.h>


  @author Julia Miralles
  @date Octubre 2023

**/

class MaxStack {

    /**
         @page page_repMaxStack Representación del TDA MaxStack

         @section sec_Image_A Título A

         Contenido de la sección A.

         @section sec_Image_B Título  B

         Contenido de la sección B.

         Referencia a la \ref sec_Image_A
       **/

private :

    /**
      @brief Cola usada para simular una pila

      Contiene los métodos ya implementados de la STL
    **/
    std::queue<element> q;

public :
    /**
     * @brief Función para conocer si una MaxStack está vacía.
     * @return Si la MaxStack está vacía
     * @post la MaxStack no se modifica.
     */
    bool empty() const;

    /**
      * @brief Tamaño de la MaxStack.
      * @return El número de elementos de la MaxStack.
      * @post La MaxStack no se modifica.
      */
    int get_size() const;

    /**
      * @brief Imprime el primer elemento de la MaxStack.
      * @return Primer elemento de la MaxStack.
      * @pre La MaxStack no está vacía.
      * @post la MaxStack no se modifica.
      */
    element top() const;

    /**
      * @brief Borra el primer elemento de la MaxStack.
      * @return La MaxStack menos el primer elemento (en el top).
      * @pre La MaxStack no está vacía.
      */
    void pop();

    /**
      * @brief Añade un elemento a la MaxStack.
      * @return MaxStack más el elemento.
      * @param n Elemento a Añadir
      */
    void push(int n);

};

#endif //  _MAXSTACK_