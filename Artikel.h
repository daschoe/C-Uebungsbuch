//
// Created by daschoe on 10/2/26.
//

#ifndef ÜBUNGSBUCH_ARTIKEL_H
#define ÜBUNGSBUCH_ARTIKEL_H
#include <string>


class Artikel {
private:
    long artikelnummer;
    std::string artikelbezeichnung;
    double verkaufspreis;
public:
    Artikel(long, const std::string&, double);
    ~Artikel();
    void print(); //formatierte Ausgabe
    long getArtikelnummer() {return artikelnummer;}
    void setArtikelnummer(long nr) {artikelnummer=nr;}
    std::string getBezeichnung() {return artikelbezeichnung;}
    void setBezeichnung(std::string bezeichnung) {artikelbezeichnung=bezeichnung;}
    double getPreis() {return verkaufspreis;}
    void setPreis(double preis) {
        if (preis<0.0)
            preis = 0.0;
        verkaufspreis=preis;
    }
};


#endif //ÜBUNGSBUCH_ARTIKEL_H
