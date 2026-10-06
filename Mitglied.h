//
// Created by daschoe on 10/6/26.
//

#ifndef ÜBUNGSBUCH_MITGLIED_H
#define ÜBUNGSBUCH_MITGLIED_H
#include "Datum.h"


class Mitglied {
private:
    int mitgliedsnummer;
    std::string name;
    const Datum geburtstag;
    static Mitglied *ptrVorstand;
public:
    Mitglied(int nr, std::string name, const Datum& geb): geburtstag(geb) {
        mitgliedsnummer = nr;
        this->name = name;
        geb.print();
        geburtstag.print();
    }
    Mitglied(int nr, std::string name, int tag, int monat, int jahr) : mitgliedsnummer(nr), geburtstag(tag, monat, jahr)
    {
        this->name = name;
        geburtstag.print();
    }
    int get_mitgliedsnummer() {return mitgliedsnummer;}
    void set_mitgliedsnummer(int nr) {mitgliedsnummer = nr;}
    std::string get_name() {return name;}
    void set_name(std::string name) {this->name=name;}
    const Datum& get_geburtsdatum() const {return geburtstag;}
    void print();
    static Mitglied* getVostand() {return ptrVorstand;}
    static void setVorstand(Mitglied* m) {ptrVorstand = m;}
};


#endif //ÜBUNGSBUCH_MITGLIED_H
