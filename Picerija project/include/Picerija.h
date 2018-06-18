#ifndef PICERIJA_H
#define PICERIJA_H
#include <iostream>
#include <vector>
#include "Admin.h"
#include "conio.h"
#include "Lietotajs.h"
#include "Pica.h"
#include <fstream>
#include <windows.h>
#include "User.h"

using namespace std;


class Picerija
{
    public:
        Picerija();
        virtual ~Picerija();
        string aMenu();
        void uMenu();
        void pievienotPicu();
        void apskatitPicu();
        void dzestPicu();
        void picasEdit();
        void pievienotIngrideentu();
        void apskatitIngr();
        void pasutijums();



    protected:

    private:
        string ingridient;
        Admin * a;
        Pica * p;
        User * u;
        vector<Pica*> Picas;
        vector<Admin*> Admins;
        vector<User*> Users;
        string parb;
        unsigned int vector_size;
        char izvele;
        string nosaukums;
        int izv;
        double cena;
        int izmers;
        fstream f;
        string fails;
        string vards;
        string adrese;

};

#endif // PICERIJA_H
