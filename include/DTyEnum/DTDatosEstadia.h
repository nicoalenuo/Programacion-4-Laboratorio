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
        
        DTHostal* getHostalDeEstadia();
        DTHuesped* getHuespedDeEstadia();
        DTHabitacion* getHabitacionDeEstadia();
        Date getFechaEntradaDeEstadia();
        Date* getFechaSalidaDeEstadia();
        void setHostal(DTHostal*);
        void setHuesped(DTHuesped*);
        void setHabitacion(DTHabitacion*);
        void setCheckIn(Date);
        void setCheckOut(Date*);
};

#endif