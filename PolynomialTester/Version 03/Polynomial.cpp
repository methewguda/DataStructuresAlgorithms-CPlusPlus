#include "Polynomial.h"

//defination section

struct PolyNode
{
    double coefficient;
    int power;
    PolyNode* next;
};

void addNode(PolyNode*& cur, double c, int p)
{
    PolyNode* temp = new PolyNode();
    temp->coefficient = c;
    temp->power = p;
    temp->next = nullptr;

    if (cur == nullptr) 
    {
        cur = temp ; 
        return ;
    }
    else
    {
        temp->next = cur ;
        cur = temp ;
    }
}

void removeNode(PolyNode*& cur, int p)
{
    if (cur == nullptr)
    {
        return;
    }

    if (cur->power == p)
    {
        PolyNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    else
    {
        removeNode(cur->next, p);
    }
}

void changeNode(PolyNode*& cur, int p, double c)
{
    if (cur == nullptr || cur->power < p )
    {
        addNode(cur, c, p);
    }
    else if (cur->power == p)
    {
        cur->coefficient = c;    }
    else     {
        changeNode(cur->next, p, c);
    }
}

Polynomial::Polynomial()
{
    head = nullptr;
}

Polynomial::~Polynomial()
{
}

int Polynomial::degree() const
{
    if (head == nullptr)
        return 0;
    return head->power;
}

double Polynomial::getCoefficient(int power) const
{
    if (power >= 0 && power <= this->degree())
    {
        PolyNode * temp = head;

        while (temp)
        {
            if (temp->power == power)
                return temp->coefficient;
            temp = temp->next;
        }
    }

    return 0;
}

double Polynomial::evaluateAt(double x) const
{
    double value = 0.00;

    PolyNode * temp = head;
    while (temp != nullptr)
    {
        value = (value * x) + temp->coefficient;
        temp= temp->next;
    }

    return value;
}

void Polynomial::setCoefficient(const double& newCoefficient, const int& power)
{
    if (power < 0)
        return;

    if (newCoefficient == 0)
        removeNode(head, power);
    else
        changeNode(head, power, newCoefficient);
}

void Polynomial::print() const
{
    PolyNode * temp = head;
    while (temp != nullptr)
    {
        cout << temp->coefficient;
        if (temp->power > 0)
            cout << "x";
        if (temp->power > 1)
            cout << "^" << temp->power;
        if (temp->power > 0 && temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
}