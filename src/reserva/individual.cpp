#include "../../include/reserva/individual.h"
#include "../../include/fabrica.h"

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

map<int,DTEstadia*> individual::obtenerEstadias(){
        map<int,DTEstadia*> e;
        DTEstadia* estadia= (*huesInd).obtenerEstadia();
        e.insert(pair<int,DTEstadia*>(estadia->getCodigo(),estadia));
        return e;
}