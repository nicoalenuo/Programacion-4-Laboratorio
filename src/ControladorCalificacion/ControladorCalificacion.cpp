#include "../../include/ControladorCalificacion/ControladorCalificacion.h"
#include "../../include/fabrica.h"
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

void ControladorCalificacion::eliminarSuscripto(empleado* e){
    observers.erase((*e).getEmail());
}
void ControladorCalificacion::agregarSuscripto(empleado* e){
            observers.insert(pair<string,empleado*>((*e).getEmail(),e));
};
void ControladorCalificacion::notificarSuscriptos(string nombreAutor,int puntuacion,string comentario){
    map<string,IObserver*>::iterator it;
    for (it=observers.begin() ; it!=observers.end() ; it++){
        (*(*it).second).notificar(nombreAutor,puntuacion,comentario);
    }
}

        map<int,DTEstadia*> ControladorCalificacion::obtenerEstadiasHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }
        void ControladorCalificacion::agregarCalificacion(string,int){}
        map<int,DTCalificacion*> ControladorCalificacion::obtenerCalificaciones(string){
            map<int,DTCalificacion*> a;
            return a;
        }
        void ControladorCalificacion::ingresarComentario(string){}
        void ControladorCalificacion::liberarEstadia(){};
        void ControladorCalificacion::eliminarCalificacion(calificacion* cal){//borra del map la calificacion, pero no de memoria, eso se hace en EliminarCalificacion de Calificacion
            calificaciones.erase(cal->getId());
        }
        void ControladorCalificacion::RegistrarEstadia(DTHostal* Hosta, string email, DTReserva* Reserva, DTEstadia* Estadia){
            fabrica* Fab =fabrica::getInstance();
            IControladorReserva* CH = (*Fab).getIControladorReserva();
            reserva* r = CH->getReserva(Reserva);
            string TipoReserva = r->getTipoReserva();
            if(TipoReserva == "Individual"){
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
        void ControladorCalificacion::ingresarRespuesta(string){}
        float ControladorCalificacion::obtenerPromocionDeEstadia(){return 1;}
        int ControladorCalificacion::obtenerCodigoDeEstadia(){return 1;}
        DTCalificacion* ControladorCalificacion::obtenerCalificacionDeEstadia(){return NULL;}
        DTRespuesta* ControladorCalificacion::obtenerRespuesta(DTCalificacion*){return NULL;}