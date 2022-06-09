#ifndef ESTADIA
#define ESTADIA

#include "DTyEnum/Date.h"
#include "DTyEnum/DTEstadia.h"
#include "calificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class estadia{
    private:
        calificacion* calificacionAsoc;
        Date fechaEntrada;
        Date fechaSalida;
        int codigo;
    public:
        estadia(Date,Date,int);
        ~estadia();

        calificacion* getCalificacion(){
            return calificacionAsoc;
        }
        Date getFechaEntrada(){
            return fechaEntrada;
        }
        Date getFechaSalida(){
            return fechaSalida;
        }
        int getCodigo(){
            return codigo;
        }
        void setCalificacion(calificacion* c){
            calificacionAsoc=c;
        }
        void setFechaEntrada(Date fe){
            fechaEntrada=fe;
        }
        void setFechaSalida(Date fs){
            fechaSalida=fs;
        }
        void setCodigo(int c){
            codigo=c;
        }

        DTEstadia* darDatos();//retorna un DTEstadia con los datos
        bool estaActiva();//retorna true sii la reserva esta activa
        void finalizarEstadiaActiva();//termina la estadaia, pre cond: estaActiva true
        void eliminarEstadia();//elimina la instancia de estadia
        DTCalificacion* obtenerCalificacionDeEstadia();//retorna un DTCalificacion de la calificacion asociada
};

#endif