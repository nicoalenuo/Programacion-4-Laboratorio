#ifndef IOBSERVER
#define IOBSERVER

#include <iostream>
#include <stdio.h>
using namespace std;


class IObserver{
    public:
        virtual void notificar(string,int,string)=0;
        virtual ~IObserver()=0;
};

#endif