#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

#include "../DTyEnum/DTHostal.h"
#include "../DTyEnum/DTReserva.h"
#include "../DTyEnum/DTHabitacion.h"
#include "../DTyEnum/DTCalificacion.h"
#include "../DTyEnum/DTEstadia.h"
#include "../DTyEnum/DTEmpleado.h"
#include "../usuario/empleado.h"
#include "../hostal.h"
#include "../habitacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class IControladorHostal {
    public:
        virtual ~IControladorHostal()=0; //AGREGADO

        virtual void asignarEmpleadoElegido(empleado*) = 0;
        virtual hostal* obtenerHostal(DTHostal*)=0;
        virtual bool existeHabEnHostal(int,string)=0;
        virtual map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>)=0;
        virtual void IngresarDatosHostal(DTHostal*)=0;
        virtual void confirmarAltaHostal()=0;
        virtual void cancelarAltaHostal()=0;
        virtual void liberarDatosHostal()=0;
        virtual map<string,DTHostal*> obtenerHostales()=0;
        virtual void IngresarDatosHab(DTHabitacion*)=0;
        virtual void cancelarAltaHabitacion()=0;
        virtual void confirmarAltaHabitacion()=0;
        virtual map<int,DTReserva*> ListarReservas(DTHostal*)=0;
        virtual void FinalizarAsignacionDeEmpleados()=0;
        virtual map<string,DTHostal*> obtenerTop3Hostales()=0;
        virtual map<int,DTCalificacion*> obtenerCalificacionesYComentarios(string)=0;
        virtual void cancelarFinalizarEstadiaActiva()=0;
        virtual string mostrarHostal()=0;
        virtual float obtenerPromCalificacionesDeHostal()=0;
        virtual map<int,DTCalificacion*> obtenerCalificacionesDeHostal()=0;
        virtual void mostrarHabitacion(DTHabitacion*)=0;
        virtual map<int,DTReserva*> obtenerReservasDeHostal()=0;
        virtual void liberarHostal()=0;
        virtual map<int,DTEstadia*> obtenerEstadiasDeHostal()=0;
        virtual DTEstadia* obtenerDatosEstadia()=0;
        virtual DTReserva* obtenerReservaDeEstadia()=0;
        virtual void liberarHostalEstadia()=0;
        virtual map<int,DTCalificacion*> obtenerCalificaciones(string)=0;
        //Cosas que agregue
        virtual map<string,hostal*> getHostales()=0;
        virtual void agregarHostalAMap(hostal*)=0;
        virtual void agregarHabitacionAMap(habitacion*)=0;
        virtual habitacion* getHab(DTHabitacion*)=0;
        virtual hostal* DarHostalDeHabitacion(habitacion*)=0;
        virtual DTHostal* getDatosHostal()=0;
};

#endif