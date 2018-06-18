#ifndef LIETOTAJS_H
#define LIETOTAJS_H
#include <iostream>
using namespace std;


class Lietotajs
{
    public:
        Lietotajs();
        Lietotajs(int, string, string, string);
        virtual ~Lietotajs();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getsurname() { return surname; }
        void Setsurname(string val) { surname = val; }

        int id;
        string name;
        string surname;
        string parole;


    protected:

    private:
};

#endif // LIETOTAJS_H
