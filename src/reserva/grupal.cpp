#include "../../include/reserva/grupal.h"
#include "../../include/fabrica.h"

grupal::grupal(int codigo,Date checkIn,Date checkOut,EstadoReserva estado,float costo, int cantHuesped){
    (*this).codigo=codigo;
    (*this).checkIn=checkIn;
    (*this).checkOut=checkOut;
    (*this).estado=estado;
    (*this).costo=costo;
    (*this).cantHuespedes=cantHuesped;
    
}
grupal::~grupal(){
}
void grupal::finalizarSiEsReservaBuscada(string emailHuesped,string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    set<huespedGrupal*>::iterator it;
    
    int nHab = (*getHabitacion()).getNumero();
    bool t=(*ch).existeHabEnHostal(nHab,nombreHostal);

    if (t){
        for (it=huesGrup.begin() ; it!=huesGrup.end() ; it++){
            (*(*it)).finalizarEstadiaActiva(emailHuesped);
        }
    }
}
bool tieneEstadiaFinalizadaDeHuesped(string e){
    DTEstadia* a;
    //!(*this).huesGrup.empty()
}