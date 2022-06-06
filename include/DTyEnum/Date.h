#ifndef DATE
#define DATE

class Date{
    private:
        int anio;
        int mes;
        int dia;
    public:
        Date();
        Date(int,int,int);
        int getAnio();
        int getMes();
        int getDia();
};

#endif