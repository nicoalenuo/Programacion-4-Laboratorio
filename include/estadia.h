#ifndef ESTADIA
#define ESTADIA

#include "DTyEnum/Date.h"
#include "calificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class estadia{
    private:
        calificacion* calificacion;

        Date fechaEntrada;
        Date fechaSalida;
        int codigo;
    public:
        Date getFechaEntrada(){
            return fechaEntrada;
        }
        Date getFechaSalida(){
            return fechaSalida;
        }
        int getCodigo(){
            return codigo;
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
        bool estaActiva();
        void finalizarEstadiaActiva();
        void eliminarEstadia();
        DTCalificacion* obtenerCalificacionDeEstadia();
        ~estadia();
};

#endif