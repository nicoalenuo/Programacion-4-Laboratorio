#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

#include "../DTyEnum/DTHostal.h"
#include "../DTyEnum/DTHabitacion.h"
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
#include <set>

class IControladorHostal {
    public:
        virtual ~IControladorHostal()=0; //AGREGADO

        virtual void asignarEmpleadoElegido(empleado*) = 0;
        virtual hostal* obtenerHostal(DTHostal*)=0;
        virtual bool existeHabEnHostal(habitacion*,string)=0;
        virtual map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>)=0;
        virtual void IngresarDatosHostal(DTHostal*)=0;
        virtual void confirmarAltaHostal()=0;
        virtual map<string,DTHostal*> obtenerHostales()=0;
        virtual void IngresarDatosHab(DTHabitacion*)=0;
        virtual void confirmarAltaHabitacion()=0;
        virtual set<DTHabitacion*> obtenerHabitaciones()=0;
        virtual map<int,DTReserva*> ListarReservas(DTHostal*)=0;
        virtual void FinalizarAsignacionDeEmpleados()=0;
        virtual map<string,DTHostal*> obtenerTop3Hostales()=0;
        virtual map<int,DTCalificacion*> obtenerCalificacionesYComentarios(string)=0;
        virtual void cancelarFinalizarEstadiaActiva()=0;
        virtual map<int,DTCalificacion*> obtenerCalificacionesDeHostal()=0;
        virtual map<int,DTReserva*> obtenerReservasDeHostal()=0;
        virtual void liberarMemoria()=0;
        virtual map<int,DTEstadia*> obtenerEstadiasDeHostal()=0;
        virtual map<int,DTCalificacion*> obtenerCalificaciones(string)=0;
        virtual map<string,hostal*> getHostales()=0;
        virtual void agregarHostalAMap(hostal*)=0;
        virtual habitacion* getHabDeHostal(DTHabitacion*)=0;
        virtual hostal* DarHostalDeHabitacion(habitacion*)=0;
        virtual DTHostal* getDatosHostal()=0;
        virtual void quitarCalificacionDeHostal(int)=0;
        virtual DTHabitacion* getDatosHabitacion()=0;
        virtual void setDatosHostal(DTHostal* h)=0;
        virtual void setDatosHabitacion(DTHabitacion* h)=0;
};

#endif