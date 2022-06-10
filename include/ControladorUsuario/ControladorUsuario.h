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
        void obtenerNombreUsuario(DTUsuario*);
        void obtenerEmailUsuario(DTUsuario*);
        DTHuesped* obtenerHuespedConEmail(string);
        DTEmpleado* obtenerEmpleadoConEmail(string);
        map<string,DTEmpleado*> obtenerEmpleadosNoAsignados();
        map<string,DTEmpleado*> obtenerEmpleados();
        set<DTNotificacion*> consultarNotificaciones(string);
        DTUsuario* devolverDatos();
        map<string,DTHuesped*> obtenerHuespedes();
        void AsignarEmpleadoAHostal(string);
    map<string,DTUsuario*> obtenerUsuarios(){
        map<string,DTUsuario*> usuarios={};
        map<string,DTEmpleado*> datosEmpleados=obtenerEmpleados();
        map<string,DTHuesped*> datosHuespedes=obtenerHuespedes();
        map<string,DTEmpleado*>::iterator it1;
        map<string,DTHuesped*>::iterator it2;
        for (it1=datosEmpleados.begin() ; it1!=datosEmpleados.end() ; it1++){
            DTEmpleado* dte= (*it1).second;
            usuarios.insert(pair<string,DTUsuario*>((*it1).first,dte));
        }
        for (it2=datosHuespedes.begin() ; it2!=datosHuespedes.end() ; it2++){
            DTHuesped* dth = (*it2).second;
            usuarios.insert(pair<string,DTUsuario*>((*it2).first,dth));
        }
        return usuarios;
    }
        void liberarUsuario();
        void suscribirEmpleado(string);
        //Cosas que agregue
        void desuscribirEmpleado(string);
        void agregarEmpleadoAMap(empleado* e){
            empleados.insert(pair<string,empleado*>((*e).getEmail(),e));
        }
        
        void agregarHuespedAMap(huesped* h){
            huespedes.insert(pair<string,huesped*>((*h).getEmail(),h));
        }
};

#endif