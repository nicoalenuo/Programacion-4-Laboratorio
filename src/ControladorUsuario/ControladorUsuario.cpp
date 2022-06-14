#include "../../include/ControladorUsuario/ControladorUsuario.h"
#include "../../include/usuario/empleado.h"
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


bool ControladorUsuario::IngresarEmail(string email){ //devuelve true si el mail se ingresó
    bool existe = false;
    fabrica* f = fabrica::getInstance();
    IControladorUsuario* cu = (*f).getIControladorUsuario();
    map<string,DTUsuario*> usuarios = (*cu).obtenerUsuarios();
    map<string,DTUsuario*>::iterator it;
    it = usuarios.begin();
    while(!existe && it != usuarios.end()){
        if (email == ((*it).second)->getMail()){
            existe = true;
        }else{
            it++;
        }
    };
    bool agregado = !existe;
    return agregado; 
}

void ControladorUsuario::cancelarAltaUsuario(){
        delete datosUsuario;
        datosUsuario=NULL;
}

void ControladorUsuario::confirmarAltaUsuario(){
    DTEmpleado* de = dynamic_cast<DTEmpleado*>(datosUsuario);
    if(de!=NULL){
        empleado e(de->getNombre(),de->getMail(),de->getPassword(),de->getTipoCargo());
        empleado * Pe = &e;
        agregarEmpleadoAMap(Pe);
        /*map<string,DTEmpleado*> empleados = obtenerEmpleados();
        map<string,DTEmpleado*>::iterator j = empleados.begin();
        std::cout<<((*j).second)->getNombre() <<std::endl;*/
    }else{
        DTHuesped * dh = dynamic_cast<DTHuesped*>(datosUsuario);
        huesped h(dh->getNombre(), dh->getMail(), dh->getPassword(),dh->getEsFinger());
        huesped * Ph = &h;
        agregarHuespedAMap(Ph);
        /*map<string,DTHuesped*> hues = obtenerHuespedes();
        map<string,DTHuesped*>::iterator j = hues.begin();
        std::cout<<((*j).second)->getNombre() <<std::endl;*/
    };
   
    ///delete datosUsuario;
    //datosUsuario = NULL;

}

string ControladorUsuario::obtenerNombreUsuario(DTUsuario*){return "a";}
string ControladorUsuario::obtenerEmailUsuario(DTUsuario*){return "a";}
DTUsuario* ControladorUsuario::devolverDatos(){return NULL;}
void ControladorUsuario::liberarUsuario(){}
map<string,DTUsuario*> ControladorUsuario::obtenerUsuarios(){
    map<string,DTUsuario*> a;
    return a;
}
