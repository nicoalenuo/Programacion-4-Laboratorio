#ifndef DTRESERVA
#define DTRESERVA

#include "EstadoReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReserva {
    protected:
        int codigo;
        Date checkIn;
        Date checkOut;
        EstadoReserva estado;


	

    public:
        ~DTReserva();
        
        int getCodigo() {
            return (*this).codigo;
        }

        void setCodigo(int codigo) {
            (*this).codigo = codigo;
        }

        public Date getCheckIn() {
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