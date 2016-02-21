#include <iostream>
using namespace std;

struct PolyNode
{
    double coefficient;
    int power;
    PolyNode* next;
};

void addNode(PolyNode*& cur, double c, int p);
/**<
adds a node with coefficient c and power p in front of the one 
cur is currently pointing at
@return void
@param cur a referenced pointer
@param c a double type value for coefficient
@param p a integer value for power
@pre
-# cur must be a reference pointer type
-# c must be double vale
-# p must be integer value
@post
- adds a node with coefficient c and power p in front 
of the one cur is currently pointing at
*/

void removeNode(PolyNode*& cur, int p);
/**<
removes the node with power p at or after the 
node cur is currently pointing at.
@return void
@param cur a referenced pointer
@param p a positive integer value for power
@pre
-# cur must be a reference pointer type
-# p must be integer value
@post
-# removes the node with power p at or after the 
node cur is currently pointing at.
-# If there is no node with power p, the list remains unchanged.
*/

void changeNode(PolyNode*& cur, int p, double c);
/**<
changes the coefficient of the node with power p at or after the
node cur is currently pointing at. 
@return void
@param cur a referenced pointer
@param c a double type value for coefficient
@param p a integer value for power
@pre
-# cur must be a reference pointer type
-# c must be double vale
-# p must be integer value
@post
-# cur is null, in which case we add the new node in front of cur
-# cur->power is less than p, in which case we (again) add the new 
node in front of cur.
-# cur->power is equal to p, in which case we change *cur's coefficient to c.
*/

void printLineOfNodes(PolyNode* cur);
void printNodes(PolyNode* cur);
void pause();

int main()
{
    cout << "\nEmpty list:";
    PolyNode* head = nullptr;
    printLineOfNodes(head);
    cout << "\nAdding 9:";
    addNode(head, 9, 0);
    printLineOfNodes(head);
    cout << "\nAdding 7x^3:";
    addNode(head, 7, 3);
    printLineOfNodes(head);
    cout << "\nAdding -x^2:";
    addNode(head->next, -1, 2);     // <--- next used here
    printLineOfNodes(head);
    cout << "\nAdding 4x^5:";
    addNode(head, 4, 5);
    printLineOfNodes(head);
    pause();

    cout << "\nRemoving x^2 term:";
    removeNode(head, 2);        // middle
    printLineOfNodes(head);
    cout << "\nRemoving x^5 term:";
    removeNode(head, 5);        // front
    printLineOfNodes(head);
    cout << "\nRemoving x^0 term:";
    removeNode(head, 0);        // end
    printLineOfNodes(head);
    cout << "\nRemoving x^1 term:";
    removeNode(head, 1);        // non-existent
    printLineOfNodes(head);
    pause();

    cout << "\nChanging x^3 term:";
    changeNode(head, 3, 10);   // existing
    printLineOfNodes(head);
    cout << "\nChanging x^1 term:";
    changeNode(head, 1, 20);   // new at end
    printLineOfNodes(head);
    cout << "\nChanging x^100 term:";
    changeNode(head, 100, 30); // new at front
    printLineOfNodes(head);
    cout << "\nChanging x^50 term:";
    changeNode(head, 50, -10);  // new in middle
    printLineOfNodes(head);
    cout << "\nChanging x^50 term:";
    changeNode(head, 50, 40);   // change in middle, again
    printLineOfNodes(head);
    cout << "\nChanging x^-1 term:";
    changeNode(head, -1, 5);   // new at end, again
    printLineOfNodes(head);
    pause();
}

void pause()
{
    cout << "\nPress enter...";
    cin.ignore(100, '\n');
    cout << "\n\n";
}

void printLineOfNodes(PolyNode* cur)
{
    cout << "\n\t[";
    printNodes(cur);
    cout << "\n";
}

void printNodes(PolyNode* cur)
{
    if (cur == nullptr) cout << "/]";
    else
    {
        cout << "*] --> [" << cur->coefficient << "|" << cur->power << "|";
        printNodes(cur->next);
    }
}

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