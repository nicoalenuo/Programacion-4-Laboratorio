#include "../include/habitacion.h"
#include "../include/reserva/individual.h"
#include "../include/reserva/grupal.h"
#include "../include/DTyEnum/DTReservaGrupal.h"
#include "../include/DTyEnum/DTReservaIndividual.h"

void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}

map<int,DTReserva*> habitacion::obtenerReservas(){
        map<int,DTReserva*> resultado;
        map<int,reserva*>::iterator it;
        for(it= reservas.begin(); it!=reservas.end();it++){
                if(dynamic_cast<individual*>((*it).second)!=NULL){ // si es reserva individual
                        individual* ind= static_cast<individual*>((*it).second);
                        DTReservaIndividual dtr= DTReservaIndividual(ind->getCodigo(),ind->getCheckIn(),ind->getCheckOut(),ind->getEstado(),ind->getCosto());
                        DTReservaIndividual* dtri;
                        (*dtri)= dtr;
                        resultado.insert(pair<int,DTReserva*>((*it).first,dtri));
                }else{ //si es la grupal
                        grupal* gru= static_cast<grupal*>((*it).second);
                        DTReservaGrupal dtr= DTReservaGrupal(gru->getCodigo(),gru->getCheckIn(),gru->getCheckOut(),gru->getEstado(),gru->getCosto(),gru->getCantHuespedes());
                        DTReservaGrupal* dtrg;
                        (*dtrg)= dtr;
                        resultado.insert(pair<int,DTReserva*>((*it).first,dtrg));
                }
        }
        return resultado;
}