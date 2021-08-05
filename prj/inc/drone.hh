#ifndef DRONE_HH
#define DRONE_HH

#include <iostream>
#include <fstream>

#include "shapes.hh"

/*!
 * \file
 * \brief Definicja metod klasy drone
 *
 * Zawiera definicje metod klasy drone i niezbędne operacje do sterowania dronem
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie drona
 *
 */
class drone
{
    protected:

    cube korpus;

    hexa rotor1;
    hexa rotor2;
    hexa rotor3;
    hexa rotor4;

    wektor3D rotor1_trans;
    wektor3D rotor2_trans;
    wektor3D rotor3_trans;
    wektor3D rotor4_trans;

    public:
 /*!
 * \brief konstruktor modelujący drona
 *
 */
    drone();
     /*!
 * \brief wraca drona do pierwotnej pozycji
 *
 */
    wektor3D returnCenter() const   {return korpus.returnCenter();}
 /*!
 * \brief Obraca o określony kąt
 *
 */
    void turnByAng(const double &);
     /*!
 * \brief przemieszcza o zadany wektor
 *
 */
    void translate(const wektor3D &);

     /*!
 * \brief przemieszcza na wprost
 *
 */
    void moveStraigth(const double &, const double &, const double &);
     /*!
 * \brief Obraca o określony kąt
 *
 */
    void rotate(const double &);

     /*!
 * \brief Zapisuje współrzędne aktualne do pliku
 *
 */
    void save();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif