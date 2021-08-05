#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <cmath>

#include "macierz.hh"


/*!
 * \file 
 * \brief Definicja klasy MacierzRot3D
 *
 *  Plik zawiera definicję klasy MacierzRot3D, która modeluje ogólne
 *  pojęcie Rotacji w przestrzeni trójwymiarowej. 
 */
using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*! 
 * \brief Modeluje pojęcie Macierzy rotacji
 *
 *  Klasa ta dziedziczy z klasy macierz<double,3>. Zawiera metody pozwalające na 
 *  obliczenie macierzy rotacji potrzebnej potem w obracaniu dronem w przestrzeni 
 *  trójwymiarowej
 */
class macierz3D
: public macierz<double, 3>
{
    private:
  /*!
    * \brief zamienia stopnie na radiany
    * 
    */
    double convertAngleToRadian(double) const;
      /*!
    * \brief zamienia radiany na stopnie
    * 
    */
    double convertRadianToAngle(double) const;
    
    public:
  /*!
    * \brief Konstruktor Bezparametryczny
    * 
    * Jest taki sam jak dla klasy SMacierz
    */
    macierz3D() = default;
       /*!
    * \brief Konstruktor kopiujący
    */
    macierz3D(const macierz<double, 3> & data)
    : macierz<double, 3> (data){}
  /*!
 * Ustawia rotację obiektu klasy macierz wokół osi X
 * 
 * \param[in] - stopnie.
 */
    void setRotationX(double);
      /*!
 * Ustawia rotację obiektu klasy macierz wokół osi Y
 * 
 * \param[in] - stopnie.
 */
    void setRotationY(double);
      /*!
 * Ustawia rotację obiektu klasy macierz wokół osi Z
 * 
 * \param[in] - stopnie.
 */
    void setRotationZ(double);
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif