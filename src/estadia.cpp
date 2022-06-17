#include "../include/estadia.h"
#include "../include/fabrica.h"
#include "../include/FechaSistema.h"

estadia::estadia(int codigoAct){
    FechaSistema* fs = FechaSistema::getInstance();
    calificacionAsoc=NULL;

    this->fechaEntrada =(*fs).getFechaActual();
    fechaSalida = NULL;
    this->codigo = codigoAct;
}

bool estadia::estaActiva(){
    return fechaSalida==NULL;
}

void estadia::finalizarEstadiaActiva(){
    FechaSistema* fs=FechaSistema::getInstance();
    Date* fechaActual;
    (*fechaActual)=(*fs).getFechaActual();
    if (estaActiva()){
        setFechaSalida(fechaActual);
        cout << "finalizada" << endl;
    }
}

DTEstadia* estadia::darDatos(){
    Date* fs=NULL;
    if (fechaSalida!=NULL)
        fs = new Date((*fechaSalida).getDia(),(*fechaSalida).getMes(),(*fechaSalida).getAnio());

    DTEstadia* resultado = new DTEstadia(fechaEntrada,fs,codigo);
    return resultado;
}

void estadia::eliminarEstadia(){
    fabrica* f = fabrica::getInstance();
    IControladorCalificacion* icc = (*f).getIControladorCalificacion();
    calificacion* c = calificacionAsoc;
    if(c!= NULL){
        c->eliminarCalificacion();
        delete calificacionAsoc;
        c= NULL;
    }
    (*icc).quitarEstadia(codigo);
}

estadia::~estadia(){
    
}