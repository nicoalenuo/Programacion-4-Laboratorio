#ifndef FABRICA
#define FABRICA

#include "ControladorUsuario/IControladorUsuario.h"
#include "ControladorCalificacion/IControladorCalificacion.h"
#include "ControladorReserva/IControladorReserva.h"
#include "ControladorHostal/IControladorHostal.h"
#include "ControladorUsuario/ControladorUsuario.h"
#include "ControladorCalificacion/ControladorCalificacion.h"
#include "ControladorReserva/ControladorReserva.h"
#include "ControladorHostal/ControladorHostal.h"

class fabrica{
    private:
        static fabrica* instancia;
        fabrica();
    public:
        static fabrica* getInstance();

        IControladorHostal* getIControladorHostal();
        IControladorReserva* getIControladorReserva();
        IControladorCalificacion* getIControladorCalificacion();
        IControladorUsuario* getIControladorUsuario();
};

#endif