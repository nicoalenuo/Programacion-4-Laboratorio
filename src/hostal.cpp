#include "../include/hostal.h"

hostal::~hostal(){
}

hostal::hostal(string nombre, string direccion,string telefono){
    empleados = {};

    (*this).nombre=nombre;
    (*this).direccion=direccion;
    (*this).telefono=telefono;
}

DTHostal* hostal::darDatos(){
    float calificacionPromedio=0;
    int punt;
    int cant=0;
    map<int,calificacion*>::iterator it;

    for (it=calificaciones.begin() ; it!=calificaciones.end() ; it++){
        punt=(*(*it).second).getPuntuacion();
        calificacionPromedio=calificacionPromedio+punt;
        cant++;
    }
    if (cant!=0)
        calificacionPromedio=calificacionPromedio/cant;
     
    DTHostal* resultado = new DTHostal((*this).nombre , (*this).direccion , (*this).telefono , calificacionPromedio);

    return resultado;
}

map<string,DTEmpleado*> hostal::quitarAsignados(map<string,DTEmpleado*> emps){
    map<string,empleado*>::iterator it;
    for (it=empleados.begin() ; it!=empleados.end() ; it++){
        delete (*emps.find((*it).first)).second;
        emps.erase((*it).first);
    }

    return emps;
}

void hostal::asignarEmpleado(empleado* e){
    empleados.insert(pair<string,empleado*>((*e).getEmail(),e));
}

map<int,DTCalificacion*> hostal::obtenerCalsYComs(){
    map<int,DTCalificacion*> resultado;
    map<int,calificacion*>::iterator it;
    for (it=calificaciones.begin() ; it!=calificaciones.end() ; it++){
        DTCalificacion* c = (*(*it).second).darDatos();
        resultado.insert(pair<int,DTCalificacion*>((*c).getId(),c));
    }
    return resultado;
}

bool hostal::tieneHab(int nHab){
    return habitaciones.find(nHab) != habitaciones.end();
}

void hostal::agregarHabitacionAMap(habitacion* h){
    habitaciones.insert(pair<int,habitacion*>((*h).getNumero(),h));
}

map<int,DTHabitacion*> hostal::obtenerHabitacionesDisponiblesEntre(Date CheckIn, Date CheckOut){
    map<int,DTHabitacion*> Resultado;
    map<int,habitacion*>::iterator it;

    for (it=habitaciones.begin() ; it !=habitaciones.end() ; it++){//Por cada habitacion
        //Por cada reserva
        map<int,habitacion*>::iterator ithab;
        habitacion* Hab = (*it).second;
        if(Hab->disponibleEn(CheckIn,CheckOut)){
            Resultado.insert(pair<int,DTHabitacion*>(Hab->getNumero(),Hab->darDatos()));
        }
    }
    return Resultado;
}

map<int,DTEstadia*> hostal:: obtenerEstadias(){
    map<int,habitacion*>::iterator it;
    map<int,DTEstadia*> habEst, aux;
    map<int,DTEstadia*>::iterator itr;
    for(it=habitaciones.begin(); it!=habitaciones.end();it++){
        habitacion* h= (*it).second;
        aux= h->obtenerEstadias();
        for(itr=aux.begin();itr!=aux.end();itr++){
            habEst.insert(pair<int,DTEstadia*>((*itr).first,(*itr).second));
        }
    }
    return habEst;
}

map<int,DTReserva*> hostal:: obtenerReservas(){
    map<int,habitacion*>::iterator it;
    map<int,DTReserva*> reservas, aux;
    map<int,DTReserva*>::iterator itr;
    for(it=habitaciones.begin(); it!=habitaciones.end();it++){
        habitacion* h= (*it).second;
        aux= h->obtenerReservas();
        for(itr=aux.begin();itr!=aux.end();itr++){
            reservas.insert(pair<int,DTReserva*>((*itr).first,(*itr).second));
        }
    }
    return reservas;
}

bool hostal::trabajaEmpleado(string emailEmpleado){
    return empleados.find(emailEmpleado)!=empleados.end(); 
}

void hostal::quitarSiTieneCalificacion(int id){
    if (calificaciones.find(id) != calificaciones.end()){
        calificaciones.erase(id);
    }
}

map<int,DTCalificacion*> hostal::obtenerCalifSinCom(){
    map<int,DTCalificacion*> send;
    for(map<int,calificacion*>::iterator it=(*this).calificaciones.begin(); it !=(*this).calificaciones.end(); ++it){
        if(it->second->sinRespuesta()){
            DTCalificacion* in = (*(*it).second).darDatos();
            send.insert(pair<int,DTCalificacion*>((*it).first,in));
        }
    }
    return send;
}