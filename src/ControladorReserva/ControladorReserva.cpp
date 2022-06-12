#include "../../include/fabrica.h"
#include "../../include/ControladorReserva/ControladorReserva.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::~ControladorReserva(){
}

ControladorReserva::ControladorReserva(){
    reservas={};

    datosReserva=NULL;
    datosIndividual=NULL;
    datosGrupal=NULL;
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
ControladorReserva* ControladorReserva::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia; 
}
void ControladorReserva::ingresarDatosReserva(DTHostal* DTHostal, Date CkeckIn, Date CheckOut){
    (*this).Hos = DTHostal;
    (*this).CheckIn = CkeckIn; 
    (*this).CheckOut = CheckOut; 
}
reserva* ControladorReserva::getReserva(DTReserva* res){
    return (*reservas.find(res->getCodigo())).second;
}
map<int,DTHabitacion*> ControladorReserva::obtenerHabitacionesDisponibles(){
    fabrica* Fab =fabrica::getInstance();
    map<int,DTHabitacion*> Resultado;
    IControladorHostal* CH = (*Fab).getIControladorHostal();
    hostal *h = (*CH).obtenerHostal(Hos);
    Resultado = (*h).obtenerHabitacionesDisponiblesEntre((*this).CheckIn, (*this).CheckOut);/////////////////
    return Resultado;
}
void ControladorReserva::finalizarEstadiaActiva(string emailHuesped, string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    map<int,reserva*>::iterator it;

    for (it=reservas.begin() ; it!=reservas.end() ; it++)
        (*(*it).second).finalizarSiEsReservaBuscada(emailHuesped,nombreHostal);

        (*ch).liberarDatosHostal();
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
        void ControladorReserva::confirmarBaja(DTHostal*, int){}
        int ControladorReserva::obtenerNumeroDeHabitacion(DTHabitacion*){return 4;}
       
        map<string,string> ControladorReserva::obtenerNombresDeReserva(DTReservaGrupal*){
            map<string,string> a;
            return a;
        }
        map<int,DTEstadia*> ControladorReserva::obtenerEstadiaHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }
        map<string,string> ControladorReserva::mostrarReserva(DTReserva*){
            map<string,string> a;
            return a;
        }
        