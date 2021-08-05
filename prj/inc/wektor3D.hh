#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>

#include "wektor.hh"


/*!
 * \file 
 * \brief Definicja klasy Wektor3D
 *
 *  Plik zawiera definicję klasy Wektor3D, która modeluje ogólne
 *  pojęcie współrzędnych w trzech wymiarach
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*! 
 * \brief Modeluje pojęcie wektorów w 3 wymiarach
 *
 *  Klasa ta dziedziczy z klasy SWektor<double,3>. 
 */
class wektor3D
: public wektor<double, 3>
{
    public:

    wektor3D(){}
     /*!
    * \brief Konstruktor parametryczny
    * Przyporządkowuje współrzędne do odpowiednich miejsc tablicy wektora
    */
    wektor3D(double x, double y, double z)  {(*this)[0] = x; (*this)[1] = y; (*this)[2] = z;}
    /*!
    * \brief Konstruktor kopiujący
    */
    wektor3D(const wektor<double, 3> & data)
    : wektor<double, 3> (data){}
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif