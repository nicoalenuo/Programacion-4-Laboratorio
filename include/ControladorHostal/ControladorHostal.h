#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL

#include "IControladorHostal.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class ControladorHostal:public IControladorHostal {
    private:
        map<string,hostal*> hostales;

        //Cosas "Recordadas por el sistema"
        DTHostal* datosHostal;
        DTHabitacion* datosHabitacion;

        static ControladorHostal* instancia;
        ControladorHostal();
    public:
        static ControladorHostal* getInstance();
        ~ControladorHostal();

        void asignarEmpleadoElegido(empleado*); 
        hostal* obtenerHostal(DTHostal*);
        bool existeHabEnHostal(habitacion*,string);
        map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>);
        void IngresarDatosHostal(DTHostal*);
        void confirmarAltaHostal();
        void liberarMemoria();
        bool existeHabConNumero(int,string);
        map<string,DTHostal*> obtenerHostales();
        map<int,DTHabitacion*> obtenerHabitacionesDeHostal();
        void IngresarDatosHab(DTHabitacion*);
        void confirmarAltaHabitacion();
        bool trabajaEmpleado(string,string);
        map<int,DTReserva*> ListarReservas(DTHostal*);
        map<string,DTHostal*> obtenerTop3Hostales();
        map<string,DTEmpleado*> obtenerEmpleados(string);
        map<int,DTCalificacion*> obtenerCalificacionesYComentarios(string);
        void cancelarFinalizarEstadiaActiva();
        map<int,DTCalificacion*> obtenerCalificacionesDeHostal();
        map<int,DTReserva*> obtenerReservasDeHostal();
        map<int,DTEstadia*> obtenerEstadiasDeHostal();
        set<DTHabitacion*> obtenerHabitaciones();
        DTHostal* hostalEnElQueTrabaja(string);
        map<int,DTCalificacion*> obtenerCalificacionesSinComentar(string);
        void quitarCalificacionDeHostal(int);
        map<string,hostal*> getHostales();
        void agregarHostalAMap(hostal* h);
        habitacion* getHabDeHostal(DTHabitacion*);  
        hostal* DarHostalDeHabitacion(habitacion*);
        DTHostal* getDatosHostal();
        DTHabitacion* getDatosHabitacion();
        void setDatosHostal(DTHostal*);
        void setDatosHabitacion(DTHabitacion*);
};  

#endif