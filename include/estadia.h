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
        Date* fechaSalida;
        int codigo;
    public:
        estadia(int);
        ~estadia();

        calificacion* getCalificacion();
        Date getFechaEntrada();
        Date* getFechaSalida();
        int getCodigo();
        void setCalificacion(calificacion*);
        void setFechaEntrada(Date);
        void setFechaSalida(Date*);
        void setCodigo(int);

        DTEstadia* darDatos();
        bool estaActiva();
        void finalizarEstadiaActiva();
        void eliminarEstadia();
        DTCalificacion* obtenerCalificacionDeEstadia();
};

#endif