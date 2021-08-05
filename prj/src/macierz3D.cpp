#include <iostream>
#include <cmath>

#include "macierz3D.hh"


/*!
 * \file
 * \brief Definicja metody klasy Macierz3D
 *
 * Zawiera definicje metod klasy Macierz3D.
 */
using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*!
 * Zamienia stopnie na radiany
 * 
 * \param[in] - stopnie.
 */
double macierz3D::convertAngleToRadian(double data) const
{
    data = data * M_PI / 180;
    return data;
}
/*!
 * Zamienia radiany na stopnie
 * 
 * \param[in] - stopnie.
 */
double macierz3D::convertRadianToAngle(double data) const
{
    data = data * 180 / M_PI;
    return data;
}
/*!
 * Ustawia rotację obiektu klasy macierz wokół osi X
 * 
 * \param[in] - stopnie.
 */
void macierz3D::setRotationX(double angle)
{
    double radian = macierz3D::convertAngleToRadian(angle);
    double sn = sin(radian);
    double cs = cos(radian);

    (*this)(0,0) =  1;  (*this)(0,1) =  0;  (*this)(0,2) =  0;
    (*this)(1,0) =  0;  (*this)(1,1) = cs;  (*this)(1,2) =-sn;
    (*this)(2,0) =  0;  (*this)(2,1) = sn;  (*this)(2,2) = cs;
}
/*!
 * Ustawia rotację obiektu klasy macierz wokół osi Y
 * 
 * \param[in] - stopnie.
 */
void macierz3D::setRotationY(double angle)
{
    double radian = macierz3D::convertAngleToRadian(angle);
    double sn = sin(radian);
    double cs = cos(radian);

    (*this)(0,0) = cs;  (*this)(0,1) =  0;  (*this)(0,2) = sn;
    (*this)(1,0) =  0;  (*this)(1,1) =  1;  (*this)(1,2) =  0;
    (*this)(2,0) =-sn;  (*this)(2,1) =  0;  (*this)(2,2) = cs;
}

/*!
 * Ustawia rotację obiektu klasy macierz wokół osi Z 
 * 
 * \param[in] - stopnie.
 */
void macierz3D::setRotationZ(double angle)
{
    double radian = macierz3D::convertAngleToRadian(angle);
    double sn = sin(radian);
    double cs = cos(radian);

    (*this)(0,0) = cs;  (*this)(0,1) =-sn;  (*this)(0,2) =  0;
    (*this)(1,0) = sn;  (*this)(1,1) = cs;  (*this)(1,2) =  0;
    (*this)(2,0) =  0;  (*this)(2,1) =  0;  (*this)(2,2) =  1;   
}