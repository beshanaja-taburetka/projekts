#ifndef ADMIN_H
#define ADMIN_H
#include "Lietotajs.h"


class Admin: public Lietotajs
{
    public:
        Admin();
        Admin (int, string, string ,string);
        virtual ~Admin();

    protected:

    private:
};

#endif // ADMIN_H
