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

DTHostal* individual::getDTHostal(){
    habitacion* hab = habitacionAsoc;
    hostal * h = (*hab).darHostal();
    DTHostal* DTH = h->darDatos();
    return DTH;
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

DTReserva* individual::getDTReserva(){
    DTReserva* DTR = new DTReservaIndividual(this->codigo,this->checkIn,this->checkOut,this->estado,this->costo);
    return DTR;
}

string individual::getTipoReserva(){return "Individual";}

bool individual::perteneceHusped(string email){
    return (this->huesInd->getHuesped())->getEmail() == email;
}
        

        DTReservaIndividual* individual::darDatos(){return NULL;}
        
        void individual::darBajaReserva(){}
        map<int, DTEstadia*> individual::obtenerEstadias(){ 
            map<int,DTEstadia*> a;
            return a;}
        DTEstadia* individual::obtenerEstadia(){return NULL;}
        DTReserva* individual::obtenerResrvaDeEst(){return NULL;}
        bool individual::tieneEstadiaFinalizadaDeHuesped(string){return 0;}
        DTEstadia* individual::darEstadiaDeHuesped(string){return NULL;}
       
