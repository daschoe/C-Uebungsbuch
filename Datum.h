//
// Created by daschoe on 10/2/26.
//

#ifndef ÜBUNGSBUCH_DATUM_H
#define ÜBUNGSBUCH_DATUM_H


class Datum {
private:
    int tag, monat, jahr;

public:
    void init(int tag, int monat, int jahr);
    void init(void);
    void print(void);

};


#endif //ÜBUNGSBUCH_DATUM_H
