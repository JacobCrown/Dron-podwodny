#include <iostream>
#include <fstream>

#include "drone.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

drone::drone()
{
    korpus.changeTmp("tmp/cube.dat");
    rotor1.changeTmp("tmp/hexa1.dat");
    rotor2.changeTmp("tmp/hexa2.dat");
    rotor3.changeTmp("tmp/hexa3.dat");
    rotor4.changeTmp("tmp/hexa4.dat");

    rotor1_trans = wektor3D( 2, 2,-1);
    rotor2_trans = wektor3D( 2,-2,-1);
    rotor3_trans = wektor3D(-2, 2,-1);
    rotor4_trans = wektor3D(-2,-2,-1);

    rotor1.translate(rotor1_trans);
    rotor2.translate(rotor2_trans);
    rotor3.translate(rotor3_trans);
    rotor4.translate(rotor4_trans);
}

void drone::save()
{
    korpus.save();
    rotor1.save(rotor1_trans);
    rotor2.save(rotor2_trans);
    rotor3.save(rotor3_trans);
    rotor4.save(rotor4_trans);

    korpus.setCenter();
}

void drone::turnByAng(const double & n_angle)
{
    korpus.turnByAng(n_angle);
    rotor1.turnByAng(n_angle);
    rotor2.turnByAng(n_angle);
    rotor3.turnByAng(n_angle);
    rotor4.turnByAng(n_angle);

    rotor1.spin();
    rotor2.spin();
    rotor3.spin();
    rotor4.spin();
}

void drone::translate(const wektor3D & data)
{
    korpus.translate(data);
    rotor1.translate(data);
    rotor2.translate(data);
    rotor3.translate(data);
    rotor4.translate(data);
}

void drone::moveStraigth(const double & n_angle, const double & length, const double & animation)
{
    korpus.moveStraigth(n_angle, length, animation);
    rotor1.moveStraigth(n_angle, length, animation);
    rotor2.moveStraigth(n_angle, length, animation);
    rotor3.moveStraigth(n_angle, length, animation);
    rotor4.moveStraigth(n_angle, length, animation);

    rotor1.spin();
    rotor2.spin();
    rotor3.spin();
    rotor4.spin();
}

void drone::rotate(const double & n_angle)
{
    korpus.rotate(n_angle);
    rotor1.rotate(n_angle);
    rotor2.rotate(n_angle);
    rotor3.rotate(n_angle);
    rotor4.rotate(n_angle);
}