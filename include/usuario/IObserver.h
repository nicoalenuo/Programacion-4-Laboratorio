#ifndef IOBSERVER
#define IOBSERVER

#include <iostream>
#include <stdio.h>
using namespace std;


class IObserver{
    public:
        virtual ~IObserver()=0;
        virtual void notificar(string,int,string)=0;
};

#endif