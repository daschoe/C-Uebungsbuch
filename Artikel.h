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
    static int num_artikel;
public:
    Artikel(long nr=0, const std::string& name="", double preis=0.0);
    Artikel(const Artikel&);
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
    static int getAnzahl() {return num_artikel;}
};


#endif //ÜBUNGSBUCH_ARTIKEL_H
