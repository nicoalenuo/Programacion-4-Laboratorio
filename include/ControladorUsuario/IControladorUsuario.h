#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include "../DTyEnum/DTHostal.h"
#include "../hostal.h"
#include "../DTyEnum/DTCalificacion.h"
#include "../DTyEnum/DTNotificacion.h"
#include "../DTyEnum/DTHuesped.h"
#include "../DTyEnum/DTEmpleado.h"
#include "../DTyEnum/DTUsuario.h"
#include "../usuario/usuario.h"
#include "../usuario/empleado.h"
#include "../usuario/huesped.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>
#include <set>


class IControladorUsuario {
    public:
        virtual ~IControladorUsuario()=0;
        virtual void IngresarDatosUsuario(DTUsuario*)=0;
        virtual bool IngresarEmail(string)=0;
        virtual void confirmarAltaUsuario()=0;
        virtual DTHuesped* obtenerHuespedConEmail(string)=0;
        virtual DTEmpleado* obtenerEmpleadoConEmail(string)=0;
        virtual map<string,DTEmpleado*> obtenerEmpleadosNoAsignados()=0;
        virtual map<string,DTEmpleado*> obtenerEmpleados()=0;
        virtual set<DTNotificacion*> consultarNotificaciones(string)=0;
        virtual map<string,DTHuesped*> obtenerHuespedes()=0;
        virtual void AsignarEmpleadoAHostal(string)=0;
        virtual map<string,DTUsuario*> obtenerUsuarios()=0;
        virtual void liberarMemoria()=0;
        virtual void suscribirEmpleado(string)=0;
        virtual void desuscribirEmpleado(string)=0;
        virtual void agregarEmpleadoAMap(empleado*)=0;
        virtual void agregarHuespedAMap(huesped*)=0;
        virtual huesped* getHuesped(DTHuesped*)=0;
        virtual DTUsuario* obtenerDatosUsuario()=0;
};

#endif