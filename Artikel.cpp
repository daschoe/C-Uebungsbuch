//
// Created by daschoe on 10/2/26.
//

#include "Artikel.h"

#include <iomanip>
#include <iostream>
//int num_artikel = 0;
int Artikel::num_artikel = 0;

Artikel::Artikel(long nr, const std::string & name, double preis) {
    std::cout<<"Es wird ein Objekt für den Artikel " << name << " angelegt.\nDies ist der "<<++num_artikel<<"-te Artikel."<<std::endl;
    artikelnummer = nr;
    artikelbezeichnung = name;
    verkaufspreis = preis;
}

Artikel::Artikel(const Artikel & other)
    : artikelnummer(other.artikelnummer),
    artikelbezeichnung(other.artikelbezeichnung),
    verkaufspreis(other.verkaufspreis)
{
    ++num_artikel;
    std::cout<<"Es wird ein Objekt für den Artikel " << other.artikelbezeichnung<< " angelegt.\nDies ist der "<<num_artikel<<"-te Artikel."<<std::endl;

}

Artikel::~Artikel() {
    std::cout<<"Das Objekt für den Artikel "<<artikelbezeichnung<<" wird zerstört.\nEs gibt noch "<<--num_artikel<<" Artikel."<<std::endl;
}

void Artikel::print() {
    std::cout<<"Artikelübersicht"<<std::endl;
    std::cout<<std::string(40,'-')<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Artikelnummer:"<<artikelnummer<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Artikelbezeichnung:"<<artikelbezeichnung<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Verkaufspreis:"<<std::fixed<<std::setprecision(2)<<verkaufspreis<<std::endl;
    std::cout<<"Weiter mit 'Enter'"<<std::endl;
    std::cin.get();
}
