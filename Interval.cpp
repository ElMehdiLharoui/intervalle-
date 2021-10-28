#include "Interval.h"
using namespace interval;
Interval::Interval(double a, double b)
{
    if (a < b) {
        this->inf = a;
        this->sup = b;
    }
    else
    {
        this->inf = b;
        this->sup = a;
    }  
}

bool Interval::operator[](Interval& a) const
{
    if ((this->inf <= a.inf) && (this->sup >= a.sup)) return true;
    return false;

}

double Interval::min() const
{
    return this->inf;
}

double Interval::max() const
{
    return this->sup;
}

bool Interval::operator[](double x) const
{
    if ((x >= this->inf) && (x <= this->sup)) return true;
    return false;
}

Interval& Interval::operator+(Interval& a) const
{
    Interval* obj = new Interval();
    // si un intervel est inclus dans l'autre
    if ((*this)[a]) *obj = *this;
    else 
        if (a[(Interval&)(*this)]) *obj = a;
        // 
        else {
            if (this->sup < a.inf || this->inf > a.sup) {
                return *obj;
            }
            if (this->inf < a.inf)obj->inf = this->inf;
            else obj->inf = a.inf;

            if (this->sup > a.sup)obj->sup = this->sup;
            else obj->sup = a.sup;
        }
    return *obj;
}

Interval& Interval::operator&&(Interval& a) const
{
    Interval* obj = new Interval();
    // si un intervel est inclus dans l'autre
    if ((*this)[a]) *obj = a;
    else
        if (a[(Interval&)(*this)]) *obj = *this;
    // 
        else {
            if (this->sup < a.inf || this->inf > a.sup) {
                return *obj;
            }
            if (this->inf < a.inf)obj->inf = a.inf;
            else obj->inf = this->inf;

            if (this->sup > a.sup)obj->sup = a.sup;
            else obj->sup = this->sup;
        }
    return *obj;
}


