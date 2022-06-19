#ifndef DATE
#define DATE

class Date{
    private:
        int anio;
        int mes;
        int dia;
        int hora;
    public:
        Date();
        ~Date();
        bool operator<(Date);
        bool operator>(Date);
        bool operator==(Date);
        int operator-(Date);//retorna la cantidad de dias entre this y el parametro

        Date(int,int,int,int);
        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        void setHora(int);
        void setAnio(int);
        void setMes(int);
        void setDia(int);
};

#endif