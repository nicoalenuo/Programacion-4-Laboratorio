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
            return (*this).anio;
        }
        int getMes(){
            return (*this).mes;
        }
        int getDia(){
            return (*this).Dia;
        }
        void setAnio(int c){
            (*this).capacidad=c;
        }
        void setMes(int c){
            (*this).mes=c;
        }
        void getDia(int c){
            (*this).dia=c;
        }
        ~Date();
};


#endif