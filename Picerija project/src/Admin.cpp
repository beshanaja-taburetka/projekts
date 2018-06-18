#include "Admin.h"

Admin::Admin()
{
    //ctor
}

Admin::Admin(int id, string name, string surname, string parole){
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->parole = parole;


}

Admin::~Admin()
{
    //dtor
}
