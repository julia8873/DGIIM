#include <Casilla.h>
#include <Suma.h>
#include <iostream>

using namespace std;

/**
 * @brief Posición de una casilla en el sudoku. 
*/
struct Posicion {
  int fila;
  int columna;
};


/**
 * @brief TDA SudokuKiller
 * 
 * Representa un sudoku killer, un sudoku donde se guardan las sumas de casillas contiguas.
 * 
 * @author Andrés Alejo Martínez
 * @author Julia Miralles Martínez
*/

class SudokuKiller {
private:
  Casilla sudoku[9][9]; /**< Casillas de las que se compone el sudoku.*/
  Suma *sumas; /**< Suma de casillas contiguas.*/
  int nSumas; /**< Número de sumas que hay en el sudoku.*/

  /**
   * @brief Comprueba si un número está en una fila.
   * @param fila Fila en la que se comprueba.
   * @param num Número a comprobar.
   * @return true si el número está en la fila, false en caso contrario.
   * @pre 0 <= fila < 9
  */
  bool EstaEnFila(int fila, int num) const;

  /**
   * @brief Comprueba si un número está en una columna.
   * @param columna Columna en la que se comprueba.
   * @param num Número a comprobar.
   * @return true si el número está en la columna, false en caso contrario.
   * @pre 0 <= columna < 9
  */
  bool EstaEnColumna(int columna, int num) const;

  /**
   * @brief Comprueba si un número está en un bloque de 3x3.
   * @param pos Posición de la casilla cuyo bloque se va a comprobar.
   * @param num Número a comprobar.
   * @return true si el número está en el bloque, false en caso contrario.
   * @pre 0 <= pos.fila < 9 && 0 <= pos.columna < 9
  */
  bool EstaEnBloque(Posicion pos, int num) const;

public: 
  /**
   * @brief Constructor por defecto.
   * @return Crea un sudoku killer vacío.
  */
  SudokuKiller();

  /**
   * @brief Destructor.
   * @return Libera la memoria dinámica reservada.
   * @post El SudokuKiller queda vacío.
  */
  ~SudokuKiller();

  /**
   * @brief Constructor de copia.
   * @param otro Sudoku killer a copiar.
   * @return SudokuKiller, el objeto sudoku creado.
  */
  SudokuKiller(const SudokuKiller& otro);

  /**
   * @brief Operador de asignación.
   * @param otro Sudoku killer a copiar.
   * @return Una referencia al sudoku killer copiado.
  */
  SudokuKiller& operator=(const SudokuKiller& otro);

  /**
   * @brief Rellena una casilla del sudoku.
   * @param pos Posición de la casilla a rellenar.
   * @param num Número a introducir en la casilla.
   * @pre 0 <= pos.fila < 9 && 0 <= pos.columna < 9
   *      && 1 <= num <= 9
  */
  void RellenarCasilla(Posicion pos, int num);

  /**
   * @brief Añade una suma al tablero del sudoku.
   * @param sum Suma a añadir.
  */
  void AniadirSuma(Suma &sum);

  /**
   * @brief Elimina los números que no puedan estar en una casilla (ver clase Casilla).
   * @param pos Posición de la casilla a comprobar.
   * @pre 0 <= pos.fila < 9 && 0 <= pos.columna < 9
  */
  void DescartaPosibilidades(Posicion pos);

  /**
   * @brief Formatea el sudoku killer en un string.
   * @return String con el sudoku killer formateado.
  */
  string toString() const;
};

  /**
   * @brief Operador de salida.
   * @param os Flujo de salida.
   * @param sudoku SudokuKiller a imprimir.
   * @return Referencia al flujo de salida.
  */
  ostream& operator<<(ostream &os, const SudokuKiller &sudoku);
