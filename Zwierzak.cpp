#include "Zwierzak.h"
#include <string.h>
#include <list>
#include <iostream>
#include <cstdlib>
#include <fstream>




using namespace std;

//Zwierzak::Zwierzak(){}



Zwierzak::Zwierzak(int Id, string Imie , int Wiek, int Waga, bool Szczepiony, string Notatka)
{
    id = Id;
    imie = Imie;
    wiek = Wiek;
    waga = Waga;
    szczepiony = Szczepiony;
    notatka = Notatka;
}

Zwierzak::~Zwierzak()
{
    //dtor

}


void Zwierzak::dodaj(){



    cout<<"Dodaj zwierze: id, nazwa, wiek, waga, czy szczepiony, notatka"<<endl;
    cout<<"id:"<<" ";cin>>id;
    cout<<"imie:"<<" ";cin>>imie;
    cout<<"wiek w latach:"<<" "; cin>>wiek;
    cout<<"waga w kg:"<<" ";cin>>waga;
    cout<<"czy szczepiony Tak - 1, Nie - 0:"<<" "; cin>>szczepiony;
    cout<<"notatka:"<<" ";
    getline(cin, notatka, '0');
    notatka.erase(0,1);
    cout<<" "<<endl;

    fstream plik;

    plik.open("schronisko.txt", ios::out |ios::app);
    plik<<"id:"<<" ";plik<<id<<" ";
    plik<<"imie:"<<" ";plik<<imie<<" ";
    plik<<"wiek w latach:"<<" "; plik<<wiek<<" ";
    plik<<"waga w kg:"<<" ";plik<<waga<<" ";
    plik<<"czy szczepiony Tak - 1, Nie - 0:"<<" "; plik<<szczepiony<<" ";
    plik<<"notatka:"<<" ";
    char *m = new char[notatka.length()+1];
    strcpy(m, notatka.c_str());
    plik<<m<<endl;
    delete [] m;

    cout<<endl;

    plik.close();


}
void Zwierzak::edytuj(){}

void Zwierzak::wyswietl(){

    cout<<"id"<<"\t imie"<<"\twiek"<<"\twaga"<<"\t szczepiony"<<"\tnotatka:"<<endl;
    cout<<id<<"\t"<<" "<<imie<<"\t"<<wiek<<"\t"<<waga<<"\t"<<"  "<<szczepiony<<"\t"<<"         "<<notatka<<endl;

}



