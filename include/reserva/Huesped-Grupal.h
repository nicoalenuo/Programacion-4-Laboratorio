#ifndef HUESPEDGRUPAL
#define HUESPEDGRUPAL

#include "../usuario/huesped.h"
#include "../estadia.h"
//Cosas que agregue
#include "../DTyEnum/DTEstadia.h"
#include "../DTyEnum/DTDatosEstadia.h"

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
        DTDatosEstadia* darDatosEstadia();
        DTEstadia* obtenerEstadia();
        void DarBaja();
        bool tieneEstFinalizadaDeHus(string);
        bool esDeHuesped(string);                                                                                                                                                                          
};

#endif