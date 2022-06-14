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
        map<int,habitacion*> habitaciones;

        DTHostal* datosHostal; //Aca se guarda la informacion "recordada por el sistema"
        DTHabitacion* datosHabitacion;

        static ControladorHostal* instancia;
        ControladorHostal();
    public:
        static ControladorHostal* getInstance();
        ~ControladorHostal(); //AGREGADO

        void asignarEmpleadoElegido(empleado*); 
        hostal* obtenerHostal(DTHostal*);
        bool existeHabEnHostal(int,string);
        map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>);
        void IngresarDatosHostal(DTHostal*);
        void confirmarAltaHostal();
        void cancelarAltaHostal();
        void liberarMemoria();
        map<string,DTHostal*> obtenerHostales();
        void IngresarDatosHab(DTHabitacion*);
        void cancelarAltaHabitacion();
        void confirmarAltaHabitacion();
        map<int,DTReserva*> ListarReservas(DTHostal*);
        void FinalizarAsignacionDeEmpleados();
        map<string,DTHostal*> obtenerTop3Hostales();
        map<int,DTCalificacion*> obtenerCalificacionesYComentarios(string);
        void cancelarFinalizarEstadiaActiva();
        string mostrarHostal();
        float obtenerPromCalificacionesDeHostal();
        map<int,DTCalificacion*> obtenerCalificacionesDeHostal();
        void mostrarHabitacion(DTHabitacion*);
        map<int,DTReserva*> obtenerReservasDeHostal();
        map<int,DTEstadia*> obtenerEstadiasDeHostal();
        DTEstadia* obtenerDatosEstadia();
        DTReserva* obtenerReservaDeEstadia();
        hostal* hostalQuePoseeCal(calificacion*);
        map<int,DTCalificacion*> obtenerCalificaciones(string);
        map<string,hostal*> getHostales(){
            return hostales;
        } 
        void agregarHostalAMap(hostal* h){
            hostales.insert(pair<string,hostal*>((*h).getNombre(),h));
        }
        void agregarHabitacionAMap(habitacion * h){
            habitaciones.insert(pair<int,habitacion*>((*h).getNumero(),h));
        }
        habitacion* getHab(DTHabitacion*);  
        hostal* DarHostalDeHabitacion(habitacion*);
        DTHostal* getDatosHostal(){
            return datosHostal;
        }
        DTHabitacion* getDatosHabitacion(){
            return datosHabitacion;
        }
        void setDatosHostal(DTHostal* h){
            datosHostal=h;
        }
        void setDatosHabitacion(DTHabitacion* h){
            datosHabitacion=h;
        }
};  

#endif