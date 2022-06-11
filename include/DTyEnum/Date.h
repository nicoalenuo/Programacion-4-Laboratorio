#ifndef DATE
#define DATE

class Date{
    private:
        int anio;
        int mes;
        int dia;
    public:
        Date();
        ~Date();
        Date(int,int,int);
        bool operator<(Date);
        bool operator>(Date);
        bool operator==(Date);
        int operator-(Date);//retorna la cantidad de dias entre this y el parametro
        int getAnio(){
            return anio;
        }
        int getMes(){
            return mes;
        }
        int getDia(){
            return dia;
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