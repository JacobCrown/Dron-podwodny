#ifndef MACIERZ_HH
#define MACIERZ_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <iomanip>
#include <cmath>

#include "wektor.hh"
#include "wyznacznik.hh"

using namespace std;

/*!
 * \file 
 * \brief Definicja klasy macierz
 *
 *  Plik zawiera definicję klasy SMacierz, która modeluje ogólne
 *  pojęcie macierzy. 
 */

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*!
 * \brief Modeluje pojęcie macierzy 
 *
 *  Klasa zawiera podstawowe operacje działań na macierzach
 *  przeciążenia operatorów podstawowych działań matematycznych
 *  oraz pomocne funkcje w modelowaniu problemu
 */
template<typename type, int size>
class macierz
{
    protected:
   /*
    * Tablica elementów macierzy.
    */
    wektor<type, size> column[size];

    public:

    macierz(){}
  /*!
   * Udostępnia do odczytu element macierzy.
   *
   * Parametry:
   *   Wiersz - indeks wiersza, z którego ma być wybrany żądany element.
   *            Indeksowanie rozpoczyna się od 0 do 2.
   *   Kolumna - indeks kolumny, w której znajduje się żądany element.
   *            Indeksowanie rozpoczyna się od 0 do 2.
   * 
   * Warunki wstępne:
   *   Wiersz, Kolumna < 3.
   *
   * Zwracana wartość:
   *   wartość elementu maicerzy o podanym numerze kolumny.
   */
    type operator () (unsigned int, unsigned int) const;
      /*!
   * Udostępnia odczytu i zapisu element macierzy.
   *
   * Parametry:
   *   Wiersz - indeks wiersza, z którego ma być wybrany żądany element.
   *            Indeksowanie rozpoczyna się od 0 do 2.
   *   Kolumna - indeks kolumny, w której znajduje się żądany element.
   *            Indeksowanie rozpoczyna się od 0 do 2.
   * 
   * Warunki wstępne:
   *   Wiersz, Kolumna < 3.
   *
   * Zwracana wartość:
   *   referencja do elementu macierzy o podanym numerze kolumny.
   */
    type & operator () (unsigned int, unsigned int);

    wektor<type, size> operator [] (unsigned int) const;
    wektor<type, size> & operator [] (unsigned int);
     /*!
   * Mnoży wektor przez macierz zgodnie z ogólnie przyjętą definicją
   * tego typu operacji.
   * 
   * Parametry:
   *   W - wektor, który ma być przemnożony przez macierz.
   *
   * Zwracana wartość:
   *   Wektor będący wynikiem przemnożenia wektora W przez macierz.
   */
    wektor<type, size> operator * (const wektor<type, size> &);

    /*!
 * \brief transponuje macierz
 *

 */
    macierz transpose() const;
    /*!
 * \brief oblicza wyznacznik macierzy
 *

 */
    type determiant() const;

    void changeColumn(wektor<type, size>, unsigned int);
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*
 * Czyta ze strumienia wejściowego macierz. Zak³ada się, że kolejne
 * elementy macierzy podawane są w kolejności: M(0,0) M(0,1) M(0,2)
 * M(1,0), M(1,1) itd.
 *
 * Parametry:
 *   StrmWej - strumieñ wejściowy, z którego wczytywane są kolejne
 *             elementy macierzy.
 *   M - reprezentuje macierz, do której wczytywane są poszczególne
 *       pola
 *
 * Warunki wstępne:
 *   W strumieniu znajduje się kolejnych 9 liczb typu double oraz stan
 *   strumienia pozwala zrealizować operację odczytu.
 *
 * Warunki koñcowe:
 *   Ze strumienia zosta³o odczytanych 9 liczb.
 *
 * Zwracana wartość:
 *   Referencja do strumienia wejściowego, z którego dokonany zosta³
 *   odczyt.
 */
template<typename type, int size>
istream & operator >> (istream &, macierz<type, size> &);

/*
 * Zapisuje do strumienia weyściowego macierz. Wartości kolejnych
 * elementów macierzy wyświetlane są w następującej kolejności:
 *   M(0,0) M(0,1) M(0,2)
 *   M(1,0) M(1,1) M(1,2)
 *   M(2,0) M(2,1) M(2,2)
 *
 * Parametry:
 *   StrmWyj - strumieñ wyjściowy, do którego zapisywane są kolejne
 *             elementy macierzy.
 *   M - reprezentuje macierz, której elementy są zapisywane do strumienia
 *       wyjściowego.
 *
 * Warunki wstępne:
 *   Stan strumienia pozwala zrealizować operację zapisu.
 *
 * Warunki koñcowe:
 *   Do strumienia zosta³o odczytanych 9 liczb po 3 w jednej linii.
 *
 * Zwracana wartość:
 *   Referencja do strumienia wyjściowego, do którego zapise zosta³y
 *   elementy macierzy.
 */
template<typename type, int size>
ostream & operator << (ostream &, macierz<type, size> &);

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename type, int size>
type macierz<type, size>::operator () (unsigned int unit, unsigned int list) const
{
    return column[unit][list];
}

template<typename type, int size>
type & macierz<type, size>::operator () (unsigned int unit, unsigned int list)
{
    return column[unit][list];
}

template<typename type, int size>
wektor<type, size> macierz<type, size>::operator [] (unsigned int index) const
{
    return column[index];
}

template<typename type, int size>
wektor<type, size> & macierz<type, size>::operator [] (unsigned int index)
{
    return column[index];
}


template<typename type, int size>
macierz<type, size> macierz<type, size>::transpose() const
{
    macierz<type, size> tmp;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            tmp(i, j) = column[j][i];
        }
    }

    return tmp;
}

template<typename type, int size>
type macierz<type, size>::determiant() const
{
        int n = size;
    int w = 0;
    int *K;
    type **A;
    type end;

    A = new type * [n];
    for(int i = 0; i < n; i++)
    {
        A[i] = new type [n];
        for(int j = 0; j < n; j++)  {A[i][j] = column[i][j];}
    }

    K = new int [n];
    for(int i = 0; i < n; i ++) {K[i] = i;}

    end = determ(n, w, K, A);

    delete [] K;
    for(int i = 0; i < n; i++)  {delete [] A[i];}
    delete [] A;

    return end;
}

template<typename type, int size>
wektor<type, size> macierz<type, size>::operator * (const wektor<type, size> & data)
{
    type tmp;
    wektor<type, size> TMP;

    for(int i = 0; i < size; i++)
    {
        tmp = column[i] * data;
        TMP[i] = tmp;
    }

    return TMP;
}

template<typename type, int size>
void macierz<type,size>::changeColumn(wektor<type, size> data, unsigned int index)
{
    column[index] = data;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename type, int size>
istream & operator >> (istream & str, macierz<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str >> data[i];}
    return str;
}

template<typename type, int size>
ostream & operator << (ostream & str, macierz<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str << data[i] << endl;}
    return str;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif