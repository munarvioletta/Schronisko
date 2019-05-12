#include <iostream>
#include <list>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ctype.h>
#include "Zwierzak.h"

using namespace std;




int opcja = 0,x;
int k;
uint16_t n = 5; //rozmiar listy
int nazwa,p;
int ID;



void wyswietlListe(list<Zwierzak> );
string znajdzNaLiscie(list<Zwierzak>& , string);
void usun_zwierze(list<Zwierzak>&, int ,Zwierzak);
void zaladuj_plik(list<Zwierzak>&, Zwierzak& );
Zwierzak edytuj(list<Zwierzak>&, int, Zwierzak&);


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
 cout << "5. Usun zwierze" << endl;
 cout << "6. Edytuj zwierze" << endl;
 cout << "9. Wyjdz z menu" << endl<<endl;

if (opcja == 0)
{
zaladuj_plik(Lista_zwierzat,z);
wyswietlListe(Lista_zwierzat);
cout<<endl;
}

while (x != 9){



 cout<<"Wybierz opcje: ";

 cin >> opcja;



      switch (opcja){


        case 1:

            if (Lista_zwierzat.empty()){
                cout<<"Lista pusta,  dodaj zwierze"<<endl;
                z.dodaj(ID);
                Lista_zwierzat.push_back(z);
            }

            else if(Lista_zwierzat.size() < n &&  Lista_zwierzat.size() >= 1){


            cout<<" Wprowadz ID: ";cin>>ID;

            z.dodaj(ID);
            Lista_zwierzat.push_back(z);
            z.wyswietl();

            }

            else{

                cout<<"Schronisko jest przepełnione"<<endl;

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
                    cout<<"False"<<" "<<" - w liscie znajduje sie " <<Lista_zwierzat.size()<<" "<<"zierzat"<<endl;
            }



        break;

        case 4:

            cout<<"Liczba zwierzat w liscie:"<<" "<<Lista_zwierzat.size()<<endl;


        break;


        case 5:

            cout<<"Usun zwierze o numerze id z listy: "<<endl;

            if(Lista_zwierzat.size()==0){
                cout<<"Lista pusta"<<endl;
            }

            else{
            wyswietlListe(Lista_zwierzat);

            cout<<"id:  ";
            cin>>k;
            usun_zwierze(Lista_zwierzat, k, z);

            cout<<"Usunieto zwierze o numerze id:"<<" "<<k<<endl;
            }

        break;


        case 6:

            cout<<"Edytuj zwierze o numerze id :"<<" "<<endl;

            if(Lista_zwierzat.size()==0){
                cout<<"Lista pusta"<<endl;
            }

            else{

            cin>>nazwa;

            edytuj(Lista_zwierzat, nazwa, z);

            cout<<"id"<<z.id<<endl;

            z.wyswietl();

            cout<<"Wprowadz numer od edycji"<<endl;
            cout << "1. Zmien imie" << endl;
            cout << "2. Zmien wiek w latach" << endl;
            cout << "3. Zmien wage w kg" << endl;
            cout << "4. Zmien czy zasczepiony Tak - 1, nie- 0" << endl;
            cout << "5. Zmien notatke" << endl;

            cin>>p;

            switch(p){

                case 1:
                     cout<<"Imie: ";
                     cin>>z.imie;
                     usun_zwierze(Lista_zwierzat, z.id, z);
                     Lista_zwierzat.push_back(z);
                     z.wyswietl();


                break;


                case 2:
                     cout<<"wiek: ";
                     cin>>z.wiek;
                     usun_zwierze(Lista_zwierzat, z.id, z);
                     Lista_zwierzat.push_back(z);
                     z.wyswietl();
                     z.zapisz_do_pliku();

                break;



                case 3:

                     cout<<"waga: ";
                     cin>>z.waga;
                     usun_zwierze(Lista_zwierzat, z.id, z);
                     Lista_zwierzat.push_back(z);
                     z.wyswietl();

                break;



                case 4:

                     cout<<"szczepiony: ";
                     cin>>z.szczepiony;
                     usun_zwierze(Lista_zwierzat, z.id, z);
                     Lista_zwierzat.push_back(z);
                     z.wyswietl();

                break;



                case 5:
                     cout<<"notatka: ";
                     getline(cin, z.notatka, '0');
                     z.notatka.erase(0,1);
                     usun_zwierze(Lista_zwierzat, z.id, z);
                     Lista_zwierzat.push_back(z);
                     z.wyswietl();

                break;

            }

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
                    z.imie = linia.substr(12,5);
                    z.wiek = static_cast<int>(linia[33]-47);
                    z.waga = static_cast<int>(linia[46]-47);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,30);
                    Lista_zwierzat.push_front(z);
            break;

            case 2:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,5);
                    z.wiek = static_cast<int>(linia[33]-47);
                    z.waga = static_cast<int>(linia[46]-47);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,30);
                    Lista_zwierzat.push_front(z);
            break;

            case 3:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,5);
                    z.wiek = static_cast<int>(linia[33]-47);
                    z.waga = static_cast<int>(linia[46]-47);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,30);
                    Lista_zwierzat.push_front(z);
            break;

            case 4:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,5);
                    z.wiek = static_cast<int>(linia[33]-47);
                    z.waga = static_cast<int>(linia[46]-47);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,30);
                    Lista_zwierzat.push_front(z);
            break;

            case 5:

                    z.id = static_cast<int>(linia[4]-48);
                    z.imie = linia.substr(12,5);
                    z.wiek = static_cast<int>(linia[33]-47);
                    z.waga = static_cast<int>(linia[46]-47);
                    z.szczepiony = static_cast<int>(linia[81]-48);
                    z.notatka = linia.substr(92,30);
                    Lista_zwierzat.push_front(z);
            break;


         }

      nr_linii++;
    }

    plik.close();



}

Zwierzak edytuj(list<Zwierzak> &Lista_zwierzat, int k, Zwierzak& z){


    list<Zwierzak>::iterator it;
    it = find_if(Lista_zwierzat.begin(), Lista_zwierzat.end(), [&k](const Zwierzak& a){return a.id == k;} );

    return z = *it;


}
