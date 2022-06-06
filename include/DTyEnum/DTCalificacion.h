#ifndef DTCALIFICACION
#define DTCALIFICACION

#include <iostream>
#include <stdio.h>
using namespace std;

class DTCalificacion {
    private:
        int ic;
        int puntuacion();
        string comentario();
        Date fecha;

    

    public:
        ~DTCalificacion();
      public
        int getIc()
        {
            return this.ic;
        }

    
        void setIc(int ic)
        {
            this.ic = ic;
        }

    
        int getPuntuacion()
        {
            return this.puntuacion();
        }


        void setPuntuacion()(int puntuacion())
        {
            this.puntuacion() = puntuacion();
        }

        string getComentario()
        {
            return this.comentario();
        }

        void setComentario()(string comentario())
        {
            this.comentario() = comentario();
        }

    
        Date getFecha()
        {
            return this.fecha;
        }

    
        void setFecha(Date fecha)
        {
            this.fecha = fecha;
        }
};

#endif