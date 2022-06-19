#ifndef HOSTAL
#define HOSTAL

#include "calificacion.h"
#include "DTyEnum/DTHostal.h"
#include "DTyEnum/DTEmpleado.h"
#include "usuario/empleado.h"
#include "habitacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>
#include <set>

class habitacion;

class hostal{
    private:
        map<int,calificacion*> calificaciones;
        map<string,empleado*> empleados;
        map<int,habitacion*> habitaciones;

        string nombre;
        string direccion;
        string telefono;
    public:
        ~hostal();
        hostal(string,string,string);
        string getNombre();
        string getDireccion();
        string getTelefono();
        void setNombre(string);
        void setDireccion(string);
        void setTelefono(string);

        void asignarEmpleado(empleado*);
        bool tieneHab(habitacion*);
        map<int,DTCalificacion*> obtenerCalsYComs();
        map<int,DTCalificacion*> obtenerCalifSinCom();
        map<int,DTHabitacion*> obtenerHabitacionesDisponiblesEntre(Date, Date);
        void removerCalificacion(calificacion*);
        map<int,DTReserva*> obtenerReservas();
        map<int,DTEstadia*> obtenerEstadias();
        DTDatosEstadia* obtenerDatos();
        DTReserva* obtenerReservaDeEstadia();
        bool trabajaEmpleado(string);
        DTHostal* darDatos();
        void quitarSiTieneCalificacion(int);
        float darCalifPromedio();
        bool tieneHabConNumero(int);
        set<DTHabitacion*> obtenerHabitaciones();
        map<int,DTHabitacion*> obtenerHabitacionesMap();
        habitacion* getHab(DTHabitacion*);
        map<string,DTEmpleado*> obtenerEmpleados();
        map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>);
        void agregarCalificacionAMap(calificacion *);
        void agregarEmpleadoAMap(empleado*);
        void agregarHabitacionAMap(habitacion*);
};

#endif