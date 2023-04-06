


////////////////////////////////////////////////////////////////////////////////////////////////
//   PROBLEM STATEMENT :-
// 
// 
//  Write a program which returns smallest element from singly linear link list. 
//  
//
//  Input linklist :- |10|->|20|->|30|->|40|->|50|->|30|->|70|
//  
//
//  output    =   10
////////////////////////////////////////////////////////////////////////////////////////////////





#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int MinElement(PNODE head)
{
    int iMin = head->Data;

    while (head != NULL)
    {
        if (iMin > (head->Data))
        {
            iMin = head->Data;
        }

        head = head->next;
    }

    return iMin;
}

int Count(PNODE head, int iValue)
{
    int iCnt = 0;
    int iCounter = 0;
    while (head != NULL)
    {
        iCnt++;

        head = head->next;
    }

    return iCnt;
}

void Display(PNODE head)
{
    printf("Number of elements are :");

    while (head != NULL)
    {

        printf("|%d|->", head->Data);

        head = head->next;
    }

    printf("NULL\n");
}

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

int main()
{

    int iNo = 0;
    int iRet = 0;
    PNODE First = NULL;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    Display(First);

    iRet = MinElement(First);
    printf("Smallest element is :%d\n", iRet);
    return 0;
}