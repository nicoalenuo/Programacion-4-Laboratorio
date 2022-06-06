#ifndef DTDATOSESTADIAS
#define DTDATOSESTADIAS

#include "DTHostal.h"
#include "DTHuesped.h"
#include "DTHabitacion.h"
#include "Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTDatosEstadias {
    private:
        DTHostal hostal;
        DTHuesped huesped;
        DTHabitacion habitacion;
        Date checkIn;
        Date checkOut;
    public:
        DTHostal getHostalDeEstadia(){
            return (*this).hostal;
        };
        DTHuesped getHuespedDeEstadia(){
            return (*this).huesped;
        };
        DTHabitacion getHabitacionDeEstadia(){
            return (*this).habitacion;
        };
        Date getFechaEntradaDeEstadia(){
            return (*this).checkIn;
        };
        Date getFechaSalidaDeEstadia(){
            return (*this).checkOut;
        };

        void setHostal(DTHostal host){
            (*this).hostal = host;
        };

        void setHuesped(DTHuesped hues){
            (*this).huesped = hues;
        };

        void setHostal(DTHabitacion hab){
            (*this).habitacion = hab;
        };

        void setHostal(Date inicio){
            (*this).checkIn = inicio;
        };

        void setHostal(Date final){
            (*this).checkOut = final;
        };

        ~DTDatosEstadias();
};

#endif