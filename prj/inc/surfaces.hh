#ifndef SURFACES_HH
#define SURFACES_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>

#include "surface.hh"


/*!
 * \file
 * \brief Definicja metody klasy surfaces
 *
 * Zawiera definicje metod klasy surfaces która jest szczególną klasą dziedziczącą z klasy surfaces
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie powierzchni wody
 *
 */
class water
: public surface
{
    public:
 /*!
 * \brief Konstruktor dla wody
 *
 */
    water()
    : surface("dat/water.dat") {}
};
 /*!
 * \brief Modeluje pojęcie powierzchni dna
 *
 */
class ground
: public surface
{
    public:
 /*!
 * \brief Konstruktor dla powierzchni dna
 *
 */
    ground()
    : surface("dat/ground.dat") {}
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif