#include "../include/hostal.h"

hostal::hostal(string nombre, string direccion,string telefono){
    empleados = {};

    (*this).nombre=nombre;
    (*this).direccion=direccion;
    (*this).telefono=telefono;
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
void hostal::agregarHabitacionAMap(habitacion * h){
        (*this).habitaciones.insert(pair<int,habitacion*>((*h).getNumero(),h));
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
map<int,DTReserva*> hostal::obtenerReservas(){
    map<int,habitacion*>::iterator it;
    map<int,DTReserva*> Resultado;
    for (it=habitaciones.begin() ; it!=habitaciones.end() ; it++){
        map<int,DTReserva*> ResultadoLocal;
        map<int,DTReserva*>::iterator it2;
        ResultadoLocal =(*(*it).second).obtenerReservas();
        for(it2 = ResultadoLocal.begin(); it2 != ResultadoLocal.end();it2++){
            Resultado.insert(*it2);
        }
    }
    return Resultado;
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
bool hostal::perteneceCalificacion(int Id){
    return calificaciones.find(Id)!= calificaciones.end();
}
bool hostal::trabajaEmpleado(string emailEmpleado){
    return empleados.find(emailEmpleado)!=empleados.end(); 
}
void hostal::removerCalificacion(calificacion* c){
    calificaciones.erase(c->getId());
}