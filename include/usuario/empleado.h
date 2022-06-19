#ifndef EMPLEADO
#define EMPLEADO

#include "usuario.h"
#include "../DTyEnum/Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <set>

class empleado:public usuario, public IObserver {
    private:
        Cargo TipoCargo;
        set<notificacion*> notificaciones;
        
    public:
        ~empleado();
        empleado(string,string,string,Cargo);

        string getNombre();
        string getEmail();
        string getPassword();
        Cargo getTipoCargo();
        void setNombre(string);
        void setEmail(string);
        void setPassword(string);
        void setTipoCargo(Cargo);

        DTEmpleado* darDatos();
        bool estaAsignado();
        void suscribirse();
        void notificar(string,int,string);
        //Cosas que agregue
        void desuscribirse();
        set<DTNotificacion*> darNotificaciones();
        void agregarNotificacionASet(notificacion*);
};

#endif