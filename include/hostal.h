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
        string getNombre(){
            return nombre;
        }
        string getDireccion(){
            return direccion;
        }
        string getTelefono(){
            return telefono;
        }
        void setNombre(string n){
            nombre=n;
        }
        void setDireccion(string d){
            direccion=d;
        }
        void setTelefono(string t){
            telefono=t;
        };

        void asignarEmpleado(empleado*);
        bool tieneHab(habitacion*);
        map<int,DTCalificacion*> obtenerCalsYComs();
        map<int,DTCalificacion*> obtenerCalifSinCom();
        map<int,DTHabitacion*> obtenerHabitacionesDisponiblesEntre(Date, Date);
        void removerCalificacion(calificacion* c);
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
        void agregarCalificacionAMap(calificacion * c){
            calificaciones.insert(pair<int,calificacion*>((*c).getId(),c));
        }
        void agregarEmpleadoAMap(empleado* e){
            empleados.insert(pair<string,empleado*>((*e).getEmail(),e));
        }
        void agregarHabitacionAMap(habitacion* h);
};

#endif