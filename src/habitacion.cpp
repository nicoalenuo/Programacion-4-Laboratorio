#include "../include/habitacion.h"
#include "../include/fabrica.h"

void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}

habitacion::~habitacion(){
}

habitacion::habitacion(int numero, float precio, int capacidad){
        (*this).numero = numero;
        (*this).precio = precio;
        (*this).capacidad = capacidad;
}

hostal* habitacion::darHostal(){
        fabrica* Fab =fabrica::getInstance();
        IControladorHostal* CH = (*Fab).getIControladorHostal();
        return CH->DarHostalDeHabitacion(this);
}

DTHabitacion* habitacion::darDatos(){
    DTHabitacion* resultado = new DTHabitacion((*this).numero , (*this).precio , (*this).capacidad);
    return resultado;
}

int habitacion::getNumero(){
    return numero;
}

bool habitacion::disponibleEn(Date CheckIn,Date CheckOut){
        map<int, reserva *>:: iterator it;
        bool Resultado = true;
        it=reservas.begin();
        while(Resultado && it !=reservas.end()){
                Date ChI = ((*it).second)->getCheckIn();
                Date ChO = ((*it).second)->getCheckOut();
                Resultado = (CheckIn > CheckOut || CheckOut < ChI);
                it++;
        }
        return Resultado;
}

map<int,DTEstadia*> habitacion::obtenerEstadias(){
        map<int,DTEstadia*> e, aux;
        map<int,DTEstadia*>::iterator ite;
        map<int,reserva*>::iterator itr;
        for(itr= reservas.begin(); itr!=reservas.end();itr++){
               aux = (*itr).second->obtenerEstadias();
               for(ite= aux.begin(); ite!=aux.end();ite++){
                        e.insert(pair<int,DTEstadia*>((*ite).first,(*ite).second));
               }
        }       
        return e;
}

map<int,DTReserva*> habitacion::obtenerReservas(){
        map<int,DTReserva*> Resultado;
        map<int,reserva*>::iterator it;
        for(it = reservas.begin(); it != reservas.end();it++){
            Resultado.insert(pair<int,DTReserva*>((*(*it).second).getCodigo(), ((*it).second)->getDTReserva()));
        }
        return Resultado;
}

void habitacion::darBajaReserva(int c){
        reservas.erase(c);
}