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
    codigo=(*DTR).getCodigo();
    costo=(*DTR).getCosto();
    checkIn=(*DTR).getCheckIn();
    checkOut=(*DTR).getCheckOut();
    estado=(*DTR).getEstado();
    cantHuespedes=(*DTR).getCantHuespedes();
}

int grupal::getCodigo(){
    return codigo;
}

Date grupal::getCheckIn(){
    return checkIn;
}

Date grupal::getCheckOut(){
    return checkOut;
}

EstadoReserva grupal::getEstado(){
    return estado;
}

float grupal::getCosto(){
    return costo;
}

int grupal::getCantHuespedes(){
    return cantHuespedes;
}

void grupal::setCodigo(int c){
    codigo=c;
}

void grupal::setHabitacion(habitacion* h){
    habitacionAsoc=h;
}

void grupal::setCheckIn(Date d){
    checkIn=d;
}

void grupal::setCheckOut(Date d){
    checkOut=d;
}

void grupal::setEstado(EstadoReserva er){
    estado=er;
}

void grupal::setCosto(float c){
    costo=c;
}

void grupal::setCantHuespedes(int ch){
    cantHuespedes=ch;
}

habitacion* grupal::getHabitacion(){
    return habitacionAsoc;
}

void grupal::agregarHuespedGrupalASet(huespedGrupal* hg){
    huesGrup.insert(hg);
}

void grupal::finalizarSiEsReservaBuscada(string emailHuesped,string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    set<huespedGrupal*>::iterator it;

    habitacion* hab = getHabitacion();
    
    if ((*ch).existeHabEnHostal(hab,nombreHostal)){
        for (it=huesGrup.begin() ; it!=huesGrup.end() ; it++){
            (*(*it)).finalizarEstadiaActiva(emailHuesped);
        }
    }
}

bool grupal::perteneceHusped(string email){
    set<huespedGrupal*>::iterator it;
    bool Resultado = false;
    it = huesGrup.begin();
    while(it!= huesGrup.end() && !Resultado){
        Resultado = ((*it)->getHuesped()->getEmail() == email);
        it++;
    }
    return Resultado;
}


DTHostal* grupal::getDTHostal(){
    habitacion* hab = habitacionAsoc;
    hostal * h = (*hab).darHostal();
    DTHostal* DTH = h->darDatos();
    return DTH;
}

DTReserva* grupal::getDTReserva(){
    DTReserva* DTR = new DTReservaGrupal(this->codigo,this->checkIn,this->checkOut,this->estado,this->costo,this->cantHuespedes);
    return DTR;
}

huespedGrupal* grupal::GetHuespedGrupalDeUsuario(string email){
    set<huespedGrupal*>::iterator it;
    it = huesGrup.begin();
    bool Encontrado = false;
    huespedGrupal* HG = NULL;
    while(!Encontrado && it != huesGrup.end()){
        huesped* hues = (*it)->getHuesped();
        Encontrado = (hues->getEmail() ==email);
        if(Encontrado){
            HG = *it;
        }
        it++;
    }
    return HG;

}

map<int,DTEstadia*> grupal::obtenerEstadias(){
        map<int,DTEstadia*> e;
        DTEstadia* aux;
        map<int,DTEstadia*>::iterator ite;
        set<huespedGrupal*>::iterator ithg;
        for(ithg= huesGrup.begin(); ithg!=huesGrup.end();ithg++){
                aux = (*ithg)->obtenerEstadia();
                if(aux!=NULL){
                    e.insert(pair<int,DTEstadia*>((*aux).getCodigo(),aux));
                }
        }       
        return e;
}

bool grupal::tieneEstadia(DTEstadia* dte){
    bool encontrado=false;
    set<huespedGrupal*>::iterator it=huesGrup.begin();
    while (it!=huesGrup.end() && !encontrado){
        encontrado = (*(*it)).tieneEstadia(dte);
        it++;
    }

    return encontrado;
}

DTHuesped* grupal::darHuespedConEstadia(DTEstadia* dte){
    set<huespedGrupal*>::iterator it=huesGrup.begin();
    bool encontrado=false;
    while (!encontrado){
        encontrado = (*(*it)).tieneEstadia(dte);
        if (!encontrado)
            it++;
    }
    DTHuesped* h = (*(*it)).darDatosHuesped();
    return h;
}

DTHabitacion* grupal::darDatosHabitacion(){
    DTHabitacion* hab = (*habitacionAsoc).darDatos();
    return hab;
}

bool grupal::tieneEstadiaFinalizadaDeHuespedEnHostal(string email){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ICH = (*f).getIControladorHostal();
    DTHostal* dth = (*ICH).getDatosHostal();
    habitacion* hab = getHabitacion();

    bool aux = false;
    bool aux2 = (*ICH).existeHabEnHostal(hab,(*dth).getNombre());

    if(!huesGrup.empty() && aux2){
        set<huespedGrupal*>::iterator it = huesGrup.begin();
        while(aux != true && it!=huesGrup.end()){
            if((*it)->tieneEstFinalizadaDeHus(email)){
                aux = true;
            }
            ++it;
        }
    } 
    return aux;
}

DTEstadia* grupal::darEstadiaDeHuesped(string email){
    DTEstadia* send = NULL;
    bool aux = false;
    if(!huesGrup.empty()){
        set<huespedGrupal*>::iterator it = huesGrup.begin();
        while(aux != true && it != huesGrup.end()){
            if((*it)->esDeHuesped(email)){
                send = (*(*it)).obtenerEstadia();
                aux = true;
            }
            ++it;
        }
    }
    return send;
}

void grupal::darBajaReserva(){
    set<huespedGrupal*>::iterator it;
    habitacion* h = getHabitacion();
    (*h).darBajaReserva(codigo);
    for(it= huesGrup.begin(); it!= huesGrup.end();it++){
        huespedGrupal* gh = *it;
        (*it)->darBaja();
        huesGrup.erase((*it));
        delete gh;
    } 
}

map<string,DTHuesped*> grupal::obtenerHuespedesDeReserva(){
    set<huespedGrupal*>::iterator it;
    map<string,DTHuesped*> resultado;
    for(it=huesGrup.begin();it!=huesGrup.end();it++){
        DTHuesped* h= (*it)->darDatosHuesped();
        resultado.insert(pair<string,DTHuesped*>((*h).getEmail(),h));
    }
    return resultado;
}