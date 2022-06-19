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
        DTCalificacion* getDatosCalificacion();
        DTEstadia* getDatosEstadia();
        void setDatosCalificacion(DTCalificacion* dtc);
        void setDatosEstadia(DTEstadia* dte);
        void eliminarSuscripto(IObserver*);
        void agregarSuscripto(IObserver*);
        void eliminarCalificacion(int);
        map<int,DTEstadia*> obtenerEstadiasHuesped(string);
        void agregarCalificacion(string,string,int,int);
        void liberarMemoria();
        void eliminarCalificacion();
        DTCalificacion* obtenerCalificacion(DTEstadia*);
        void RegistrarEstadia(string, int);
        void ingresarRespuesta(string,int);
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