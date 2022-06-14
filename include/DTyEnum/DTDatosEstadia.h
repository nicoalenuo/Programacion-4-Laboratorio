#ifndef DTDATOSESTADIA
#define DTDATOSESTADIA

#include "DTHostal.h"
#include "DTHuesped.h"
#include "DTHabitacion.h"
#include "Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTDatosEstadia {
    private:
        DTHostal* hostal;
        DTHuesped* huesped;
        DTHabitacion* habitacion;
        Date checkIn;
        Date* checkOut;
    public:
        DTDatosEstadia(DTHostal*,DTHabitacion*,DTHuesped*,Date,Date*);
        ~DTDatosEstadia();
        
        DTHostal* getHostalDeEstadia(){
            return (*this).hostal;
        }
        DTHuesped* getHuespedDeEstadia(){
            return (*this).huesped;
        }
        DTHabitacion* getHabitacionDeEstadia(){
            return (*this).habitacion;
        }
        Date getFechaEntradaDeEstadia(){
            return (*this).checkIn;
        }
        Date* getFechaSalidaDeEstadia(){
            return (*this).checkOut;
        }

        void setHostal(DTHostal* host){
            (*this).hostal = host;
        }

        void setHuesped(DTHuesped* hues){
            (*this).huesped = hues;
        }
//ACA LO CAMBIE
        void setHabitacion(DTHabitacion* hab){
            (*this).habitacion = hab;
        }

        void setCheckIn(Date inicio){
            (*this).checkIn = inicio;
        }

        void setCheckOut(Date* final){
            (*this).checkOut = final;
        }
};

#endif