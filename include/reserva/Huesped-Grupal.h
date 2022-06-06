#ifndef HUESPEDGRUPAL
#define HUESPEDGRUPAL

#include "../usuario/huesped.h"
#include "../estadia.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedGrupal{
    private:
        huesped* huespedAsoc;
        estadia* estadiaAsoc;      
    public:
        ~huespedGrupal();
        huespedGrupal();
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
        bool tieneEstFinalizadaDeHus(string);
        bool esDeHuesped(string);                                                                                                                                                                          
};

#endif