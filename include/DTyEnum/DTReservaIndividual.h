#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

#include "DTReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReservaIndividual:public DTReserva {
    private:

    public:
        DTReservaIndividual(string,string,string);
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
};

#endif