#include "NumComplejo.h"
#include <ostream> 

NumComplejo NumComplejo::operator+(const NumComplejo& o)const{
    return NumComplejo(a + o.a, b + o.b);
}

NumComplejo NumComplejo::operator-(const NumComplejo& o)const{
    return NumComplejo(a - o.a, b - o.b);
}

std::ostream& operator<<(std::ostream& os, const NumComplejo& c){
    if(c.getB() < 0 ) os << c.getA() << " - " << -c.getB() << " i ";
    else os << c.getA() << " + " << c.getB() << " i ";
    return os;
}