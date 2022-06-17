#include "../../include/ControladorReserva/ControladorReserva.h"
#include "../../include/fabrica.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::~ControladorReserva(){
}

ControladorReserva::ControladorReserva(){
        datosReserva = NULL;
        datosIndividual = NULL;
        datosGrupal = NULL;
        Propietario = NULL;
}

ControladorReserva* ControladorReserva::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia; 
}

void ControladorReserva::finalizarEstadiaActiva(string emailHuesped, string nombreHostal){
    map<int,reserva*>::iterator it;

    for (it=reservas.begin() ; it!=reservas.end() ; it++)
        (*(*it).second).finalizarSiEsReservaBuscada(emailHuesped,nombreHostal);
}

void ControladorReserva::ingresarDatosReserva(DTHostal* hos, Date CkeckIn, Date CheckOut){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    (*ch).setDatosHostal(hos);
    (*this).CheckIn = CkeckIn; 
    (*this).CheckOut = CheckOut; 
}

map<int,DTHabitacion*> ControladorReserva::obtenerHabitacionesDisponibles(){
    fabrica* Fab =fabrica::getInstance();
    map<int,DTHabitacion*> Resultado;
    IControladorHostal* CH = (*Fab).getIControladorHostal();
    DTHostal* Hos = (*CH).getDatosHostal();
    hostal *h = (*CH).obtenerHostal(Hos);
    Resultado = (*h).obtenerHabitacionesDisponiblesEntre((*this).CheckIn, (*this).CheckOut);
    return Resultado;
}

void ControladorReserva::DesignarPropietarioDeReserva(DTHuesped* P){
    (*this).Propietario = P;
}

void ControladorReserva::IngresarHuespedEnReserva(DTHuesped* h){
    SDTH.insert(pair<string,DTHuesped*>(h->getEmail(), h));
}

void ControladorReserva::confirmarReserva(){
    fabrica* Fab =fabrica::getInstance();
    IControladorHostal* CH = Fab->getIControladorHostal();
    DTHabitacion* Hab = (*CH).getDatosHabitacion();
    habitacion* h = CH->getHabDeHostal(Hab);

    reserva *Res;
    int CantidadDias = this->CheckIn - this->CheckOut;//Calculo los dias entre Checkin y CheckOut
    if(SDTH.empty()){//Es individual
        float Precio = (Hab->getPrecio())*CantidadDias;
        DTReservaIndividual* ResIn = new DTReservaIndividual(IDActualReserva+1,CheckIn,CheckOut,Abierto,Precio);
        Res = new individual(ResIn,h,Propietario);
    }else{//Es grupal
        float Precio = (Hab->getPrecio())*CantidadDias*(1-0.3);
        DTReservaGrupal* ResGr= new DTReservaGrupal(IDActualReserva+1,CheckIn,CheckOut,Abierto,Precio,SDTH.size() +1);
        Res = new grupal(ResGr,h,SDTH,Propietario);
    }
    IDActualReserva++;
    agregarReservaAMap(Res);
    (*h).agregarReservaAMap(Res);
    (*CH).liberarMemoria();
    liberarMemoria();
}  

        
map<int,DTReserva*> ControladorReserva::ListarReservasNoCanceladasDeHuesped(DTHostal* Hostal, string Mail){
    map<int,DTReserva*> Resultado;
    map<int,reserva*>::iterator it;
    for(it = reservas.begin(); it!= reservas.end();it++){
    DTHostal * DTh = ((*it).second)->getDTHostal(); 
    DTReserva * DTr = ((*it).second)->getDTReserva();
    if(Hostal->getNombre() == DTh->getNombre() && DTr->getEstado() != Cancelado){
        bool p = (*it).second->perteneceHusped(Mail);
        if(p){ 
            Resultado.insert(pair<int,DTReserva*>((*it).second->getCodigo(),(*it).second->getDTReserva()));
        }
    }
    }
    return Resultado;
}

reserva* ControladorReserva::getReserva(int cod){
    return (*reservas.find(cod)).second;
}

DTDatosEstadia* ControladorReserva::obtenerDatosEstadia(){//Existe DTHostal y DTEstadia en memoria
    fabrica* f= fabrica::getInstance();
    IControladorCalificacion* icc= (*f).getIControladorCalificacion();
    IControladorHostal* ich= (*f).getIControladorHostal();
    DTEstadia* dte= (*icc).getDatosEstadia();
    
    map<int,reserva*>::iterator itr;
    reserva* r= obtenerReservaDeEstadia(dte);

    DTHostal* datosHostalDevolver= (*ich).getDatosHostal();
    DTHuesped* datosHuespedDevolver = (*r).darHuespedConEstadia(dte);
    DTHabitacion* datosHabitacionDevolver = (*r).darDatosHabitacion();
    Date* fechaSalidaDevolver;
    Date fs=Date((*(*dte).getFechaSalida()));
    (*fechaSalidaDevolver)=fs;

    DTDatosEstadia* datosDevolver = new DTDatosEstadia(datosHostalDevolver,datosHabitacionDevolver,datosHuespedDevolver,(*dte).getFechaEntrada(),fechaSalidaDevolver);

    return datosDevolver;
}

reserva* ControladorReserva::obtenerReservaDeEstadia(DTEstadia* dte){
    reserva* r;
    bool encontrado= false; 
    map<int,reserva*>::iterator it= reservas.begin();
    while(encontrado != false){
        encontrado= (*it).second->tieneEstadia(dte);
        if (!encontrado)
            it++;
    }
    r=(*it).second;
    return r;
}

DTReserva* ControladorReserva::obtenerDTReservaDeEstadia(DTEstadia* dte){
    DTReserva* resultado;
    reserva* r;
    r=obtenerReservaDeEstadia(dte);
    resultado = (*r).getDTReserva();
    return resultado;
}

void ControladorReserva::confirmarBaja(DTHostal* Host, int Codigo){
    reserva * r = (*reservas.find(Codigo)).second;
    reservas.erase(Codigo);
    r->darBajaReserva();
    delete r;
}

map<int,DTEstadia*> ControladorReserva::obtenerEstadiaHuesped(string email){
    map<int,DTEstadia*> send;
    for(map<int,reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        if(it->second->tieneEstadiaFinalizadaDeHuesped(email)){
            DTEstadia* aux = it->second->darEstadiaDeHuesped(email);
            send.insert(pair<int,DTEstadia*>(aux->getCodigo(),aux));
        }
    }
    return send;
}

map<string,DTHuesped*> ControladorReserva::obtenerHuespedesDeReserva(DTReservaGrupal* dtrg){
    map<int,reserva*>::iterator it= reservas.find(dtrg->getCodigo());
    //como siempre es grupal
    grupal* gru= static_cast<grupal*>((*it).second);
    return gru->obtenerHuespedesDeReserva();
}

void ControladorReserva::liberarMemoria(){
    if (datosReserva!=NULL){
        delete datosReserva;
        datosReserva=NULL;
    }
    if (datosIndividual!=NULL){
        delete datosIndividual;
        datosIndividual=NULL;
    }
    if (datosGrupal!=NULL){
        delete datosGrupal;
        datosGrupal=NULL;
    }
    if (Propietario!=NULL){
        delete Propietario;
        Propietario=NULL;
    }
    map<string,DTHuesped*>::iterator it;
    for (it=SDTH.begin() ; it!=SDTH.end() ; it++){
        delete (*it).second;
    }
    SDTH.clear();
} 