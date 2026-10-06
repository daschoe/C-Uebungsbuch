//
// Created by daschoe on 10/6/26.
//

#ifndef ÜBUNGSBUCH_AMPEL_H
#define ÜBUNGSBUCH_AMPEL_H
#include <iostream>
#include <unistd.h>

class Ampel
{
public: // Aufzählung für die Klasse Ampel
    enum Status { aus, rot, gruen, gelb };
    enum {gelbzeit=1, gruenzeit=10};
private:
    Status status;
public:
    Ampel( Status s = aus) : status(s) {}
    Status getStatus() const { return status; }
    void setStatus( Status s)
    {
        switch(s)
        { case aus: std::cout << " AUS "; break;
            case rot: std::cout << " ROT "; break;
            case gruen: std::cout << " GRUEN "; break;
            case gelb: std::cout << " GELB "; break;
            default: return;
        }
        status = s;
    }
    inline static void warten(int sek) {
        sleep(sek);
    }
};
#endif //ÜBUNGSBUCH_AMPEL_H
