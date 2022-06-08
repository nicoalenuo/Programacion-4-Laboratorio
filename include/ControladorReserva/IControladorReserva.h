#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include "../DTyEnum/DTReservaGrupal.h"
#include "../DTyEnum/DTReservaIndividual.h"
#include "../hostal.h"
#include "../DTyEnum/DTReserva.h"
#include "../DTyEnum/DTHabitacion.h"
#include "../DTyEnum/DTCalificacion.h"
#include "../DTyEnum/DTEstadia.h"
#include "../DTyEnum/DTEmpleado.h"
#include "../DTyEnum/Date.h"
#include "../DTyEnum/DTHuesped.h"
#include "../DTyEnum/DTHostal.h"
#include "../reserva/reserva.h"
#include "../reserva/individual.h"
#include "../reserva/grupal.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class IControladorReserva{
    public:
        virtual ~IControladorReserva()=0; //AGREGADO
        //AQUI DECIA OTRA VEZ FINALIZAR ESTADIA ACTIVA
        virtual void ingresarDatosReserva(DTHostal*, Date, Date)=0;
        virtual map<int,DTHabitacion*> obtenerHabitacionesDisponibles()=0;
        virtual void EscogerHabitacion(DTHabitacion*)=0;
        virtual DTHuesped* DesignarPropietarioDeReserva(DTHuesped*)=0;
        virtual void IngresarHuespedEnReserva(DTHuesped*)=0;
        virtual void CancelarReserva()=0;
        virtual void confirmarReserva()=0; 
        virtual map<int,DTReserva*> ListarReservasNoCanceladasDeHuesped(DTHostal*, string)=0;
        virtual void confirmarBaja(DTHostal*, int)=0;
        virtual void finalizarEstadiaActiva(string, string)=0;
        virtual map<string,string> mostrarReserva(DTReserva*)=0;
        virtual int obtenerNumeroDeHabitacion(DTHabitacion*)=0;
        virtual map<string,string> obtenerNombresDeReserva(DTReservaGrupal*)=0;
        virtual map<int,DTEstadia*> obtenerEstadiaHuesped(string)=0;
};

#endif