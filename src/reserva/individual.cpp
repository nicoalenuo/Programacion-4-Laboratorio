#include "../../include/reserva/individual.h"
#include "../../include/fabrica.h"
individual::~individual(){
   // [FATLTA HACER]
}
individual::individual(DTReservaIndividual* DTR, habitacion* Hab,DTHuesped* Propietario){
    fabrica* Fab =fabrica::getInstance();
    IControladorUsuario* CU = Fab->getIControladorUsuario();
    huesped* U = (*CU).getHuesped(Propietario);
    huespedIndividual* HI = new huespedIndividual(U);
    this->huesInd = HI;
    this->habitacionAsoc = Hab;
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
        DTReservaIndividual* individual::darDatos(){return NULL;}
        bool individual::perteneceHusped(string){return 0;}
        string individual::getTipoReserva(){return "";}
        void individual::darBajaReserva(){}
        map<int, DTEstadia*> individual::obtenerEstadias(){ 
            map<int,DTEstadia*> a;
            return a;}
        DTEstadia* individual::obtenerEstadia(){return NULL;}
        DTReserva* individual::obtenerResrvaDeEst(){return NULL;}
        bool individual::tieneEstadiaFinalizadaDeHuesped(string){return 0;}
        DTEstadia* individual::darEstadiaDeHuesped(string){return NULL;}


