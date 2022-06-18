#include "../../include/ControladorCalificacion/ControladorCalificacion.h"
#include "../../include/fabrica.h"
#include "../../include/FechaSistema.h"


ControladorCalificacion* ControladorCalificacion::instancia = NULL;

ControladorCalificacion::~ControladorCalificacion(){
}

ControladorCalificacion::ControladorCalificacion(){
    calificaciones={};
    estadias={};
}

ControladorCalificacion* ControladorCalificacion::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorCalificacion();
    return instancia;
}

void ControladorCalificacion::eliminarSuscripto(IObserver* o){
    empleado* e = static_cast<empleado*>(o);
    observers.erase((*e).getEmail());
}

void ControladorCalificacion::agregarSuscripto(IObserver* o){
    empleado* e = static_cast<empleado*>(o);
    observers.insert(pair<string,IObserver*>((*e).getEmail(),o));
}

void ControladorCalificacion::notificarSuscriptos(string nombreAutor,int puntuacion,string comentario){
    map<string,IObserver*>::iterator it;
    for (it=observers.begin() ; it!=observers.end() ; it++){
        (*(*it).second).notificar(nombreAutor,puntuacion,comentario);
    }
}

void ControladorCalificacion::RegistrarEstadia(DTHostal* Hosta, string email, DTReserva* Reserva, DTEstadia* Estadia){
    fabrica* Fab =fabrica::getInstance();
    IControladorReserva* CH = (*Fab).getIControladorReserva();
    reserva* r = CH->getReserva(Reserva);
    if(dynamic_cast<individual*>(r)!=NULL){
        individual* rI = static_cast<individual*>(r);
        huespedIndividual* HI = rI->getHuespedIndividual();
        MaxCodigoEstadia++;
        Estadia->setCodigo(MaxCodigoEstadia);
        estadia* e = new estadia(Estadia); 
        HI->setEstadia(e);
        estadias.insert(pair<int,estadia*>(Estadia->getCodigo(),e));
    }else{
        grupal* rG = static_cast<grupal*>(r);
        huespedGrupal* HG = rG->GetHuespedGrupalDeUsuario(email);
        MaxCodigoEstadia++;
        Estadia->setCodigo(MaxCodigoEstadia);
        estadia* e = new estadia(Estadia); 
        HG->setEstadia(e);
        estadias.insert(pair<int,estadia*>(Estadia->getCodigo(),e));
    }
}

void ControladorCalificacion::agregarCalificacion(string email,string coment,int nota){
    fabrica* fab = fabrica::getInstance();
    FechaSistema* fSist = FechaSistema::getInstance(); 
    IControladorUsuario* usr = fab->getIControladorUsuario();
    IControladorHostal* hst = fab->getIControladorHostal();
    DTHostal* dtsHostal=(*hst).getDatosHostal();
    DTHuesped* hues = usr->obtenerHuespedConEmail(email);
    hostal* host = hst->obtenerHostal(dtsHostal);
    Date actual = fSist->getFechaActual();
    calificacion* cal = new calificacion(idActual, nota, coment, actual);
    idActual++;
    notificarSuscriptos(hues->getNombre(),nota,coment);
    agregarCalificacionAMap(cal);
    host->agregarCalificacionAMap(cal);
    map<int,estadia*>::iterator it = estadias.find(datosEstadia->getCodigo());
    it->second->setCalificacion(cal);
}

void ControladorCalificacion::ingresarRespuesta(string resp, DTCalificacion* tcl){
    map<int,calificacion*>::iterator aux = (*this).calificaciones.find(tcl->getId());
    calificacion* aux2 = (*aux).second;
    aux2->ingresarRespuesta(resp);
}

void ControladorCalificacion::liberarMemoria(){
    if (datosCalificacion!=NULL){
        delete datosCalificacion;
        datosCalificacion=NULL;
    }
    if (datosEstadia!=NULL){
        delete datosEstadia;
        datosEstadia=NULL;
    }
}

int ControladorCalificacion::obtenerCodigoDeEstadia(){
    return (*this).getDatosEstadia()->getCodigo();
}

DTCalificacion* ControladorCalificacion::obtenerCalificacionDeEstadia(){
    map<int,estadia*>::iterator it= estadias.find((*this).datosEstadia->getCodigo());
    calificacion* c= (*it).second->getCalificacion();
    DTCalificacion* dtc=NULL;
    if (c!=NULL)
        dtc = new DTCalificacion(c->getId(),c->getPuntuacion(),c->getComentario(),c->getFecha());
    return dtc;
}

DTCalificacion* ControladorCalificacion::obtenerCalificacion(DTEstadia* dte){
    map<int,estadia*>::iterator it= estadias.find(dte->getCodigo());
    calificacion* c= (*it).second->getCalificacion();
    DTCalificacion* dtc=NULL;
    if (c!=NULL)
        dtc = new DTCalificacion(c->getId(),c->getPuntuacion(),c->getComentario(),c->getFecha());
    return dtc;
}

void ControladorCalificacion::quitarEstadia(int codigo){
    estadias.erase(codigo);
}

DTRespuesta* ControladorCalificacion::obtenerRespuesta(DTCalificacion* c){
    map<int,estadia*>::iterator it= estadias.find(c->getId());
    calificacion* cal= (*it).second->getCalificacion();
    DTRespuesta* dtr=NULL;
    if (cal!=NULL){
        respuesta* r= cal->getRespuesta();
        if (r!=NULL){
            dtr = new DTRespuesta((*r).getComentario());
        }
    }
    return dtr;
}

void ControladorCalificacion::eliminarCalificacion(int id){//borra del map la calificacion, pero no de memoria, eso se hace en EliminarCalificacion de Calificacion
    calificaciones.erase(id);
}

////////////////////////////////////////////////

        map<int,DTEstadia*> ControladorCalificacion::obtenerEstadiasHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }
        map<int,DTCalificacion*> ControladorCalificacion::obtenerCalificaciones(string){
            map<int,DTCalificacion*> a;
            return a;
        }
        void ControladorCalificacion::eliminarCalificacion(){}
        float ControladorCalificacion::obtenerPromocionDeEstadia(){return 1;}