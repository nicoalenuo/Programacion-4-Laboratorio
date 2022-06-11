#include "../../include/ControladorHostal/ControladorHostal.h"
#include "../../include/DTyEnum/DTHabitacion.h"
#include "../../include/DTyEnum/DTHostal.h"


ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::~ControladorHostal(){
}

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

void ControladorHostal::asignarEmpleadoElegido(empleado* e){
    hostal* h = (*hostales.find((*datosHostal).getNombre())).second;
    cout << (*h).getNombre() << endl;
    (*h).asignarEmpleado(e);
}

map<string,DTHostal*> ControladorHostal::obtenerTop3Hostales(){
    map<string,DTHostal*> hostales=obtenerHostales();
    map<string,DTHostal*> resultado={};
    map<string,DTHostal*>::iterator it;
    DTHostal* mayorProm;

    while (resultado.size()<3 && !hostales.empty()){
        mayorProm = (*hostales.begin()).second;
        for (it=hostales.begin() ; it!=hostales.end() ; it++){
            if ((*mayorProm).getCalificacionPromedio() < (*(*it).second).getCalificacionPromedio()){
                mayorProm=(*it).second;
            }
        }
        hostales.erase((*mayorProm).getNombre());
        resultado.insert(pair<string,DTHostal*>((*mayorProm).getNombre(),mayorProm));
    }
    for (it=hostales.begin() ; it!=hostales.end() ; it++)
        delete (*it).second;

    return resultado;
}

map<int,DTCalificacion*> ControladorHostal::obtenerCalificacionesYComentarios(string nombreHostal){
    hostal* h=(*hostales.find(nombreHostal)).second;
    map<int,DTCalificacion*> resultado = (*h).obtenerCalsYComs();
    return resultado;
}

bool ControladorHostal::existeHabEnHostal(int nHab,string nombreHostal){
    hostal* h = (*hostales.find(nombreHostal)).second;
    return (*h).tieneHab(nHab);
}

void ControladorHostal::FinalizarAsignacionDeEmpleados(){
    if (datosHostal!=NULL){
        delete datosHostal;
        datosHostal=NULL;
    }
}

void ControladorHostal::cancelarFinalizarEstadiaActiva(){
    if (datosHostal!=NULL){
        delete datosHostal;
        datosHostal=NULL;
    }
}

void ControladorHostal::IngresarDatosHostal(DTHostal* dth){
    datosHostal=dth;
}

hostal* ControladorHostal::obtenerHostal(DTHostal*){return NULL;}

void ControladorHostal::confirmarAltaHostal(){
    hostal * h = new hostal(datosHostal->getNombre(), datosHostal->getDireccion(), datosHostal->getTelefono());
    agregarHostalAMap(h);
    delete datosHostal;
    datosHostal = NULL;
}

void ControladorHostal::cancelarAltaHostal(){
    delete datosHostal;
    datosHostal = NULL;
}

void ControladorHostal::liberarDatosHostal(){
    delete datosHostal;
    datosHostal = NULL;
}

void ControladorHostal::IngresarDatosHab(DTHabitacion* dthab){
    datosHabitacion = dthab;
}


void ControladorHostal::cancelarAltaHabitacion(){
    delete datosHabitacion;
    datosHabitacion = NULL;
}

void ControladorHostal::confirmarAltaHabitacion(){
    habitacion * hab = new habitacion(datosHabitacion->getNumero(), datosHabitacion->getPrecio(),datosHabitacion->getCapacidad());
    string hostalElegido = datosHostal->getNombre();
    hostal* h = (*hostales.find(hostalElegido)).second;
    h->agregarHab(hab);
    delete datosHabitacion;
    datosHabitacion = NULL;
    
}

        map<int,DTReserva*> ControladorHostal::ListarReservas(DTHostal*){
            map<int,DTReserva*> a;
            return a;
        }
        string ControladorHostal::mostrarHostal(){return "a";}
        float ControladorHostal::obtenerPromCalificacionesDeHostal(){return 1;}
        map<int,DTCalificacion*> ControladorHostal::obtenerCalificacionesDeHostal(){
            map<int,DTCalificacion*> a;
            return a;
        }
        void ControladorHostal::mostrarHabitacion(DTHabitacion*){}
        map<int,DTReserva*> ControladorHostal::obtenerReservasDeHostal(){
            map<int,DTReserva*> a;
            return a;
        }
        void ControladorHostal::liberarHostal(){}
        map<int,DTEstadia*> ControladorHostal::obtenerEstadiasDeHostal(){
            map<int,DTEstadia*> a;
            return a;
        }
        DTEstadia* ControladorHostal::obtenerDatosEstadia(){return NULL;}
        DTReserva* ControladorHostal::obtenerReservaDeEstadia(){return NULL;}
        void ControladorHostal::liberarHostalEstadia(){}
        map<int,DTCalificacion*> ControladorHostal::obtenerCalificaciones(string){
            map<int,DTCalificacion*> a;
            return a;
        }