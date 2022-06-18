#ifndef ICONTROLADORCALIFICACION
#define ICONTROLADORCALIFICACION

#include "../DTyEnum/DTHostal.h"
#include "../hostal.h"
#include "../DTyEnum/DTReserva.h"
#include "../DTyEnum/DTHabitacion.h"
#include "../DTyEnum/DTCalificacion.h"
#include "../DTyEnum/DTEstadia.h"
#include "../DTyEnum/DTEmpleado.h"
#include "../DTyEnum/DTRespuesta.h"
#include "../calificacion.h"
#include "../estadia.h"
#include "../calificacion.h"
#include "../usuario/IObserver.h"
#include "../usuario/empleado.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>


class IControladorCalificacion {
    private:
        virtual void notificarSuscriptos(string,int,string)=0;
    public:
        virtual ~IControladorCalificacion()=0; //AGREGADO

        virtual void agregarSuscripto(IObserver*)=0;
        virtual void eliminarSuscripto(IObserver*)=0;
        virtual DTCalificacion* getDatosCalificacion()=0;
        virtual DTEstadia* getDatosEstadia()=0;
        virtual void eliminarCalificacion(int)=0;
        virtual void setDatosCalificacion(DTCalificacion*)=0;
        virtual void setDatosEstadia(DTEstadia*)=0;
        virtual map<int,DTEstadia*> obtenerEstadiasHuesped(string)=0;
        virtual void agregarCalificacion(string,string,int)=0;
        virtual map<int,DTCalificacion*> obtenerCalificaciones(string)=0;
        virtual void liberarMemoria()=0;
        virtual void eliminarCalificacion()=0;
        virtual void quitarEstadia(int)=0;
        virtual void RegistrarEstadia(DTHostal*, string, DTReserva*, DTEstadia*)=0;
        virtual void ingresarRespuesta(string,DTCalificacion*)=0;
        virtual float obtenerPromocionDeEstadia()=0;
        virtual int obtenerCodigoDeEstadia()=0;
        virtual DTCalificacion* obtenerCalificacionDeEstadia()=0;
        virtual DTCalificacion* obtenerCalificacion(DTEstadia*)=0;
        virtual DTRespuesta* obtenerRespuesta(DTCalificacion*)=0;
        virtual void agregarCalificacionAMap(calificacion*)=0;
        virtual void agregarEstadiaAMap(estadia*)=0;
};

#endif