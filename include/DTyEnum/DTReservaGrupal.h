#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL

#include "DTReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReservaGrupal:public DTReserva {
    private:
        int CantHuespedes;

    public:
        ~DTReservaGrupal();
        
        int getCantHuespedes() {
            return (*this).CantHuespedes;
        }

        void setCantHuespedes(int CantHuespedes) {
            (*this).CantHuespedes = CantHuespedes;
        }
};

#endif