#include "../../include/reserva/grupal.h"
#include "../../include/fabrica.h"

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

void grupal::obtenerNombresDeReserva(){
    set<huespedGrupal*>::iterator it;
    for(it=huesGrup.begin();it!=huesGrup.end();it++){
        huesped* h= (*it)->getHuesped();
        cout << h->getNombre() << endl;
    }
}

map<int,DTEstadia*> grupal::obtenerEstadias(){
        map<int,DTEstadia*> e;
        return e;
}

bool grupal::tieneEstadia(DTEstadia* dte){
    bool encontrado=false;
    set<huespedGrupal*>::iterator it;
    for (it=huesGrup.begin() ; it!=huesGrup.end() ; it++){
        encontrado = (*(*it)).tieneEstadia(dte);
    }
    return encontrado;
}

DTHuesped* grupal::darHuespedConEstadia(DTEstadia* dte){
    set<huespedGrupal*>::iterator it=huesGrup.begin();
    bool encontrado=false;
    while (!encontrado){
        (*(*it)).tieneEstadia(dte);
        if (!encontrado)
            it++;
    }
    DTHuesped* h = (*(*it)).darDatosHuesped();
    return h;
}

DTHabitacion* grupal::darDatosHabitacion(){
    DTHabitacion* hab = (*habitacionAsoc).darDatos();
    return hab;
}