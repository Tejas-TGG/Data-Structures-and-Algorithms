////////////////////////////////////////////////////
// 
//  Datastructure  Queue  in Generic Way................
//  Technology Used - C++ programming...........
// 
///////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{

public:
    struct node<T> *Head;
    int Count;

    Queue();

    void Enqueue(T); // Insertlast.......

    void Dequeue(); // Deletefirst

    void Display();

    int CountNo();
};

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void Queue<T>::Enqueue(T No)
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
void Queue<T>::Dequeue()
{
    T no;

    if (Count == 0)
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        no = Head->data;

        struct node<T> *temp = Head;
        Head = Head->next;
        delete temp;
        Count--;
        cout << "Removed element is: " << no << endl;
    }
}

template <class T>
void Queue<T>::Display()
{
    cout << "Elements from Queue is :" << endl;

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
int Queue<T>::CountNo()
{
    return Count;
}

int main()
{
    Queue<int> obj1;
    int iRet = 0;

    obj1.Enqueue(11);
    obj1.Enqueue(21);
    obj1.Enqueue(51);
    obj1.Enqueue(101);

    obj1.Display();

    iRet = obj1.CountNo();
    cout << "Number of elements in Queue is :" << iRet << endl;

    obj1.Dequeue();
    obj1.Dequeue();
    obj1.Dequeue();

    obj1.Display();

    iRet = obj1.CountNo();
    cout << "Number of elements in Queue is :" << iRet << endl;

    obj1.Dequeue();
    obj1.Dequeue();

    iRet = obj1.CountNo();
    cout << "Number of elements in Queue is :" << iRet << endl;

    return 0;
}
