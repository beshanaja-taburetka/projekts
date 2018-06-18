#ifndef PICA_H
#define PICA_H
#include <iostream>
using namespace std;


class Pica
{
    public:
        Pica();
        Pica(string, double, int);
        virtual ~Pica();

        string Getnosaukums() { return nosaukums; }
        void Setnosaukums(string val) { nosaukums = val; }
        double Getcena() { return cena; }
        void Setcena(double val) { cena = val; }
        int Getizmers() { return izmers; }
        void Setizmers(int val) { izmers = val; }

        string nosaukums;
        double cena;
        int izmers;

    protected:

    private:

};

#endif // PICA_H
