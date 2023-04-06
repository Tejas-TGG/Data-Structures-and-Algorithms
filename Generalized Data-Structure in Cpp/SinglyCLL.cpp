////////////////////////////////////////////////////////////////////
// 
// 
//  Singly circular link list by generic way..................
//  Technology used- C++ programming...........
// 
////////////////////////////////////////////////////////////////////


#include <iostream>
#include<algorithm>
#include <forward_list>
#include <list>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node *next;
};

template <class T>

class SinglyCLL
{
private: // Charecteristics
    struct node<T> *Head;
    struct node<T> *Tail;
    int Count;

public:          // Behaviours
    SinglyCLL(); // Default constructor

    void push_front(T);

    void InsertLast(T);

    void InsertAtPos(T, int ipos);

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(int ipos);

    void Display();

    bool Empty();

    int CountNode();
};

template <class T>
SinglyCLL<T>::SinglyCLL() // Default constructor
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template <class T>
void SinglyCLL<T>::push_front(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL contains at least one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;

    Count++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL contains at least one node
    {

        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;

    Count++;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T iNo, int ipos)
{
    int iSize = 0;

    iSize = CountNode();

    if ((ipos < 1) && ipos > (iSize + 1))
    {
        cout << "Invalid position\n";
    }

    else if (ipos == 1)
    {
        push_front(iNo);
    }
    else if (ipos == (iSize + 1))
    {
        InsertLast(iNo);
    }

    else
    {
        int iCnt = 0;

        struct node<T> *newn = NULL;
        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;

        struct node<T> *temp = Head;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

    Count++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains at least one node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else
    {
        Tail->next = Head->next;
        delete Head;
        Head = Tail->next;
    }

    Count--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains at least one node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else // If link list contain more than  node..............
    {
        struct node<T> *temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = Head;
        Tail = temp;
    }

    Count--;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int iSize = 0;

    iSize = CountNode();

    if ((ipos < 1) && ipos > (iSize))
    {
        cout << "Invalid position\n";
    }

    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (iSize))
    {
        DeleteLast();
    }

    else
    {
        int iCnt = 0;
        struct node<T> *temp = Head;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        struct node<T> *tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
    }

    Count--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    do
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;

    } while (temp != Tail->next);

    cout << "NULL";
    cout << endl;
}

template <class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}

template <class T>
bool SinglyCLL<T> :: Empty()
{
    if(Count <= 0  ||  Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    


    SinglyCLL<int> obj1;
    int iRet = 0;

    bool bRet = false;

    bRet = obj1.Empty();
    if(bRet == true)
    {
        cout << "\nEmpty\n"<<endl;
    }
    else
    {
        cout << "\nNot empty\n"<<endl;
    }

    obj1.push_front(21);
    obj1.push_front(11);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertAtPos(31, 3);
    obj1.InsertAtPos(41, 4);
    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.CountNode();
    cout << "Number of nodes are:" << iRet << endl;

    SinglyCLL<float> obj2;
    float fRet = 0;

    obj2.push_front(21.2);
    obj2.push_front(11.2);
    obj2.InsertLast(51.2);
    obj2.InsertLast(101.2);
    obj2.InsertAtPos(31.2, 3);
    obj2.InsertAtPos(41.2, 4);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPos(3);
    obj2.Display();
    fRet = obj2.CountNode();
    cout << "Number of nodes are:" << fRet << endl;

    bRet = obj1.Empty();
    if(bRet == true)
    {
        cout << "\nEmpty\n"<<endl;
    }
    else
    {
        cout << "\nNot empty\n"<<endl;
    }
    return 0;
}
