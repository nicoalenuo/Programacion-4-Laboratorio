#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include "reserva.h"
#include "Huesped-Grupal.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <set>

class grupal:public reserva{
    private:
        set<huespedGrupal*> huesGrup;

        int cantHuespedes;
    public:
        int getCodigo();
        Date getCheckIn();
        Date getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        int getCantHuespedes();
        void setCodigo(int);
        void setCheckIn(Date);
        void setCheckOut(Date);
        void setEstado(EstadoReserva);
        void setCosto(float);
        void setCantHuespedes(int);
        
};

#endif