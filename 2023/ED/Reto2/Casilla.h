/**
 * @brief TDA Casilla
 * 
 * Representa una casilla de un sudoku killer.
 * - Si la casilla tiene un 0, se considera vacía.
 * 
 * @author Andrés Alejo Martínez
 * @author Julia Miralles Martínez
*/

class Casilla{
private:
  /**
   * @section invConjunto Invariante de la representación
   * valor >= 0 && valor <= 9
   * nPos >= 0 && nPos <= 9
   * indSuma >= 0
  */

  int valor; /**< Valor de la casilla.*/
  int indSuma; /**< Índice de la suma a la que pertenece la casilla.*/
  int *posibilidades; /**< Posibles valores de la casilla.*/
  int nPos; /**< Número de posibilidades de la casilla.*/


public:
  /**
   * @brief Constructor por defecto.
   * @return Crea una casilla vacía, con valor 0 y posibilidades = {1,2,3,4,5,6,7,8,9}.
  */
  Casilla();

  /**
   * @brief Destructor.
   * @return Libera la memoria dinámica reservada.
   * @post La casilla está vacía.
  */
  ~Casilla();

  /**
   * @brief Constructor de copia.
   * @param otro Casilla a copiar.
   * @return Casilla, el objeto casilla creada.
  */
  Casilla(const Casilla& otro);

  /**
   * @brief Operador de asignación.
   * @param otro Casilla a copiar.
   * @return Una referencia a la casilla copiada.
  */
  Casilla& operator=(const Casilla& otro);

  /**
   * @brief Valor de la casilla.
   * @return Valor de la casilla.
  */
  int getValor() const;

  /**
   * @brief Establece el valor de la casilla.
   * @param valor Valor de la casilla.
   * @pre 0 <= valor <= 9
  */
  void setValor(int valor);

  /**
   * @brief Índice de la suma a la que pertenece la casilla.
   * @return Índice de la suma a la que pertenece la casilla.
  */
  int getIndSuma() const;

  /**
   * @brief Número de posibilidades para la casilla.
   * @return Número de posibilidades para la casilla.
  */
  int getNPos() const;

  /**
   * @brief Elimina una posibilidad de la casilla.
   * @param valor Valor a eliminar.
   * @pre 1 <= valor <= 9
  */
  void eliminaPosibilidad(int valor);

  /**
   * @brief Añade una posibilidad a la casilla.
   * @param valor Valor a añadir.
   * @pre 1 <= valor <= 9
  */
  void nuevaPosibilidad(int valor);

  /**
   * @brief Comprueba si dos casillas tienen las mismas posibilidades.
   * @param casilla Casilla a comparar.
   * @return true si las casillas tienen las mismas posibilidades, false en caso contrario.
  */
  bool mismasPosib(Casilla casilla);

  /**
   * @brief Comprueba si un valor es posible para la casilla.
   * @param valor Valor a comprobar.
   * @return true si el valor es posible, false en caso contrario.
  */
  bool esPosible(int valor) const;
};
