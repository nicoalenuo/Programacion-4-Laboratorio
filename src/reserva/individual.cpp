#include "../../include/reserva/individual.h"
#include "../../include/fabrica.h"

individual::individual(int codigo,Date checkIn,Date checkOut,EstadoReserva estado,float costo){
    (*this).codigo=codigo;
    (*this).checkIn=checkIn;
    (*this).checkOut=checkOut;
    (*this).estado=estado;
    (*this).costo=costo;
    (*this).huesInd=NULL;
}
individual::~individual(){
}
DTReservaIndividual* darDatos(){
    return NULL;
}
void individual::finalizarSiEsReservaBuscada(string emailHuesped,string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    
    int nHab = (*getHabitacion()).getNumero();
    bool t=(*ch).existeHabEnHostal(nHab,nombreHostal);

    if (t){
        huespedIndividual* hi = getHuespedIndividual();
        (*hi).finalizarEstadiaActiva(emailHuesped);
    }
}
bool individual::perteneceHusped(string){
    return false;
}
string individual::getTipoReserva(){
    return "";
}
void individual::darBajaReserva(){

}
map<int, DTEstadia*> individual::obtenerEstadias(){
    map<int, DTEstadia*> send;
    return send;
}
DTEstadia* individual::obtenerEstadia(){
    return NULL;
}
DTReserva* individual::obtenerResrvaDeEst(){
    return NULL;
}
bool individual::tieneEstadiaFinalizadaDeHuesped(string email){
    return huesInd->tieneEstFinalizadaDeHus(email);
}
DTEstadia* individual::darEstadiaDeHuesped(string email){
    if(tieneEstadiaFinalizadaDeHuesped(email)==true){
        DTEstadia* est = huesInd->darDatosEstadia();
        return est;
    }else{ return NULL; }
}

