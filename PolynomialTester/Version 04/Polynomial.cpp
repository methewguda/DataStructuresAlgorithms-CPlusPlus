#include "Polynomial.h"

//definition section for PolyNode Structure
struct PolyNode
{
    double coefficient;
    int power;
    PolyNode* next;
};

//definition section for addNode
void addNode(PolyNode*& cur, double c, int p)
{
    PolyNode* temp = new PolyNode;
    temp->coefficient = c;
    temp->power = p;
    temp->next = nullptr;

    if (cur == nullptr) 
    {
        cur = temp;
        return;
    }
    else
    {
        temp->next = cur;
        cur = temp;
    }
}

//definition section for removeNode
void removeNode(PolyNode*& cur, int p)
{
    if (cur == nullptr)
    {
        return;
    }
    else if (cur->power == p)
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

//definition section for changeNode
void changeNode(PolyNode*& cur, int p, double c)
{
    if (cur == nullptr)
    {
        addNode(cur, c, p);
    }
    else if(cur->power < p)
    {
        addNode(cur, c, p);
    }
    else if (cur->power == p)
    {
        cur->coefficient = c;    }
    else    {
        changeNode(cur->next, p, c);
    }
}

//definition section for CopyNodes
PolyNode* CopyNodes(PolyNode* srcNode)
{
    if (srcNode == nullptr) return nullptr;
    PolyNode* copy = new PolyNode;
    copy->coefficient = srcNode->coefficient;
    copy->power = srcNode->power;
    copy->next = CopyNodes(srcNode->next);
    return copy;
}

//definition section for DeleteNodes
void DeleteNodes(PolyNode* cur) 
{
    if (cur != nullptr) 
    {
        PolyNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

//definition section for Polynomial
Polynomial::Polynomial()
{
    head = nullptr;
}

//definition section for copy constructor
Polynomial::Polynomial(const Polynomial& src)
{
    head = CopyNodes(src.head);
}

//definition section for swap
void Polynomial::swap(Polynomial& other)
{
    std::swap(head, other.head);
}

//definition section for ~Polynomial
Polynomial::~Polynomial()
{
    DeleteNodes(head);
}

//definition section for operator=
Polynomial& Polynomial::operator=(Polynomial src)
{
    this->swap(src);
    return *this;
}

//definition section for degree
int Polynomial::degree() const
{
    if (head == nullptr)
    {
        return 0;
    }
    else
    {
        return head->power;
    }
}

//definition section for getCoefficient
double Polynomial::getCoefficient(int power) const
{
    PolyNode * temp = head;

    while (temp != nullptr && temp->power !=power)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        return 0;
    }
    else
    {
        return temp->coefficient;
    }
}

//definition section for evaluateAt
double Polynomial::evaluateAt(double x) const
{
    double newValue = 0.00;

    PolyNode * temp = head;
    while (temp != nullptr)
    {
        newValue = (newValue * x) + temp->coefficient;
        temp= temp->next;
    }

    return newValue;
}

//definition section for setCoefficient
void Polynomial::setCoefficient(const double& newCoefficient, 
                                const int& power)
{
    if (head == nullptr)
    {
        addNode(head, newCoefficient, power);
    }
    else if (newCoefficient == 0.00)
    {
        removeNode(head, power);
    }
    else
    {
        changeNode(head, power, newCoefficient);
    }
}

//definition section for print()
void Polynomial::print() const
{
    PolyNode * temp = head;
    while (temp != nullptr)
    {
        if (temp->coefficient == 1)
            cout << "x + ";
        else
        {
            cout << temp->coefficient;

            if (temp->power > 0)
            {cout << "x";}
            if (temp->power > 1)
            {cout << "^" << temp->power;}
            if (temp->power > 0 && temp->next != nullptr)
            {cout << " + ";}
        }

        temp = temp->next;
    }
}

//definition section for operator<<
ostream& operator<<(ostream& out, const Polynomial& list)
{
    PolyNode* temp = list.head;

    while (temp != nullptr)
    {
        if (temp->coefficient == 1)
        {
            out << "x + ";
        }
        else
        {
            out << temp->coefficient;

            if (temp->power > 0)
            {
                out << "x";
            }
            if (temp->power > 1)
            {
                out << "^" << temp->power;
            }
            if (temp->power > 0 && temp->next != nullptr)
            {
                out << " + ";
            }
        }

        temp = temp->next;
    }

    return out;
}