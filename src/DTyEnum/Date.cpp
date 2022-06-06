#include "../../include/DTyEnum/Date.h"

Date::Date(){
    dia=0;
    mes=0;
    anio=0;
}

Date::Date(int dia,int mes,int anio){
    (*this).dia=dia;
    (*this).mes=mes;
    (*this).anio=anio;
}