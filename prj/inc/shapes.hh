#ifndef SHAPES_HH
#define SHAPES_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>

#include "shape.hh"


/*!
 * \file
 * \brief Definicja metody klasy shapes
 *
 * Zawiera definicje metod klasy shapes. Dziedziczy z klasy shape, są to szczególne przypadki reprezentujące kształty
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie prostopadłościanu
 *
 */
class cube
: public shape
{
    public:
 /*!
 * \brief Konstruktor dla zapamiętania pliku do modyfikacji i do oryginalnego położenia
 *
 */
    cube(): shape("dat/cube.dat", "tmp/cube.dat") {}
};
 /*!
 * \brief Modeluje pojęcie graniastosłupa o podstawie sześciokąta
 *
 */
class hexa
: public shape
{
    public:
 /*!
 * \brief Konstruktor dla zapamiętania pliku do modyfikacji i do oryginalnego położenia
 *
 */
    hexa(): shape("dat/hexa.dat", "tmp/hexa.dat") {}
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif