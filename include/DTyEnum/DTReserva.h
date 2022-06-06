#ifndef DTRESERVA
#define DTRESERVA

#include "EstadoReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReserva {
    protected:
        int Codigo;
        Date CheckIn;
        Date CheckOut;
        EstadoReserva

	

    public:
     ~DTReserva();
    int getCodigo() {
		return (*this).Codigo;
	}

	void setCodigo(int Codigo) {
		(*this).Codigo = Codigo;
	}

	Date getCheckIn() {
		return (*this).CheckIn;
	}

	void setCheckIn(Date CheckIn) {
		(*this).CheckIn = CheckIn;
	}

	Date getCheckOut() {
		return (*this).CheckOut;
	}

	void setCheckOut(Date CheckOut) {
		(*this).CheckOut = CheckOut;
	}

	Object getEstadoReserva() {
		return (*this).EstadoReserva;
	}

	void setEstadoReserva(Object EstadoReserva) {
		(*this).EstadoReserva = EstadoReserva;
	}
};

#endif