#include "../Include/Person.h"

// friend
ostream& operator<< (ostream& os, const person& p)
{
    os << p._name << " " << p._phonenumber << " " << p._city << " " << p._country;
    return os;
}

// friend
string& operator>> (string& s, const person& p)
{
    s = p._name;
    return s;
}
