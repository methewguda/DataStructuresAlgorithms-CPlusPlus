#include <iomanip>
#include "Polynomial.h"
#include "utilities.h"

using std::endl;
using std::setw;
using std::setprecision;
using std::right;
using std::fixed;
using Scobey::Pause;

void printTable(const Polynomial& p, double s, double e, double g);
/**<
print table of evaluated polynomial
@return void
@param p a constant polynomial object
@param s a double value
@param e a double value
@param g a double value
*/

void scale (Polynomial& p, double value);
/**<
prints table of multiplied polynomial
@return void
@param p a constant polynomial object
@param value a double value
*/

Polynomial addPolynomials(const Polynomial& p, const Polynomial& q);
/**<
prints added polynomials
@return Polynomial
@param p a constant polynomial object
@param q a constant polynomial object
*/

int main()
{
    cout << "Building Polynomials:" << endl << endl;

    Polynomial p;

    p.setCoefficient(0, 0);
    p.setCoefficient(7, 3);
    p.setCoefficient(4, 5);
    p.setCoefficient(-1, 2);

    cout << "p = ";
    p.print();
    cout << endl;

    Polynomial q;

    q.setCoefficient(-4,0);
    q.setCoefficient(2, 2);
    q.setCoefficient(5,1);

    cout << "q = ";
    q.print();
    cout << endl << endl;

    Pause();

    cout << "Evaluated Polynomial Table (for p):" << endl << endl;
    printTable(p, 0.0, 1.0, 0.1);

    cout << "Evaluated Polynomial Table (for q):" << endl << endl;
    printTable(q, 0.0, 1.0, 0.1);

    Pause();

    cout << "Polynomial Scaled with 2.5: " << endl << endl;

    cout << "p = ";
    scale (p, 2.5);
    cout << endl;

    cout << "q = ";
    scale (q, 2.5);
    cout << endl << endl;

    Pause();

    cout << "Added two Polynomials: " << endl << endl;

    p.setCoefficient(9, 0);
    p.setCoefficient(7, 2);
    p.setCoefficient(4, 5);
    p.setCoefficient(-1, 3);

    cout << "p = ";
    p.print();
    cout << endl;

    q.setCoefficient(-4,0);
    q.setCoefficient(2, 2);
    q.setCoefficient(5,1);

    cout << "q = ";
    q.print();
    cout << endl;

    Polynomial r =  addPolynomials(p, q);
    
    cout << "Sum = ";
    r.print();

    cout << endl << endl;
    Pause();
}

//defination section
void printTable(const Polynomial& p, double s, double e, double g)
{
    cout << setw(10) << right << "x" << setw(10) << right << "f(x)" << endl;
    while (s <= e)
    {
        cout << fixed ;
        cout << setw(10) << right << setprecision(2) << s 
            << setw(10) << right << p.evaluateAt(s) << endl;
        s += g;
    }

    cout << endl;
}

void scale (Polynomial& p, double value)
{
    double scaleValue = 0.0;

    for (int i = 0; i <= p.degree(); ++i)
    {
        scaleValue = p.getCoefficient(i);
        scaleValue = scaleValue * value;
        p.setCoefficient(scaleValue, i);
    }


    p.print();
}

Polynomial addPolynomials(const Polynomial& p, const Polynomial& q)
{
    Polynomial r;

    int rDegree = 0;

    if(p.degree() > q.degree())
    {
        rDegree = p.degree();
    }
    else if (p.degree() < q.degree())
    {
        rDegree = q.degree();
    }
    else
    {
        rDegree = p.degree();
    }

    rDegree = rDegree;

    double coef = 0.00;

    for (int i = 0; i <= rDegree; i++)
    {
        coef = p.getCoefficient(i) + q.getCoefficient(i);
        r.setCoefficient(coef, i);
    }

    return r;
}