#include <iostream>
#include <list>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Zwierzak.h"


int opcja,x;
int k;
uint16_t n = 5; //rozmiar listy



void wyswietlListe(list<Zwierzak> );
string znajdzNaLiscie(list<Zwierzak>& , string);
void usun_zwierze(list<Zwierzak>&, int ,Zwierzak);
void zaladuj_plik(list<Zwierzak>&, Zwierzak &z);


int main() {

list<Zwierzak> Lista_zwierzat;
Zwierzak z;


//int id, wiek, waga,
//string imie, notatka;
//bool szczepiony;

 cout << "MENU GLOWNE" << endl;
 cout <<endl;
 cout << "-----------------" << endl;
 cout << "1. Dodaj zwierze do listy" << endl;
 cout << "2. Wyswietl liste pacjentow" << endl;
 cout << "3. Czy lista pusta?" << endl;
 cout << "4. Rozmiar listy" << endl;
 cout << "5. Usun Pacjenta" << endl;
 cout << "9. Wyjdz z menu" << endl<<endl;


zaladuj_plik(Lista_zwierzat,z);
wyswietlListe(Lista_zwierzat);

while (x != 9){



 cout<<"Wybierz opcje:";

 cin >> opcja;



      switch (opcja){


        case 1:

            if(Lista_zwierzat.size()<= n){


                z.dodaj();
                Lista_zwierzat.push_back(z);


            }

            else{

                cout<<" Schronisko jest pełne"<<endl;
            }


        break;

        case 2:

            if (Lista_zwierzat.empty()){
                cout<<"Lista pusta"<<endl;
            }

            else if(Lista_zwierzat.size() >= n){

                cout<<" Schronisko jest pełne"<<endl;
                 wyswietlListe(Lista_zwierzat);
            }

            else{

                  wyswietlListe(Lista_zwierzat);
                  cout<<"\n"<<"Mozna przyjac kolejne zwierzeta do schroniska"<<endl;

            }


        break;

        case 3:

            cout<<"Lista pusta: ";
            if (Lista_zwierzat.empty()){

                    cout<< "True"<<endl;
            }
            else {
                    cout<<"False"<<" "<<" w liscie znajduje sie " <<Lista_zwierzat.size()<<" "<<"zierzat"<<endl;
            }



        break;

        case 4:

            cout<<"Liczba zwierzat w liscie:"<<" "<<Lista_zwierzat.size()<<endl;


        break;


        case 5:

            cout<<"Usun zwierze o numerze id z listy:"<<" "<<endl;

            if(Lista_zwierzat.size()==0){
                cout<<"Lista pusta"<<endl;
            }

            else{
            wyswietlListe(Lista_zwierzat);

            cin>>k;
            usun_zwierze(Lista_zwierzat, k, z);

            cout<<"Usunieto zwierze o numerze id:"<<" "<<k<<endl;
            }

        break;

        case 9:

            exit(0);

        break;

        default: break;
      }

    x++;


 }


  return 0;
}

void wyswietlListe(list<Zwierzak> Lista_zwierzat){

   list<Zwierzak>::iterator it;

    for (it =  Lista_zwierzat.begin(); it !=  Lista_zwierzat.end(); ++it)
    {
      it->wyswietl();
    }

}


void usun_zwierze(list<Zwierzak> &Lista_zwierzat, int k, Zwierzak z){


   list<Zwierzak>::iterator it;

   if (!Lista_zwierzat.empty()){


         it = find_if(Lista_zwierzat.begin(), Lista_zwierzat.end(), [&k](const Zwierzak& a){ return a.id == k; });


           if (it -> id) Lista_zwierzat.erase(it);


        }

    }


void zaladuj_plik(list<Zwierzak>& Lista_zwierzat, Zwierzak &z){

    fstream plik;

    plik.open("schronisko.txt", ios::in);
        if(plik.good()==false){

            cout<<"Plik nie istnieje";
            //exit(0);
        }

    string linia;
    int nr_linii=1;
    cout<<"\nAktualna lista\n"<<endl;

    while (getline(plik,linia)){


        switch(nr_linii){

            case 1:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,6);
                    z.wiek = static_cast<int>(linia[33]-48);
                    z.waga = static_cast<int>(linia[46]-48);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,5);
                    Lista_zwierzat.push_front(z);
            break;

            case 2:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,6);
                    z.wiek = static_cast<int>(linia[33]-48);
                    z.waga = static_cast<int>(linia[46]-48);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,10);
                    Lista_zwierzat.push_front(z);
            break;

            case 3:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,6);
                    z.wiek = static_cast<int>(linia[33]-48);
                    z.waga = static_cast<int>(linia[46]-48);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,10);
                    Lista_zwierzat.push_front(z);
            break;

            case 4:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,6);
                    z.wiek = static_cast<int>(linia[33]-48);
                    z.waga = static_cast<int>(linia[46]-48);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,10);
                    Lista_zwierzat.push_front(z);
            break;

            case 5:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,6);
                    z.wiek = static_cast<int>(linia[33]-48);
                    z.waga = static_cast<int>(linia[46]-48);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,10);
                    Lista_zwierzat.push_front(z);
            break;


         }

      nr_linii++;
    }

    plik.close();



}

string znajdzNaLiscie(list<Zwierzak>& z, string k){


    list<Zwierzak>::iterator it;
    it = find_if(z.begin(), z.end(), [&k](const Zwierzak& a){ return a.imie == k; }  );
    return it -> notatka;

}
