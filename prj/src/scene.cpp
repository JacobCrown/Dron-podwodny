#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>

#include "scene.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

scene::scene(const double & frames)
{
    amount_cube = 0;
    amount_hexa = 0;

    animation = frames;
    a_timeout = 1 / frames;

    ground_z = -50;
    water_z = 0;

    Dron.translate((wektor3D(0, 0, -20)));
    Dron.save();

    obj_1.changeTmp("tmp/obj_1.dat");
    obj_1.translate(wektor3D(10, 10,-46));
    obj_1.save();

    obj_2.changeTmp("tmp/obj_2.dat");
    obj_2.translate(wektor3D(-5,-10, -46));
    obj_2.save();

    obj_3.changeTmp("tmp/obj_3.dat");
    obj_3.translate(wektor3D(15,-10, -10));
    obj_3.save();

    link.ZmienTrybRys(PzG::TR_3D);
    link.Inicjalizuj();

    link.UstawZakresX(-30, 30);
    link.UstawZakresY(-30, 30);
    link.UstawZakresZ(-50, 10);
    link.UstawRotacjeXZ(75, 45);

    link.DodajNazwePliku("dat/water.dat");
    link.DodajNazwePliku("dat/ground.dat");

    link.DodajNazwePliku("tmp/cube.dat");
    link.DodajNazwePliku("tmp/hexa1.dat");
    link.DodajNazwePliku("tmp/hexa2.dat");
    link.DodajNazwePliku("tmp/hexa3.dat");
    link.DodajNazwePliku("tmp/hexa4.dat");

    link.DodajNazwePliku("tmp/obj_1.dat");
    link.DodajNazwePliku("tmp/obj_2.dat");
    link.DodajNazwePliku("tmp/obj_3.dat");

    colisionInfo.push_back(obj_1.returnCenter());
    colisionInfo.push_back(obj_2.returnCenter());
    colisionInfo.push_back(obj_3.returnCenter());
}

void scene::show()
{
    link.Rysuj();
    Dron.save();
    usleep(a_timeout * 2000000);
}

bool scene::moveStraigth(const double & n_angle, const double & length)
{
    for(int i = 0; i < animation; i++)
    {
        if((*this).colision())
        {
            info_2();
            for(int i = 0; i < animation; i++)
            {
                Dron.turnByAng(180 / animation);
                (*this).show();
            }
            usleep(1000000);
            for(int i = 0; i < animation; i++)
            {
                Dron.moveStraigth(-n_angle, M_E * log10(abs(length)) / 2, animation);
                (*this).show();
            }
            usleep(1000000);
            for(int i = 0; i < animation; i++)
            {
                Dron.turnByAng(180 / animation);
                (*this).show();
            }
            usleep(1000000);
            return false;
        }
        Dron.moveStraigth(n_angle, length / 2, animation);
        (*this).show();
    }
    return true;
}

void scene::rotate(const double & n_angle)
{
    for(int i = 0; i < animation; i++)
    {
        Dron.turnByAng(n_angle / animation);
        (*this).show();
    }
}

bool scene::colision()
{
    double delta = 8;

    double dron_z;
    droneCenter = Dron.returnCenter();
    dron_z = Dron.returnCenter()[2];
    if(dron_z < water_z - (delta / 2) && dron_z > ground_z + (delta / 2))
    {
        wektor3D tmp;
        double space;
        for(int i = 0; i < (int)colisionInfo.size(); i++)
        {
            tmp = droneCenter - colisionInfo[i];
            space = tmp.length();
            if(space < delta)
            {
                info_1();
                return true;
            }
        }
        return false;
    }

    else
    {
        info_1();
        return true;
    }
}

void scene::info_1()
{
    system("clear");
    cout << endl << endl;
    cout << "\t" << "UWAGA" << endl;
    cout << "\t" << "Dalszy ruch nie jest możliwy. Grozi uszkodzeniem drona!" << endl;
    cout << endl << endl;
    usleep(4000000);
}

void scene::info_2()
{
    system("clear");
    cout << endl << endl;
    cout << "\t" << "UWAGA" << endl;
    cout << "\t" << "Dron przygotowuje się do samodzielnego wycofania sie z niebezpiecznej sytuacii." << endl;
    cout << endl << endl;
    usleep(4000000);
}

bool scene::addObsticle()
{
    system("clear");
    cout << endl << endl;
    cout << "\t" << "[c] - cube" << endl;
    cout << "\t" << "[h] - hexa" << endl;
    cout << endl << endl;
    char o; cin >> o;

    switch(o)
    {
        case 'c':   amount_cube++;  break;
        case 'h':   amount_hexa++;  break;
        default:
        cout << endl << endl;
        cout << "\t" << "Blad! Nie ma takiego obiektu" << endl;
        cout << endl << endl;
        usleep(2000000);
        return false;
    }

    cout << '\t' << "Nadaj translacje : " << endl;
    cout << '\t' << "x = "; double x; cin >> x;
    cout << '\t' << "y = "; double y; cin >> y;
    cout << '\t' << "z = "; double z; cin >> z;

    wektor3D t = wektor3D(x, y, z);
    droneCenter = Dron.returnCenter();

    if((droneCenter - t).length() < 10)
    {
        cout << endl << endl;
        cout << "\t" << "Blad! Obiek nie moze powstac tak blisko drona." << endl;
        cout << endl << endl;
        usleep(4000000);
        return false;
    }

    if(o == 'c')
    {
        cube new_cube;
        char n[] = "tmp/new_0_c_.dat";
        n[8] = static_cast<char>(amount_cube);
        new_cube.changeTmp(n);
        new_cube.translate(t);
        new_cube.save();

        link.DodajNazwePliku(n);
        link.Rysuj();

        cubes.push_back(new_cube);
        colisionInfo.push_back(new_cube.returnCenter());
        lastAdded.push_back(0);
    }
    if(o == 'h')
    {
        hexa new_hexa;
        char n[] = "tmp/new_0_c_.dat";
        n[8] = static_cast<char>(amount_hexa);
        new_hexa.changeTmp(n);
        new_hexa.translate(t);
        new_hexa.save();

        link.DodajNazwePliku(n);
        link.Rysuj();

        hexas.push_back(new_hexa);
        colisionInfo.push_back(new_hexa.returnCenter());
        lastAdded.push_back(1);
    }
    return true;
}

bool scene::deleteLast()
{
    if(lastAdded.size() == 0)
    {
        cout << endl << endl;
        cout << "\t" << "Blad! Nie dodano zadnego obiektu." << endl;
        cout << endl << endl;
        usleep(2000000);
        return false;
    }

    int type = lastAdded[lastAdded.size() - 1];

    if(type == 0)
    {
        char n[] = "tmp/new_0_c_.dat";
        n[8] = static_cast<char>(amount_cube);
        ofstream file(n);
        file << '#' << endl;
        colisionInfo.pop_back();
        cubes.pop_back();
        lastAdded.pop_back();
        amount_cube--;
        link.Rysuj();
        return true;
    }

    if(type == 1)
    {
        char n[] = "tmp/new_0_h_.dat";
        n[8] = static_cast<char>(amount_hexa);
        ofstream file(n);
        file << '#' << endl;
        colisionInfo.pop_back();
        cubes.pop_back();
        lastAdded.pop_back();
        amount_hexa--;
        link.Rysuj();
        return true;
    }
    
    cout << endl << endl;
    cout << "\t" << "Blad! cos poszlo nie tak ..." << endl;
    cout << endl << endl;
    usleep(2000000);
    return false;
}