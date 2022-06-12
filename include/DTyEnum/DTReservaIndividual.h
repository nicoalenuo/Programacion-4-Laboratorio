#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

#include "DTReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReservaIndividual:public DTReserva {
    private:

    public:
        DTReservaIndividual(int,Date,Date,EstadoReserva,float);
        ~DTReservaIndividual();

        int getCodigo() {
            return (*this).codigo;
        }

        void setCodigo(int codigo) {
            (*this).codigo = codigo;
        }

        Date getCheckIn() {
            return (*this).checkIn;
        }

        void setCheckIn(Date checkIn) {
            (*this).checkIn = checkIn;
        }

        Date getCheckOut() {
            return (*this).checkOut;
        }

        void setCheckOut(Date checkOut) {
            (*this).checkOut = checkOut;
        }

        EstadoReserva getEstado() {
            return (*this).estado;
        }

        void setEstado(EstadoReserva estado) {
            (*this).estado = estado;
        }

        float getCosto() {
            return (*this).costo;
        }

        void setCosto(float costo) {
            (*this).costo = costo;
        }
};

#endif