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
        huespedIndividual(huesped*);
        huesped* getHuesped();
        estadia* getEstadia();
        void setHuesped(huesped*);
        void setEstadia(estadia*);

        void finalizarEstadiaActiva(string);
        DTEstadia* darDatosEstadia();
        DTReserva* obtenerReserva();
        void darBaja();
        DTEstadia* obtenerEstadia();
        bool tieneEstFinalizadaDeHus(string); 
        bool esDeHuesped(string);    
        bool tieneEstadia(DTEstadia*);
        DTHuesped* darDatosHuesped();  
};

#endif