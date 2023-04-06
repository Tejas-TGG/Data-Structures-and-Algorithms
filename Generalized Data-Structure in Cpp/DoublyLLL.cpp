/////////////////////////////////////////////////////////////////////////
// 
// 
//  Doubly linear link list in generic way.......
//  Technology Used-C++ programming Language......
// 
///////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node *prev;
    struct node *next;
};

template <class T>
class DoublyLL
{
public:
    struct node<T> *Head;
    int Count;

    DoublyLL();

    void Insertfirst(T);

    void InsertLast(T);

    void InsertAtPos(T, int ipos);

    void DeleteFirst();

    void DeleteLAst();

    void DeleteAtPos(int ipos);

    void Display();

    int CountNode();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void DoublyLL<T>::Insertfirst(T No)
{
    struct node <T>*newn = NULL;
    newn = new struct node<T>;
    newn->prev = NULL;
    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
        newn->next->prev = newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }

    Count++;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T No, int ipos)
{
    int iSize = CountNode();

    if ((ipos < 1) || (ipos > (iSize + 1)))
    {
        cout << "Invalid Position" << endl;
        return;
    }
    else if (ipos == 1)
    {
        Insertfirst(No);
    }
    else if (ipos == (iSize + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct node<T> *temp = Head;

        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
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
void DoublyLL<T>::DeleteFirst()
{

    if (Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head->next;
        free(Head->prev);
        Head->prev = NULL;
    }
    Count--;
}

template <class T>
void DoublyLL<T>::DeleteLAst()
{

    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        free(Head);
        Head == NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    Count--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    int iSize = CountNode();

    if ((ipos < 1) || (ipos > (iSize)))
    {
        cout << "Invalid Position" << endl;
        return;
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (iSize))
    {
        DeleteLAst();
    }
    else
    {

        struct node<T> *temp = Head;
        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }

    Count--;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp = Head;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|"
             << "->";

        temp = temp->next;
    }
    cout << "|Null|" << endl;
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

int main()
{
    DoublyLL<int> obj1;
    int iRet = 0;
    obj1.Insertfirst(21);
    obj1.Insertfirst(11);

    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertAtPos(31, 3);
    obj1.DeleteAtPos(3);

    obj1.Display();
    iRet = obj1.CountNode();
    cout << "Number of nodes are:" << iRet << endl;

    DoublyLL<float> obj2;
    float fRet = 0;

    obj2.Insertfirst(21.41);
    obj2.Insertfirst(11.41);

    obj2.InsertLast(51.41);
    obj2.InsertLast(101.41);
    obj2.InsertAtPos(31.41, 3);
    obj2.DeleteAtPos(3);
    obj2.Display();
    fRet = obj2.CountNode();
    cout << "Number of nodes are:" << fRet << endl;

    return 0;
}
