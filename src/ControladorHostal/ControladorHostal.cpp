#include "../../include/ControladorHostal/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::~ControladorHostal(){
    datosHostal = NULL;
    datosHabitacion = NULL;
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

hostal* ControladorHostal::DarHostalDeHabitacion(habitacion* hab){
    map<string,hostal*>::iterator it;
    bool pr = false;
    hostal* Solucion = NULL;
    it = hostales.begin();
    while(it != hostales.end() && !pr){
        pr = (*it).second->tieneHab(hab->getNumero());
        if(pr) {
            Solucion= (*it).second;
        }
        it++;
    }
    return Solucion;
}

habitacion * ControladorHostal::getHab(DTHabitacion* DTH){
    map<int,habitacion*>::iterator it;
    it =  habitaciones.find(DTH->getNumero());
   return (*it).second;
}

map<int,DTEstadia*> ControladorHostal::obtenerEstadiasDeHostal(){
    map<string,hostal*>::iterator it;
    it = hostales.find(datosHostal->getNombre());
    hostal* h= (*it).second;
    map<int,DTEstadia*> dte;
    dte= h->obtenerEstadias();
    return dte;
}

map<int,DTReserva*> ControladorHostal::ListarReservas(DTHostal* Hos){
    map<int,DTReserva*> Resultado;
    map<string,hostal*>::iterator it;
    map<int,DTReserva*>::iterator it2;
    for(it = hostales.begin(); it != hostales.end();it++){
        map<int,DTReserva*> ReservasLocales;  
        hostal* ho = ((*it)).second;
        ReservasLocales = (*ho).obtenerReservas();
        for(it2 = ReservasLocales.begin(); it2 != ReservasLocales.end(); it2++){
            Resultado.insert(*it2);
        }

    }
    return Resultado;
}

void ControladorHostal::quitarCalificacionDeHostal(int id){
    map<string,hostal*>::iterator it;
    for (it=hostales.begin() ; it!=hostales.end() ; it++)
        (*(*it).second).quitarSiTieneCalificacion(id);
}

map<int,DTCalificacion*> ControladorHostal::obtenerCalificaciones(string empleado){
    map<int,DTCalificacion*> send;
    bool aux = false;
    map<string,hostal*>::iterator it = (*this).hostales.begin();
    while(it != (*this).hostales.end() && aux != true){
        if(it->second->trabajaEmpleado(empleado)){
            send = it->second->obtenerCalifSinCom();
            aux = true;
        }
        ++it;
    }
    return send;
}

map<int,DTCalificacion*> ControladorHostal::obtenerCalificacionesDeHostal(){//precondicion, existe DTHostal en memoria
    string nombre= datosHostal->getNombre();
    return obtenerCalificacionesYComentarios(nombre);
}

map<int,DTReserva*> ControladorHostal::obtenerReservasDeHostal(){
    map<int,DTReserva*> reservas;
    hostal* h= obtenerHostal(datosHostal);
    reservas= h->obtenerReservas();
    return reservas;
}

void ControladorHostal::liberarMemoria(){
    if (datosHostal!=NULL){
        delete datosHostal;
        datosHostal=NULL;
    }
    if (datosHabitacion!=NULL){
        delete datosHabitacion;
        datosHabitacion=NULL;
    }
}

void ControladorHostal::IngresarDatosHab(DTHabitacion* dthab){
    datosHabitacion = dthab;
}

void ControladorHostal::confirmarAltaHostal(){
    hostal* ph = new hostal(datosHostal->getNombre(), datosHostal->getDireccion(), datosHostal->getTelefono());
    agregarHostalAMap(ph);
}

void ControladorHostal::confirmarAltaHabitacion(){
    habitacion * Phab = new habitacion(datosHabitacion->getNumero(), datosHabitacion->getPrecio(),datosHabitacion->getCapacidad()); ;
    string hostalElegido = datosHostal->getNombre();
    hostal* h = (*hostales.find(hostalElegido)).second;
    h->agregarHabitacionAMap(Phab);
    agregarHabitacionAMap(Phab);  
}

hostal* ControladorHostal::obtenerHostal(DTHostal* dth){
    map<string,hostal*>::iterator it = (*this).hostales.find(dth->getNombre());
    return it->second;
}