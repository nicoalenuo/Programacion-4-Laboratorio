#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

#include "DTReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReservaIndividual:public DTReserva {
    private:

    public:
        DTReservaIndividual(int, Date, Date, EstadoReserva,float);
        ~DTReservaIndividual();

        int getCodigo();
        void setCodigo(int);
        Date getCheckIn();
        void setCheckIn(Date);
        Date getCheckOut();
        void setCheckOut(Date);
        EstadoReserva getEstado();
        void setEstado(EstadoReserva);
        float getCosto();
        void setCosto(float);
};

#endif