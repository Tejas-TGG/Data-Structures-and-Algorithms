/////////////////////////////////////////////////////////////////////
// 
// 
//  Singly Linear link list by generic programming..................
//  Technology Used - c++ programming Language..
// 
/////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{

public:
    struct node<T> *Head;
    int Count;

    SinglyLL();

    void Insertfirst(T);

    void InsertLast(T);

    void InsertAtPos(T, int ipos);

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(int ipos);

    void Display();

    int CountNo();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}
template <class T>
void SinglyLL<T>::Insertfirst(T No)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->next = NULL;
    newn->data = No;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn->next = Head;
        Head = newn;
    }

    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = No;
    newn->next = NULL;

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
    }

    Count++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int ipos)
{
    int size = CountNo();

    if (ipos < 1 && ipos > (size + 1))
    {
        cout << "Invalid Position\n";
    }

    else if (ipos == 1)
    {
        Insertfirst(No);
    }
    else if (ipos == (size + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        struct node<T> *temp = Head;

        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

    Count++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct node<T> *temp = Head;
        Head = temp->next;
        free(temp);
    }

    Count--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    if (Head->next == NULL)
    {
        free(Head);
        Head = NULL;
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
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int iSize = 0;
    iSize = CountNo();

    if ((ipos < 0) && (ipos > iSize))
    {
        cout << "Invalid Position" << endl;
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;
        int iCnt = 0;
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
void SinglyLL<T>::Display()
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
int SinglyLL<T>::CountNo()
{
    return Count;
}

int main()
{
    SinglyLL<int> obj1;
    int iRet = 0;
    obj1.Insertfirst(21);
    obj1.Insertfirst(11);

    obj1.InsertLast(51);
    obj1.InsertLast(101);

    obj1.InsertAtPos(41, 3);

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPos(2);

    obj1.Display();

    iRet = obj1.CountNo();
    cout << "Total number of nodes are:" << iRet << endl;

    SinglyLL<float> obj2;
    float fRet = 0.0;
    obj2.Insertfirst(21.5);
    obj2.Insertfirst(11.7);

    obj2.InsertLast(51.9);
    obj2.InsertLast(101.3);

    obj2.InsertAtPos(71.5, 4);

    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPos(2);

    obj2.Display();

    fRet = obj2.CountNo();
    cout << "Total number of nodes are:" << fRet << endl;

    return 0;
}
