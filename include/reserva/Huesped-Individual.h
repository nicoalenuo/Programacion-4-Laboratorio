#ifndef HUESPEDINDIVIDUAL
#define HUESPEDINDIVIDUAL

#include "../usuario/huesped.h"
#include "../estadia.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedIndividual{
    private:
        huesped* huespedAsoc;
        estadia* estadiaAsoc;
    public:
        ~huespedIndividual();
        huespedIndividual();
        huesped* getHuesped(){
            return huespedAsoc;
        }
        estadia* getEstadia(){
            return estadiaAsoc;
        }
        void setHuesped(huesped* h){
            huespedAsoc=h;
        }
        void setEstadia(estadia* h){
            estadiaAsoc=h;
        }
        void finalizarEstadiaActiva(string);
        DTEstadia* darDatosEstadia();
        DTReserva* obtenerReserva();
        void DarBaja();
        bool tieneEstFinalizadaDeHus(); 
};

#endif