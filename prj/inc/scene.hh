#ifndef SCENA_HH
#define SCENA_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>

#include "link.hh"
#include "drone.hh"
#include "shapes.hh"
#include "surfaces.hh"


/*!
 * \file
 * \brief Definicja metody klasy scene
 *
 * Zawiera definicje metod klasy scene czyli wszystkie operacje działania na scenie
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie sceny na której rozgrywa się akcja
 *
 */
class scene
{
    protected:

    int amount_cube;
    int amount_hexa;

    PzG::LaczeDoGNUPlota link;

    drone Dron;
    water Woda;
    ground Dno;

    cube obj_1;
    cube obj_2;
    hexa obj_3;

    double animation;
    double a_timeout;

    wektor3D droneCenter;
    double ground_z;
    double water_z;

    vector<wektor3D> colisionInfo;
    void info_1();
    void info_2();

    vector<cube> cubes;
    vector<hexa> hexas;
    vector<int> lastAdded;

    void save();

    public:

    scene(const double & = 60);
     /*!
 * \brief sprawdza czy zaszła kolizja
 *
 */
    bool colision();
     /*!
 * \brief Sprawdza czy dodano przeszkodę
 *
 */
    bool addObsticle();
     /*!
 * \brief usuwa ostatnio dodaną przeszkodę
 *
 */
    bool deleteLast();

     /*!
 * \brief Zadaj ruch na wprost
 *
 */
    bool moveStraigth(const double &, const double &);
     /*!
 * \brief Obróć się o zadany kąt
 *
 */
    void rotate(const double &);

     /*!
 * \brief Rysuj scenę w gnuplocie
 *
 */
    void show();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


#endif