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
DTHabitacion* habitacion::darDatos(){
    DTHabitacion* resultado = new DTHabitacion((*this).numero , (*this).precio , (*this).capacidad);
    return resultado;
}