////////////////////////////////////////////////////////////////////
// 
// 
//  Doubly circular link list by generic way..................
//  Technology used-C++ programming...........
// 
////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCLL
{
private: // Charecteristics
    struct node<T> *Head;
    struct node<T> *Tail;
    int Count;

public: // Behaviours
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int CountNode();
};

template <class T>
DoublyCLL<T>::DoublyCLL() // Default constructor
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL && Tail == NULL) // If link list is empty..........
    {
        Head = newn;
        Tail = newn;
    }

    else // If link list contains more than one node
    {
        newn->next = Head;
        newn->prev = Tail;
        Tail->next = newn;
        Head->prev = newn;
        Head = newn;
    }

    Count++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL && Tail == NULL) // If link list is empty.........
    {
        Head = newn;
        Tail = newn;
    }

    else // If link list contains more than one node
    {
        newn->next = Head;
        newn->prev = Tail;
        Tail->next = newn;
        Head->prev = newn;
        Tail = newn;
    }

    Count++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T iNo, int ipos)
{

    int iSize = 0;

    iSize = CountNode();

    if ((ipos < 1) && ipos > (iSize + 1))
    {
        cout << "Invalid position\n";
    }

    else if (ipos == 1)
    {
        InsertFirst(iNo);
    }
    else if (ipos == (iSize + 1))
    {
        InsertLast(iNo);
    }

    else
    {
        int iCnt = 0;

        struct node<T> *temp = Head;

        struct node<T> *newn = NULL;
        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }

    Count++;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{

    if (Head == NULL && Tail == NULL)
    {
        return;
    }

    else if (Head == Tail)
    {
        free(Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail->next = Head->next;
        free(Head);
        Head = Tail->next;
        Head->prev = Tail;
    }

    Count--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{

    if (Head == NULL && Tail == NULL)
    {
        return;
    }

    else if (Head == Tail)
    {
        free(Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T> *tempdelete = Tail;
        Tail->prev->next = Head;
        Head->prev = Tail->prev;
        Tail = Tail->prev;
        free(tempdelete);
    }

    Count--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
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

        struct node<T> *tempDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(tempDelete);
    }

    Count--;
}

template <class T>
void DoublyCLL<T>::Display()
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
int DoublyCLL<T>::CountNode()
{
    return Count;
}

int main()
{
    DoublyCLL<int> obj1;
    int iRet = 0;
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
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

    DoublyCLL<float> obj2;
    float fRet = 0;
    obj2.InsertFirst(21.2);
    obj2.InsertFirst(11.2);
    obj2.InsertLast(51.2);
    obj2.InsertLast(101.2);
    obj2.InsertAtPos(31.2, 3);
    obj2.InsertAtPos(41.2, 4);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPos(3);
    obj2.Display();
    iRet = obj2.CountNode();
    cout << "Number of nodes are:" << iRet << endl;

    return 0;
}
