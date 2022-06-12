#include "../include/hostal.h"

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
    cout << "aea" << endl;
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

bool hostal::trabajaEmpleado(string emailEmpleado){
    return empleados.find(emailEmpleado)!=empleados.end(); 
}

float hostal::darCalifPromedio(){
    map<int,calificacion*>::iterator it;
    float resultado=0;
    if(calificaciones.size() != 0){
        for (it=calificaciones.begin() ; it!=calificaciones.end() ; it++){
            calificacion* c= (*it).second;
            resultado=resultado+ c->getPuntuacion();
        }
        return (resultado/calificaciones.size());
    }else{
        return 0;
    }
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