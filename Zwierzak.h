#include <iostream>
#include <stdio.h>
#include <string>
#include <list>

using namespace std;

#ifndef ZWIERZAK_H
#define ZWIERZAK_H
#include "Zwierzak.h"

class Zwierzak
{

    public:

        string imie;
        int id;
        int wiek;
        int waga;
        bool szczepiony;
        string notatka;


//      Zwierzak();

      Zwierzak(int = 1, string = "Boni", int = 2, int = 3, bool = 0, string = "brak uwag");


      virtual ~Zwierzak();


      void dodaj();

        // bool adoptuj();
      void edytuj();
      void wyswietl();

        // void wyszukaj();

};

#endif // ZWIRZAK_H
