#ifndef SURFACE_HH
#define SURFACE_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "wektor3D.hh"
#include "macierz3D.hh"


/*!
 * \file
 * \brief Definicja metody klasy surface
 *
 * Zawiera definicje metod klasy surface która modeluje powierzchnię
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
 /*!
 * \brief Modeluje pojęcie powierzchni
 *
 */
class surface
{
    protected:

    vector<wektor3D> vertex;
    string file_main;

    wektor3D center;

    public:
 /*!
 * \brief Konstruktor dla powierzchni
 *
 */
    surface(const string & main_file)
    {
        this->file_main = main_file;

        ifstream str(main_file);
        wektor3D tmp;
        while(str >> tmp)   {vertex.push_back(tmp);}

        (*this).setCenter();
    }
 /*!
 * \brief Ustawia do pozycji początkowej
 *
 */
    void setCenter();
    wektor3D returnCenter() const   {return center;}
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif