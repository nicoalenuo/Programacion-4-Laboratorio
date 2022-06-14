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
        if(estadia!=NULL){
            e.insert(pair<int,DTEstadia*>(estadia->getCodigo(),estadia));
        }
        return e;
}

bool individual::tieneEstadia(DTEstadia* dte){
    bool encontrado=false;
    encontrado = (*huesInd).tieneEstadia(dte);

    return encontrado;
}

DTHuesped* individual::darHuespedConEstadia(DTEstadia* dte){
    DTHuesped* huesped = (*huesInd).darDatosHuesped();
    return huesped;
}

DTHabitacion* individual::darDatosHabitacion(){
    DTHabitacion* hab = (*habitacionAsoc).darDatos();
    return hab;
}

huespedIndividual* individual::getHuespedIndividual(){
    return huesInd;
}

void individual::setHuespedIndividual(huespedIndividual* hi){
    huesInd = hi;
}