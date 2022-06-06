#ifndef HUESPEDINDIVIDUAL
#define HUESPEDINDIVIDUAL

#include "../usuario/huesped.h"
#include "../estadia.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedIndividual{
    private:
        huesped* huesped;

        estadia* estadia;
    public:
        void finalizarEstadiaActiva(string);
        DTEstadia* darDatosEstadia();
        DTReserva* obtenerReserva();
        void DarBaja();
        bool tieneEstFinalizadaDeHus();
        ~huespedIndividual(); 
};

#endif