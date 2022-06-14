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

        DTUsuario* datosUsuario;
        DTHuesped* datosHuesped;
        DTEmpleado* datosEmpleado;

        static ControladorUsuario* instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario* getInstance();
        ~ControladorUsuario(); //AGREGADO


        void IngresarDatosUsuario(DTUsuario*);
        void IngresarEmail(string);
        void cancelarAltaUsuario();
        void confirmarAltaUsuario();
        DTHuesped* obtenerHuespedConEmail(string);
        DTEmpleado* obtenerEmpleadoConEmail(string);
        map<string,DTEmpleado*> obtenerEmpleadosNoAsignados();
        map<string,DTEmpleado*> obtenerEmpleados();
        set<DTNotificacion*> consultarNotificaciones(string);
        DTUsuario* devolverDatos();
        map<string,DTHuesped*> obtenerHuespedes();
        void AsignarEmpleadoAHostal(string);
        map<string,DTUsuario*> obtenerUsuarios();
        void liberarMemoria();
        void suscribirEmpleado(string);
        //Cosas que agregue
        void desuscribirEmpleado(string);
        void agregarEmpleadoAMap(empleado* e){
            empleados.insert(pair<string,empleado*>((*e).getEmail(),e));
        }
        
        void agregarHuespedAMap(huesped* h){
            huespedes.insert(pair<string,huesped*>((*h).getEmail(),h));
        }
        huesped* getHuesped(DTHuesped* DTU){
            map<string,huesped*>::iterator it;
            it =  huespedes.find(DTU->getEmail());
            return (*it).second;
        }
};

#endif