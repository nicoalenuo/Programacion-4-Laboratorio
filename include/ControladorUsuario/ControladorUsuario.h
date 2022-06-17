#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "IControladorUsuario.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>
#include <set>

class ControladorUsuario:public IControladorUsuario {
    private:
        map<string,empleado*> empleados;
        map<string,huesped*> huespedes;

        //Cosas "Recordadas por el sistema"
        DTUsuario* datosUsuario;
        DTHuesped* datosHuesped;
        DTEmpleado* datosEmpleado;

        static ControladorUsuario* instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario* getInstance();
        ~ControladorUsuario(); 


        void IngresarDatosUsuario(DTUsuario*);
        bool IngresarEmail(string);
        void confirmarAltaUsuario();
        DTHuesped* obtenerHuespedConEmail(string);
        DTEmpleado* obtenerEmpleadoConEmail(string);
        map<string,DTEmpleado*> obtenerEmpleadosNoAsignados();
        map<string,DTEmpleado*> obtenerEmpleados();
        set<DTNotificacion*> consultarNotificaciones(string);
        map<string,DTHuesped*> obtenerHuespedes();
        void AsignarEmpleadoAHostal(string);
        map<string,DTUsuario*> obtenerUsuarios();
        void liberarMemoria();
        void suscribirEmpleado(string);
        void desuscribirEmpleado(string);
        void agregarEmpleadoAMap(empleado* e){
            empleados.insert(pair<string,empleado*>((*e).getEmail(),e));
        }
        
        void agregarHuespedAMap(huesped* h){
            huespedes.insert(pair<string,huesped*>((*h).getEmail(),h));
        }
        huesped* getHuesped(DTHuesped* DTH){
            map<string,huesped*>::iterator it;
            it =  huespedes.find(DTH->getEmail());
            return (*it).second;
        }
        DTUsuario* obtenerDatosUsuario(){
            return (*this).datosUsuario;
        }
};

#endif