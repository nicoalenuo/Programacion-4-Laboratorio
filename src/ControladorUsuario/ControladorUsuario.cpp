#include "../../include/ControladorUsuario/ControladorUsuario.h"
#include "../../include/fabrica.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::~ControladorUsuario(){
}

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
        dte = (*(*it).second).darDatos();
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
    resultado = (*empleadoBuscado).darDatos();
    return resultado;
}

map<string,DTEmpleado*> ControladorUsuario::obtenerEmpleadosNoAsignados(){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch=(*f).getIControladorHostal();

    map<string,DTEmpleado*> resultado=obtenerEmpleados();
    resultado = (*ch).quitarAsignados(resultado);

    return resultado;
}

void ControladorUsuario::suscribirEmpleado(string emailEmpleado){
    map<string,empleado*>::iterator it;
    it=empleados.find(emailEmpleado);
    empleado* e=(*it).second;
    (*e).suscribirse();
}

void ControladorUsuario::desuscribirEmpleado(string emailEmpleado){
    map<string,empleado*>::iterator it;
    it=empleados.find(emailEmpleado);
    empleado* e=(*it).second;
    (*e).desuscribirse();
}


set<DTNotificacion*> ControladorUsuario::consultarNotificaciones(string emailEmpleado){
    set<DTNotificacion*> resultado;
    map<string,empleado*>::iterator it;
    it=empleados.find(emailEmpleado);
    empleado* e=(*it).second;
    resultado = (*e).darNotificaciones();
    return resultado;
}

void ControladorUsuario::AsignarEmpleadoAHostal(string emailEmpleado){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    empleado* e = (*empleados.find(emailEmpleado)).second;
    (*ch).asignarEmpleadoElegido(e);
}


        void ControladorUsuario::IngresarEmail(string){}
        void ControladorUsuario::cancelarAltaUsuario(){}
        void ControladorUsuario::confirmarAltaUsuario(){}
void ControladorUsuario::obtenerNombreUsuario(DTUsuario* dtu){
    cout << dtu->getNombre() << endl;
}
void ControladorUsuario::obtenerEmailUsuario(DTUsuario* dtu){
    cout << dtu->getMail() << endl;
}
        DTUsuario* ControladorUsuario::darDatos(){return NULL;}
        void ControladorUsuario::liberarUsuario(){}

map<string,DTUsuario*> ControladorUsuario::obtenerUsuarios(){
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
    // en interfaz se retorna un elemento del map usuarios
    return usuarios;
}