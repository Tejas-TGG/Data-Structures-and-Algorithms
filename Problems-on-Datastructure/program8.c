

////////////////////////////////////////////////////////////////////////////////////////
//
//  Write a program which returns addition of all even elements from singly linear link list.
//
//  Input linklist :- |11|->|28|->|17|->|41|->|6|->|89|
//
//  ouput :-   34
//
///////////////////////////////////////////////////////////////////////////////////////////


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

int Addition(PNODE head)
{
    int iSum = 0;
    while (head != NULL)
    {

        if ((head->Data) % 2 == 0)
        {
            iSum = iSum + (head->Data);
        }

        head = head->next;
    }

    return iSum;
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
    InsertFirst(&First, 28);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 11);

    Display(First);

    iRet = Addition(First);
    printf("Addition of even elements are:\n %d", iRet);

    return 0;
}