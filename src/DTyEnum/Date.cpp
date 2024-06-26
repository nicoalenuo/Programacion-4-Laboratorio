#include "../../include/DTyEnum/Date.h"

Date::~Date(){  
}

Date::Date(){
    dia=0;
    mes=0;
    anio=0;
    hora=0;
}

int Date::getAnio(){
    return anio;
}

int Date::getMes(){
    return mes;
}

int Date::getDia(){
    return dia;
}

int Date::getHora(){
    return hora;
}

void Date::setHora(int h){
    hora = h;
}

void Date::setAnio(int a){
    anio= a;
}

void Date::setMes(int m){
    mes= m;
}

void Date::setDia(int d){
    dia= d;
}

bool Date::operator<(Date D2){
    bool Resultado = false;
    if((*this).anio < D2.anio){
        Resultado = true;
    }else if((*this).anio == D2.anio && (*this).mes < D2.mes ){
        Resultado = true;
    }else if((*this).anio == D2.anio && (*this).mes == D2.mes && (*this).dia < D2.dia ){
        Resultado = true;
    }
    return Resultado;
}

bool Date::operator==(Date D2){
    return ((*this).anio == D2.anio && (*this).mes == D2.mes && (*this).dia == D2.dia);
}

bool Date::operator>(Date D2){
    return (!((*this) < D2) && !((*this)== D2));
}

int Date::operator-(Date D2){
    int DiaCalc = this->dia - D2.getDia();
    int MesCalc = this->mes-D2.getMes();
    int AnioCalc = this->anio - D2.getAnio();
    int Diferencia = DiaCalc + MesCalc*30 + AnioCalc*360;
    if(Diferencia >= 0){
        return Diferencia;
    }else{
        return -Diferencia;
    }
}

Date::Date(int dia,int mes,int anio,int hora){
    (*this).dia=dia;
    (*this).mes=mes;
    (*this).anio=anio;
    (*this).hora=hora;
}