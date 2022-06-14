#ifndef CONTROLADORCALIFICACION
#define CONTROLADORCALIFICACION

#include "IControladorCalificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class ControladorCalificacion:public IControladorCalificacion {
    private:
        map<int,calificacion*> calificaciones;
        map<string,IObserver*> observers;
        map<int,estadia*> estadias;
        int MaxCodigoEstadia = 0;
        int idActual=0;

        //Cosas "Recordadas por el sistema"
        DTCalificacion* datosCalificacion;
        DTEstadia* datosEstadia;

        static ControladorCalificacion* instancia;
        ControladorCalificacion();

        void notificarSuscriptos(string,int,string);
    public:
        static ControladorCalificacion* getInstance();
        ~ControladorCalificacion();
        DTCalificacion* getDatosCalificacion(){
            return datosCalificacion;
        }
        DTEstadia* getDatosEstadia(){
            return datosEstadia;
        }
        void setDatosCalificacion(DTCalificacion* dtc){
            datosCalificacion=dtc;
        }
        void setDatosEstadia(DTEstadia* dte){
            datosEstadia=dte;
        }
        void eliminarSuscripto(IObserver*);
        void agregarSuscripto(IObserver*);
        void eliminarCalificacion(int);
        map<int,DTEstadia*> obtenerEstadiasHuesped(string);
        void agregarCalificacion(string,string,int);
        map<int,DTCalificacion*> obtenerCalificaciones(string);
        void liberarMemoria();
        void eliminarCalificacion();
        void RegistrarEstadia(DTHostal*, string, DTReserva*, DTEstadia*);
        void ingresarRespuesta(string,DTCalificacion*);
        float obtenerPromocionDeEstadia();
        int obtenerCodigoDeEstadia();
        void quitarEstadia(int);
        DTCalificacion* obtenerCalificacionDeEstadia();
        DTRespuesta* obtenerRespuesta(DTCalificacion*);
        void agregarCalificacionAMap(calificacion* c){
            calificaciones.insert(pair<int,calificacion*>((*c).getId(),c));
        }
        void agregarEstadiaAMap(estadia * e){
            estadias.insert(pair<int,estadia*>((*e).getCodigo(), e));
        }     
};

#endif