#ifndef EXCEPTIONLIST_H
#define EXCEPTIONLIST_H
#include <iostream>
#include<stdexcept>
using namespace std;

class Exceptionlist: public std::exception
{
private:
    char *msg;
public:
    Exceptionlist(const char *message): std::exception(){msg=(char*)message;}
    const char *what() const noexcept{return msg;}
};

#endif // EXCEPTIONLIST_H
