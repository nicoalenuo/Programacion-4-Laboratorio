#include "../../include/ControladorReserva/ControladorReserva.h"
#include "../../include/fabrica.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::~ControladorReserva(){
}

ControladorReserva::ControladorReserva(){
    reservas={};

    datosReserva=NULL;
    datosIndividual=NULL;
    datosGrupal=NULL;
}

ControladorReserva* ControladorReserva::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia; 
}

void ControladorReserva::finalizarEstadiaActiva(string emailHuesped, string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    map<int,reserva*>::iterator it;

    for (it=reservas.begin() ; it!=reservas.end() ; it++)
        (*(*it).second).finalizarSiEsReservaBuscada(emailHuesped,nombreHostal);

     (*ch).liberarDatosHostal();
}

void ControladorReserva::ingresarDatosReserva(DTHostal* DTHostal, Date CkeckIn, Date CheckOut){
    (*this).Hos = DTHostal;
    (*this).CheckIn = CkeckIn; 
    (*this).CheckOut = CheckOut; 
}

map<int,DTHabitacion*> ControladorReserva::obtenerHabitacionesDisponibles(){
    fabrica* Fab =fabrica::getInstance();
    map<int,DTHabitacion*> Resultado;
    IControladorHostal* CH = (*Fab).getIControladorHostal();
    hostal *h = (*CH).obtenerHostal(Hos);
    Resultado = (*h).obtenerHabitacionesDisponiblesEntre((*this).CheckIn, (*this).CheckOut);/////////////////
    return Resultado;
}

void ControladorReserva::EscogerHabitacion(DTHabitacion* h){(*this).Hab = h;}

void ControladorReserva::DesignarPropietarioDeReserva(DTHuesped* P){(*this).Propietario = P;}

void ControladorReserva::IngresarHuespedEnReserva(DTHuesped* h){SDTH.insert(pair<string,DTHuesped*>(h->getMail(), h));}
        
void ControladorReserva::CancelarReserva(){
        map<string,DTHuesped*>::iterator it;
        delete Hos;
        delete Hab;
        delete Propietario;
        for(it = SDTH.begin(); it != SDTH.end();it++){
            delete (*it).second;
    }
}

void ControladorReserva::confirmarReserva(){
    fabrica* Fab =fabrica::getInstance();
    IControladorHostal* CH = Fab->getIControladorHostal();
    habitacion* h = CH->getHab(Hab);
    reserva *Res;
    int CantidadDias = this->CheckIn - this->CheckOut;//Calculo los dias entre Checkin y CheckOut
    if(SDTH.empty()){//Es individual
        float Precio = (Hab->getPrecio())*CantidadDias;
        DTReservaIndividual* ResIn = new DTReservaIndividual(IDActualReserva+1,CheckIn,CheckOut,Abierto,Precio);
        Res = new individual(ResIn,h,Propietario);
    }else{//Es grupal
        float Precio = (Hab->getPrecio())*CantidadDias*(1-0.3);
        DTReservaGrupal* ResGr= new DTReservaGrupal(IDActualReserva+1,CheckIn,CheckOut,Abierto,Precio,SDTH.size() +1);
        Res = new grupal(ResGr,h,SDTH,Propietario);///////
    }
    IDActualReserva++;
    agregarReservaAMap(Res);
    CancelarReserva();//Libera la memoria correspondiente            
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

reserva* ControladorReserva::getReserva(DTReserva* res){
    return (*reservas.find(res->getCodigo())).second;
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

void ControladorReserva::confirmarBaja(DTHostal* Host, int Codigo){
    reserva * r = (*reservas.find(Codigo)).second;
    reservas.erase(Codigo);
    r->darBajaReserva();
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

////////////////////////////////


        int ControladorReserva::obtenerNumeroDeHabitacion(DTHabitacion*){return 4;}
        map<string,string> ControladorReserva::obtenerNombresDeReserva(DTReservaGrupal*){
            map<string,string> a;
            return a;
        }
        map<string,string> ControladorReserva::mostrarReserva(DTReserva*){
            map<string,string> a;
            return a;
        }
        