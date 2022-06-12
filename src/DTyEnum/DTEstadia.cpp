#include "../../include/DTyEnum/DTEstadia.h"

DTEstadia::~DTEstadia(){
}
DTEstadia::DTEstadia(Date ChIn,Date ChOut,int cod){
    (*this).fechaEntrada = ChIn;
    (*this).fechaSalida = ChOut;
    (*this).codigo = cod;
}