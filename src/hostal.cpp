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