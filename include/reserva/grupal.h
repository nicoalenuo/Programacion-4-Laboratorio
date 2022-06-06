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
        int getCantHuespedes(){
            return cantHuespedes;
        }
        void setCodigo(int c){
            codigo=c;
        }
        void setCheckIn(Date d){
            checkIn=d;
        }
        void setCheckOut(Date d){
            checkOut=d;
        }
        void setEstado(EstadoReserva er){
            estado=er;
        }
        void setCosto(float c){
            costo=c;
        }
        void setCantHuespedes(int ch){
            cantHuespedes=ch;
        }

        ~grupal();
        
};

#endif