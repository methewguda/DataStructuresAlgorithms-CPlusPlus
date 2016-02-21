#include "Polynomial.h"

//defination section
Polynomial::Polynomial()
{
}

Polynomial::~Polynomial()
{
}

int Polynomial::degree() const
{
    return (polynomial.size()-1);
}

double Polynomial::getCoefficient(int power) const
{
    if (power > degree())
    {
        return 0;
    }
        return polynomial[power];
}

double Polynomial::evaluateAt(double x) const
{
    double value = 0.00;

    for (auto it = polynomial.rbegin(); it != polynomial.rend(); ++it)
    {
        value = (value * x) + *it;
    }

    return value;
}

void Polynomial::setCoefficient(const double& newCoefficient, const int& power)
{
    if (polynomial.size() <= power ) 
    {
        polynomial.resize(power);
        polynomial.push_back(newCoefficient);
    }
    polynomial[power]= newCoefficient;
}

void Polynomial::print() const
{
    int s = polynomial.size();

    for (auto i = polynomial.rbegin(); i != polynomial.rend(); ++i)
    {
        s -= 1;

        if (*i != 0)
        {
            cout << *i;
            if (s == 1)
            {
                cout << "x";
            }
            else if (s > 1)
            {
                cout << "x^" << s;
            }
            if (i != polynomial.rend() -1)
            {
                cout << " + ";
            }
        }
    }
}