//
// Created by daschoe on 10/6/26.
//

#include "Mitglied.h"

#include <iostream>

Mitglied* Mitglied::ptrVorstand = NULL;

/*Mitglied::Mitglied(int nr, std::string name, const Datum& geb) : geburtstag(geb) {
    mitgliedsnummer = nr;
    this->name = name;
    geb.print();
    geburtstag.print();
}*/

/*Mitglied::Mitglied(int nr, std::string name, int tag, int monat, int jahr) : geburtstag(tag, monat, jahr){
    mitgliedsnummer = nr;
    this->name = name;
    geburtstag.print();
}*/

void Mitglied::print() {
    std::cout<<"Mitgliedskarte"<<std::endl;
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Geburtstag: ";
    geburtstag.print();
    std::cout<<"Mitgliedsnummer: "<<mitgliedsnummer<<"\n\n"<<std::endl;
}
