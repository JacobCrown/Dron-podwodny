#include <iostream>
#include <cmath>

#include "surface.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void surface::setCenter()
{
    wektor3D tmp = wektor3D(0, 0, 0);
    double i;
    for(i = 0; i < vertex.size(); i++)  {tmp += vertex[i];}
    center = tmp / i;
}