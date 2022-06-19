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
        DTReservaGrupal(int,Date,Date,EstadoReserva,float,int);
        ~DTReservaGrupal();
        
        int getCodigo();
        void setCodigo(int);
        Date getCheckIn();
        void setCheckIn(Date);
        Date getCheckOut();
        void setCheckOut(Date);
        EstadoReserva getEstado();
        void setEstado(EstadoReserva);
        int getCantHuespedes();
        void setCantHuespedes(int);
        float getCosto();
        void setCosto(float);
};

#endif