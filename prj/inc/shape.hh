#ifndef SHAPE_HH
#define SHAPE_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <fstream>

#include "surface.hh"


/*!
 * \file
 * \brief Definicja metody klasy shape
 *
 * Zawiera definicje metod klasy shape pozwalającą na bycie klasą podstawową dla szczególnych kształtów
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie kształtu
 *
 */
class shape
: public surface
{
    protected:

    string file_tmp;
    double angle;
    double angleToRadian(double data) const {return (data * M_PI / 180);}

    wektor3D trans;
    wektor3D setTrans(double, double) const;

    public: 
 /*!
 * \brief konstruktor
 *
 */
    shape(const string & main_file, const string & tmp_file)
    : surface(main_file) {angle = 0; file_tmp = tmp_file;}
 /*!
 * \brief zmienia nazwę pliku tymczasowego
 *
 */
    void changeTmp(const string & tmp_file) {file_tmp = tmp_file;}
 /*!
 * \brief Obraca się o zadany kąt
 *
 */
    void turnByAng(double data)             {angle += data;}
     /*!
 * \brief Zapamiętuje wektor translacji
 *
 */
    void translate(const wektor3D & data)   {trans += data;}

 /*!
 * \brief zadaj ruch na wprost
 *
 */
    void moveStraigth(double, double, double);
     /*!
 * \brief Obróć się o zadany kąt
 *
 */
    void rotate(double);

     /*!
 * \brief Kręć się wokół własnej osi
 *
 */
    void spin();

     /*!
 * \brief powraca do początkowej pozycji
 *
 */
    wektor3D returnCenter() const   {return center + trans;}
 /*!
 * \brief zapisuje aktualne położenie kształtu do pliku
 *
 */
    void save(const wektor3D &);
 /*!
 * \brief zapisuje aktualne położenie kształtu do pliku
 *
 */
    void save();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif
