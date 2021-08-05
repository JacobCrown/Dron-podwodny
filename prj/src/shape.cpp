#include <iostream>
#include <fstream>

#include "shape.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

wektor3D shape::setTrans(double n_angle, double length) const
{
    wektor3D tmp;
    tmp[0] = (cos((*this).angleToRadian(n_angle)) * length) * cos((*this).angleToRadian(angle));
    tmp[1] = (cos((*this).angleToRadian(n_angle)) * length) * sin((*this).angleToRadian(angle));
    tmp[2] = (sin((*this).angleToRadian(n_angle)) * length);
    return tmp;
}

void shape::moveStraigth(double n_angle, double lenght, double animation)
{
    wektor3D tmp = (*this).setTrans(n_angle, lenght);
    tmp /= animation;

    (*this).translate(tmp);
    (*this).save();
    (*this).trans += tmp;
}

void shape::rotate(double n_angle)
{
    (*this).turnByAng(n_angle);
    (*this).save();
}

void shape::spin()
{
    macierz3D tmp;
    tmp.setRotationZ(20);
    for(int i = 0; i < (int)vertex.size(); i++) {vertex[i] = tmp * vertex[i];}
}

void shape::save()
{
    ofstream str_out(file_tmp);

    macierz3D rot;
    rot.setRotationZ(angle);

    wektor3D tmp;

    for(int i = 0; i < (int)vertex.size(); i++)
    {
        tmp = rot * vertex[i] + trans;
        str_out << tmp << endl;
    }
}

void shape::save(const wektor3D & data)
{
    ofstream str_out(file_tmp);

    macierz3D rot;
    rot.setRotationZ(angle);

    wektor3D tmp;

    for(int i = 0; i < (int)vertex.size(); i++)
    {
        tmp = rot * (vertex[i] + data) + trans;
        str_out << tmp << endl;
    }
}