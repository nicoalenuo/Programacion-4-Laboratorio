#ifndef HOSTAL
#define HOSTAL

#include "calificacion.h"
#include "DTyEnum/DTHostal.h"
#include "DTyEnum/DTEmpleado.h"
#include "usuario/empleado.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class hostal{
    private:
        map<int,calificacion*> calificaciones;
        map<string,empleado*> empleados;
        map<int,habitacion*> habitaciones;

        string nombre;
        string direccion;
        string telefono;
    public:
        string getNombre(){
            return (*this).nombre;
        }
        string getDireccion(){
            return (*this).direccion;
        }
        string getTelefono(){
            return (*this).telefono;
        }
        void setNombre(string n){
            (*this).nombre=n;
        }
        void setDireccion(string d){
            (*this).direccion=d;
        }
        void setTelefono(string t){
            (*this).telefono=t;
        }
        ~hostal();

        void asignarEmpleado(empleado);
        bool tieneHab(int);
        map<int,DTCalificacion*> obtenerCalsYComs();
        map<int,DTCalificacion*> obtenerCalifSinCom();
        map<int,DTHabitacion*> obtenerHabitacionesDisponiblesEntre(Date checkIn, Date checkOut);
        void removerCalificacion(calificacion c);
        map<int,DTReserva*> obtenerReservas();
        map<int,DTEstadia*> obtenerEstadias();
        DTDatosEstadias obtenerDatos();
        DTReserva obtenerReservaDeEstadia();
        bool trabajaEmpleado(string);
        map<string,DTEmpleado> quitarAsignados(map<string,DTEmpleado>);
        DTHostal darDatos();   
        float darCalifPromedio();  
        map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>);
};

#endif