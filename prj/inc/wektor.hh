#ifndef WEKTOR_HH
#define WEKTOR_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <fstream>
#include <cmath>


/*!
 * \file 
 * \brief Definicja klasy wektor
 *
 *  Plik zawiera definicję klasy SWektor, która modeluje ogólne
 *  pojęcie Wektora. Dodatkowo zawiera wszystkie metody zawarte w ciele klasy.
 */

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*! 
 * \brief Modeluje pojęcie wektora
 *
 *  Klasa ta jest klasą podstawową dla klasy Wektor3D. Zawiera podstawowe 
 *  metody działań na wektorach, przeciążone operatory i metody potrzebne w 
 *  opracowaniu problemu.
 */
template<typename type, int size>
class wektor
{
    protected:
/*! 
 * \brief Modeluje pojęcie wektora
 *
 *  Zawiera w sobie kolejno elementy wektora
 */
    type coordinates[size];
    /*! 
 * \brief Modeluje pojęcie wektora
 *
 *  Zawiera aktualną liczbę obiektów klasy wektor
 */
    static int amount_all;
    /*! 
 * \brief Modeluje pojęcie wektora
 *
 *  Zawiera liczbę wszystkich powstałych obiektów klasy wektor
 */
    static int amount_now;

    public:
  /*! 
 * \brief Konstruktor bezparametryczny
 *
 *  Ustawia współrzędne wektora na 0 i dodaje 1 do łącznej ilości obiektów
 */
    wektor(bool = true);
         /*! 
 * \brief Konstruktor kopiujący
 *
 *  Pozwala przy definicji obiektu przypisać wartości innego obiektu klasy 
 *  wektor.
 */
    wektor(const wektor<type, size> &);
  /*! 
 * \brief Przeciążenie operatora [] 
 *
 *  Zwraca element kryjący się pod _Wsp[Ind]
 */
    type operator [] (unsigned int) const;
        /*! 
 * \brief Przeciążenie operatora [] 
 *
 *  Zwraca referencję do elementu kryjącego się pod _Wsp[Ind]
 */
    type & operator [] (unsigned int);    
/*! 
 * \brief Przeciążenie operatora +=
 *
 *  Pozwala na dodawanie dwóch obiektów typu SWektor
 */
    wektor<type, size> operator += (const wektor<type, size> &);
       /*! 
 * \brief Przeciążenie operatora -=
 *
 *  Pozwala na odejmowanie dwóch obiektów typu SWektor
 */
    wektor<type, size> operator -= (const wektor<type, size> &);
        /*! 
 * \brief Przeciążenie operatora *=
 *
 *  Pozwala na mnożenie obiektu typu SWektor i obiektu STyp
 *  
 */
    wektor<type, size> operator *= (const type &);
    /*! 
 * \brief Przeciążenie operatora /=
 *
 *  Pozwala na dzielenie obiektu typu SWektor i obiektu STyp
 */
    wektor<type, size> operator /= (const type &);
    /*! 
 * \brief Przeciążenie operatora +
 *
 *  Pozwala na dodawanie dwóch obiektów typu SWektor
 */  
    wektor<type, size> operator + (const wektor<type, size> &) const;
        /*! 
 * \brief Przeciążenie operatora -
 *
 *  Pozwala na odejmowanie dwóch obiektów typu SWektor
 */
    wektor<type, size> operator - (const wektor<type, size> &) const;
    /*! 
 * \brief Przeciążenie operatora *
 *
 *  Pozwala na mnożenie obiektu typu SWektor i obiektu STyp
 */
    wektor<type, size> operator * (const type &) const;
    /*! 
 * \brief Przeciążenie operatora /
 *
 *  Pozwala na mnożenie obiektu typu SWektor i obiektu STyp
 */
    wektor<type, size> operator / (const type &) const;

    type operator * (const wektor<type, size> &) const;
    
    double length() const;

    static int quantity_all()   {return amount_all;}
    static int quantity_now()   {return amount_now;}

    ~wektor()   {amount_now--;}
};

template<typename type, int size>
wektor<type, size>::wektor(bool empty)
{
    amount_all++;
    amount_now++;

    if(empty == true)   {for(int i = 0; i < size; i++)  coordinates[i] = 0;}
}

template<typename type, int size>
wektor<type, size>::wektor(const wektor<type, size> & data)
{
    amount_all++;
    amount_now++;

    *this = data;
}

template<typename type, int size>
int wektor<type, size>::amount_all = 0;

template<typename type, int size>
int wektor<type, size>::amount_now = 0;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename type, int size>
type wektor<type, size>::operator [] (unsigned int index) const {return coordinates[index];}

template<typename type, int size>
type & wektor<type, size>::operator [] (unsigned int index)     {return coordinates[index];}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator += (const wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {coordinates[i] += data.coordinates[i];}
    return *this;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator -= (const wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {coordinates[i] -= data.coordinates[i];}
    return *this;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator *= (const type & data)
{
    for(int i = 0; i < size; i++)   {coordinates[i] *= data;}
    return *this;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator /= (const type & data)
{
    for(int i = 0; i < size; i++)   {coordinates[i] /= data;}
    return *this;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator + (const wektor<type, size> & data) const
{
    wektor<type, size> tmp = *this;
    return tmp += data;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator - (const wektor<type, size> & data) const
{
    wektor<type, size> tmp = *this;
    return tmp -= data;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator * (const type & data) const
{
    wektor<type, size> tmp = *this;
    return tmp *= data;
}

template<typename type, int size>
wektor<type, size> wektor<type, size>::operator / (const type & data) const
{
    wektor<type, size> tmp = *this;
    return tmp /= data;
}

template<typename type, int size>
type wektor<type, size>::operator * (const wektor<type, size> & data) const
{
    type tmp = 0;
    for(int i = 0; i < size; i++)   {tmp += coordinates[i] * data.coordinates[i];}
    return tmp;
}

template<typename type, int size>
double wektor<type, size>::length() const
{
    double tmp = 0;
    for(int i = 0; i < size; i++)   {tmp += pow(coordinates[i], 2);}
    return sqrt(tmp);
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename type, int size>
istream & operator >> (istream & str, wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str >> data[i];}
    return str;
}

template<typename type, int size>
ostream & operator << (ostream & str, wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str << '\t' << data[i];}
    return str;
}

template<typename type, int size>
ifstream & operator >> (ifstream & str, wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str >> data[i];}
    return str;
}

template<typename type, int size>
ofstream & operator << (ofstream & str, wektor<type, size> & data)
{
    for(int i = 0; i < size; i++)   {str << '\t' << data[i];}
    return str;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif