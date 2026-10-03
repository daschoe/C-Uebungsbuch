//
// Created by daschoe on 10/2/26.
//

#ifndef ÜBUNGSBUCH_DATUM_H
#define ÜBUNGSBUCH_DATUM_H
#include <string>


class Datum {
private:
    int tag, monat, jahr;

public:
    void init(int tag, int monat, int jahr);
    void init(void);
    void print(void);
    //Ab Aufgabe 13
    Datum();
    Datum(int tag, int monat, int jahr);
    void setDatum();
    void setDatum(int tg, int mn, int jr);
    int getTag() const;
    int getMonat() const;
    int getJahr() const;
    bool isEqual(const Datum&) const;
    bool isLess(const Datum&) const;
    const std::string& asString() const;
    void print() const;

};

inline bool isLeapYear(int jahr) {
    return ((jahr%4 == 0 && jahr%100 != 0) || jahr%400 == 0);
}

#endif //ÜBUNGSBUCH_DATUM_H
