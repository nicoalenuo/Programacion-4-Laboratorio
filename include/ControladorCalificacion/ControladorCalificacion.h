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

        DTCalificacion* datosCalificacion;
        DTEstadia* datosEstadia;
        int MaxCodigoEstadia = 0;
        static ControladorCalificacion* instancia;
        ControladorCalificacion();

        void notificarSuscriptos(string,int,string);
    public:
        static ControladorCalificacion* getInstance();
        ~ControladorCalificacion(); //AGREGADO
        void eliminarSuscripto(empleado*);
        map<int,DTEstadia*> obtenerEstadiasHuesped(string);
        void agregarCalificacion(string,int);
        map<int,DTCalificacion*> obtenerCalificaciones(string);
        void ingresarComentario(string);
        void liberarEstadia();
        void eliminarCalificacion();
        void RegistrarEstadia(DTHostal*, string, DTReserva*, DTEstadia*);
        void ingresarRespuesta(string);
        float obtenerPromocionDeEstadia();
        int obtenerCodigoDeEstadia();
        DTCalificacion* obtenerCalificacionDeEstadia();
        DTRespuesta* obtenerRespuesta(DTCalificacion*);
        void agregarSuscripto(empleado*);
        void agregarCalificacionAMap(calificacion* c){
            calificaciones.insert(pair<int,calificacion*>((*c).getId(),c));
        }
        void agregarEstadiaAMap(estadia * e){
            estadias.insert(pair<int,estadia*>((*e).getCodigo(), e));
        }
        DTEstadia* getDatosEstadia(){
            return (*this).datosEstadia;
        }
        
};

#endif