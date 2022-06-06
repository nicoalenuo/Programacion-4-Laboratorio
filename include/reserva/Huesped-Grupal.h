#ifndef HUESPEDGRUPAL
#define HUESPEDGRUPAL

#include "../usuario/huesped.h"
#include "../estadia.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedGrupal{
    private:
        huesped* huesped;
        estadia* estadia;
        
    public:
        void finalizarEstadiaActiva(string);
        DTEstadia* darDatosEstadia();
        DTReserva* obtenerReserva();
        void DarBaja();
        bool tieneEstFinalizadaDeHus(string);
        bool esDeHuesped(string);
        ~huespedGrupal();                                                                                                                                                                          
};

#endif