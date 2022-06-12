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
        DTEstadia* aux;
        map<int,DTEstadia*>::iterator ite;
        set<huespedGrupal*>::iterator ithg;
        for(ithg= huesGrup.begin(); ithg!=huesGrup.end();ithg++){
                aux = (*ithg)->obtenerEstadia();
                e.insert(pair<int,DTEstadia*>((*aux).getCodigo(),aux));
        }       
        return e;
}