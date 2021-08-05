#ifndef WYZNACZNIK_HH
#define WYZNACZNIK_HH

#include <iostream>

/*!
 * \file
 * \brief Zawiera metodę potrzebną do obliczania wyznacznika
 */



/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/*
    Lista krokow do obliczenia macierzy

        ZMIENNE ZEWNETRZENE
    n   - stopien macierzy
    w   - bierzacy wiersz, w ktorym rozpoczyna sie submacierz
    *K  - wektor kolumn
    **A - kopia macierzy podstawowej

        ZMIENNE FUNKCYJNE
    m   - mnoznik iloczynu macierzy
    *k  - wektor kolumn, mniejszy o jeden od wektora K
    s   - suma iloczynów wyrazow wiersza

    funkcja(n, w, K, A)
    Jesli   : (n == 1) -> return A[w][K[0]]
    Inaczej :
        1.  stworz k[n - 1]
        2.  s = 0
            m = 1
        3.  dla (i = 0; i < n; i++)
            i1. t = 0
            i2. dla (j = 0; j < n - 1; j++)
                jesli   : (k == i) -> k = k + 1
                zawsze  :
                    j1. k[j] = K[t]
                    j2. k = k + 1
            i3. s = s + m * A[w][K[i]] *  funkcja(n - 1, w + 1, K, A)
            i4. m = -m
        4.  usun k
        5.  return s
*/

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename type>
type determ(int n, int w, int * K, type ** A)
{
    int m, t;
    int *k;
    type s;

    //  warunek konczacy rekurencje
    if(n == 1)  {return A[w][K[0]];}
    else
    {
        k = new int [n - 1];
        m = 1;
        s = 0;

        for(int i = 0; i < n; i++)
        {
            t = 0;
            for(int j = 0; j < n - 1; j++)
            {
                if(t == i)  {t++;}
                k[j] = K[t++];
            }
            s = s + m * A[w][K[i]] * determ(n - 1, w + 1, k, A);
            m = -m;
        }
        delete [] k;
        return s;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif