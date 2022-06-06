#include "../../include/ControladorHostal/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){
    hostales={};
    habitaciones={};

    datosHostal==NULL;
    datosHabitacion==NULL;
}

ControladorHostal* ControladorHostal::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorHostal();
    return instancia;   
}

map<string,DTHostal*> ControladorHostal::obtenerHostales(){
    map<string,DTHostal*> resultado={};
    map<string,hostal*>::iterator it;
    for (it=hostales.begin() ; it!=hostales.end() ; it++){
        DTHostal* dth;
        dth = (*(*it).second).darDatos();
        resultado.insert(pair<string,DTHostal*>((*it).first,dth));
    }
    return resultado;
}

map<string,DTEmpleado*> ControladorHostal::quitarAsignados(map<string,DTEmpleado*> emps){
    map<string,hostal*>::iterator it;
    for (it=hostales.begin() ; it!=hostales.end() ; it++){
        emps = (*(*it).second).quitarAsignados(emps);
    }
    return emps;
}