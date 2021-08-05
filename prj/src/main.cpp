#include <iostream>
#include <unistd.h>

#include "scene.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void menu();
void clear();

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main()
{
    double a;
    double b;
    double c;
    char tmp;

    scene Scena;
    Scena.show();


    do
    {
        menu();
        cin >> tmp;
        clear();

        switch(tmp)
        {
            case 'r':
            cout << "\t" << "Podaj stopien rotacji : "; cin >> a;
            cout << "\t" << "Podaj dlugosc drogi : ";   cin >> b;
            Scena.moveStraigth(a, b);
            clear();
            break;

            case 'o':
            cout << "\t" << "Podaj stopien rotacji : "; cin >> c;
            Scena.rotate(c);
            clear();
            break;

            case 'k':
            cout << "\t" << "Wychodzenie ..." << endl;
            clear();

            break;

            case 'd':
            Scena.addObsticle();
            clear();
            break;

            case 'u':
            Scena.deleteLast();
            clear();
            break;

            default:
            cout << "\t" << "Blad wyboru." << endl;
            clear();

            break;
        }

    }   while(tmp != 'k');
    
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void menu()
{
    system("clear");

    cout << endl << endl;
    cout << "\t" << "MENU" << endl;
    cout << "\t" << "[r] - zadaj ruch na wprost" << endl;
    cout << "\t" << "[o] - zadaj obrot" << endl;
    cout << "\t" << "[d] - dodaj obiekt" << endl;
    cout << "\t" << "[u] - usun ostatni obiekt" << endl;
    cout << "\t" << "[k] - wyjscie" << endl;
    cout << "- - - + - - - + - - - + - - - + - - - + - - -" << endl;
    cout << "Aktualna ilosc obiektow wektor3D : " << wektor3D::quantity_now() << endl;
    cout << "Laczne ilosc obiektow wektor3D : " << wektor3D::quantity_all() << endl;
    cout << endl << endl;
}

void clear()
{
    cin.ignore(1024, '\n');
    cin.clear();
}