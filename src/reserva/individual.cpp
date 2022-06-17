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
    codigo=(*DTR).getCodigo();
    costo=(*DTR).getCosto();
    checkIn=(*DTR).getCheckIn();
    checkOut=(*DTR).getCheckOut();
    estado=(*DTR).getEstado();
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
    
    habitacion* hab = getHabitacion();
    if ((*ch).existeHabEnHostal(hab,nombreHostal)){
        huespedIndividual* hi = getHuespedIndividual();
        (*hi).finalizarEstadiaActiva(emailHuesped);
    }
}

DTReserva* individual::getDTReserva(){
    DTReserva* DTR = new DTReservaIndividual(this->codigo,this->checkIn,this->checkOut,this->estado,this->costo);
    return DTR;
}

bool individual::perteneceHusped(string email){
    return (this->huesInd->getHuesped())->getEmail() == email;
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

void individual::darBajaReserva(){
    huespedIndividual* HI = huesInd;
    habitacion* h = getHabitacion();
    (*h).darBajaReserva(codigo);
    HI->darBaja();
    delete HI;
    HI= NULL;
}

bool individual::tieneEstadiaFinalizadaDeHuesped(string email){
    return huesInd->tieneEstFinalizadaDeHus(email);
}

DTEstadia* individual::darEstadiaDeHuesped(string email){
    if(tieneEstadiaFinalizadaDeHuesped(email)==true){
        DTEstadia* est = huesInd->obtenerEstadia();
        return est;
    }else{ return NULL; }
}

/////////////////////////////////////////

        DTReservaIndividual* individual::darDatos(){return NULL;}
        DTEstadia* individual::obtenerEstadia(){return NULL;}
        DTReserva* individual::obtenerResrvaDeEst(){return NULL;}
       
