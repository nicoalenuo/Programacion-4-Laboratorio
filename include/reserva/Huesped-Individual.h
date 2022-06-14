#ifndef HUESPEDINDIVIDUAL
#define HUESPEDINDIVIDUAL

#include "../usuario/huesped.h"
#include "../estadia.h"
//Cosas que agregue
#include "../DTyEnum/DTReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedIndividual{
    private:
        huesped* huespedAsoc;
        estadia* estadiaAsoc;
    public:
        ~huespedIndividual();
        huespedIndividual(huesped* hues);
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
        void darBaja();
        bool tieneEstFinalizadaDeHus(string); 
        bool esDeHuesped(string);    
};

#endif