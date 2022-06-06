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
 public getAnio(): int {
        return this.anio;
    }

    public setAnio(anio: int): void {
        this.anio = anio;
    }

    public getMes(): int {
        return this.mes;
    }

    public setMes(mes: int): void {
        this.mes = mes;
    }

    public getDia(): int {
        return this.dia;
    }

    public setDia(dia: int): void {
        this.dia = dia;
    }


#endif