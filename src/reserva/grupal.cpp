#include "../../include/reserva/grupal.h"
#include "../../include/fabrica.h"
grupal::~grupal(){
   // [FATLTA HACER]
}
grupal::grupal(DTReservaGrupal* DTR, habitacion* Hab,map<string,DTHuesped*> SDTH,DTHuesped* Propietario){
    fabrica* Fab =fabrica::getInstance();
    map<string,DTHuesped*>::iterator it;
    IControladorUsuario* CU = Fab->getIControladorUsuario();
    huesped* U = (*CU).getHuesped(Propietario);
    huespedGrupal* HG = new huespedGrupal(U);
    this->huesGrup.insert(HG);
    for(it = SDTH.begin(); it!= SDTH.end();it++){
        huesped* Huesp = (*CU).getHuesped((*it).second);
        huespedGrupal* HG = new huespedGrupal(Huesp);
        this->huesGrup.insert(HG);
    }
    this->habitacionAsoc = Hab;
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
        DTReservaGrupal* grupal::darDatos(){return NULL;}
        bool grupal::perteneceHusped(string){return 1;}
        string grupal::getTipoReserva(){return "";}
        void grupal::darBajaReserva(){}
        map<int, DTEstadia*> grupal::obtenerEstadias(){
            map<int,DTEstadia*> a;
            return a;
        }
        DTEstadia* grupal::obtenerEstadia(){return NULL;}
        DTReserva* grupal::obtenerResrvaDeEst(){return NULL;}
        bool grupal::tieneEstadiaFinalizadaDeHuesped(string){return 0;}
        DTEstadia* grupal::darEstadiaDeHuesped(string){return NULL;}