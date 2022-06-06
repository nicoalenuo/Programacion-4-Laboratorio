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
        int getAnio(){
            return anio;
        };
        int getMes(){
            return mes;
        };
        int getDia(){
            return dia;
        };
        void setAnio(int a){
            anio= a;
        };
        void setMes(int m){
            mes= m;
        };
        void setDia(int d){
            dia= d;
        };
};

#endif