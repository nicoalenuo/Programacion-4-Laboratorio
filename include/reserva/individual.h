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
        int getCodigo(){
            return codigo;
        }
        Date getCheckIn(){
            return checkIn;
        }
        Date getCheckOut(){
            return checkOut;
        }
        EstadoReserva getEstado(){
            return estado;
        }
        float getCosto(){
            return costo;
        }
        void setCodigo(int c){
            codigo=c;
        }
        void setCheckIn(Date ci){
            checkIn=ci;
        }
        void setCheckOut(Date co){
            checkOut=co;
        }
        void setEstado(EstadoReserva e){
            estado=e;
        }
        void setCosto(float c){
            costo=c;
        }
        ~individual();
};

#endif