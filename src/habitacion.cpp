#include "../include/habitacion.h"
#include "../include/fabrica.h"
void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
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
hostal* habitacion::darHostal(){
        fabrica* Fab =fabrica::getInstance();
        IControladorHostal* CH = (*Fab).getIControladorHostal();
        return CH->DarHostalDeHabitacion(this);
}
map<int,DTReserva*>habitacion::obtenerReservas(){
        map<int,DTReserva*> Resultado;
        map<int,reserva*>::iterator it;
        for(it = reservas.begin(); it != reservas.end();it++){
            Resultado.insert(pair<int,DTReserva*>((*(*it).second).getCodigo(), ((*it).second)->getDTReserva()));
        }
        return Resultado;
}
DTHabitacion* habitacion::darDatos(){
    DTHabitacion* resultado = new DTHabitacion((*this).numero , (*this).precio , (*this).capacidad);
    return resultado;
}