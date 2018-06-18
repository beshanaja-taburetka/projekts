#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;


class User
{
    public:
        User();
        User(string, string);
        virtual ~User();

        string vards;
        string nosaukums;

    protected:

    private:
};

#endif // USER_H
