#include "../../include/ControladorUsuario/ControladorUsuario.h"
#include "../../include/fabrica.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){
    huespedes={};
    empleados={};

    datosUsuario=NULL;
    datosHuesped=NULL;
    datosEmpleado=NULL;
}

ControladorUsuario* ControladorUsuario::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

void ControladorUsuario::IngresarDatosUsuario(DTUsuario* datos){
    datosUsuario=datos;
}

map<string,DTEmpleado*> ControladorUsuario::obtenerEmpleados(){
    map<string,DTEmpleado*> resultado={};
    map<string,empleado*>::iterator it;
    for (it=empleados.begin() ; it!=empleados.end() ; it++){
        DTEmpleado* dte;
        (*dte)=(*(*it).second).darDatos();
        resultado.insert(pair<string,DTEmpleado*>((*it).first,dte));
    }
    return resultado;
}

map<string,DTHuesped*> ControladorUsuario::obtenerHuespedes(){
    map<string,DTHuesped*> resultado={};
    map<string,huesped*>::iterator it;
    for (it=huespedes.begin() ; it!=huespedes.end() ; it++){
        DTHuesped* dth;
        dth=(*(*it).second).darDatos();
        resultado.insert(pair<string,DTHuesped*>((*it).first,dth));
    }
    return resultado;   
}

DTHuesped* ControladorUsuario::obtenerHuespedConEmail(string email){ //Pre: Existe un huesped con atributo email
    huesped* huespedBuscado = (*huespedes.find(email)).second;
    DTHuesped* resultado;
    resultado = (*huespedBuscado).darDatos();
    return resultado;
}

DTEmpleado* ControladorUsuario::obtenerEmpleadoConEmail(string email){ //Pre: Existe un empleado con atributo email
    empleado* empleadoBuscado = (*empleados.find(email)).second;
    DTEmpleado* resultado;
    (*resultado) = (*empleadoBuscado).darDatos();
    return resultado;
}

map<string,DTEmpleado*> ControladorUsuario::obtenerEmpleados(){
    map<string,DTEmpleado*> resultado;
    map<string,empleado*>::iterator it;
    for (it=empleados.begin() ; it!=empleados.end() ; it++){
        DTEmpleado* dte;
        (*dte)=(*(*it).second).darDatos();
        resultado.insert(pair<string,DTEmpleado*>((*it).first,dte));
    }
}

map<string,DTEmpleado*> ControladorUsuario::obtenerEmpleadosNoAsignados(){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch=(*f).getIControladorHostal();

    map<string,DTEmpleado*> resultado=obtenerEmpleados();
    resultado = (*ch).quitarAsignados(resultado);

    return resultado;
}
