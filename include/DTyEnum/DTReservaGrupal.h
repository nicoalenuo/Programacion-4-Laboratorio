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
        DTReservaGrupal(int,Date,Date,EstadoReserva,float,int);//codigo,checkin,checkout, estado, precio,cantHuespedes)
        ~DTReservaGrupal();
        
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

        int getCantHuespedes() {
            return (*this).CantHuespedes;
        }

        void setCantHuespedes(int CantHuespedes) {
            (*this).CantHuespedes = CantHuespedes;
        }        
        float getCosto() {
            return (*this).costo;
        }

        void setCosto(float Costo) {
            (*this).costo = Costo;
        }
};

#endif