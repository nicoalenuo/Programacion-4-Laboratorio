#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "reserva.h"
#include "Huesped-Individual.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class individual:public reserva{
    private:
        huespedIndividual* huesInd;
    public:
        int getCodigo();
        Date getCheckIn();
        Date getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        void setCodigo(int);
        void setCheckIn(Date);
        void setCheckOut(Date);
        void setEstado(EstadoReserva);
        void setCosto(float);
};

#endif