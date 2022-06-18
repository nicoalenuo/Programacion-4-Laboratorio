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
        int getAnio(){
            return anio;
        }
        int getMes(){
            return mes;
        }
        int getDia(){
            return dia;
        }
        int getHora(){
            return hora;
        }
        void setHora(int h){
            hora = h;
        }
        void setAnio(int a){
            anio= a;
        }
        void setMes(int m){
            mes= m;
        }
        void setDia(int d){
            dia= d;
        }
};

#endif