
////////////////////////////////////////////////////////////////////////////////////////
// 
//  Write a program which displays all elements which are perfect from singly linear link list.
// 
//  Input linklist :- |11|->|28|->|17|->|41|->|6|->|89|
// 
//  ouput :-   6    28
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

void PerfectNum(PNODE head)
{

    while (head != NULL)
    {
        int iCnt = 0;
        int iSum = 0;

        for (iCnt = 1; iCnt <= (head->Data) / 2; iCnt++)
        {
            if ((head->Data) % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if (head->Data == iSum)
        {
            printf("Perfect number is :%d\n", head->Data);
        }
        else
        {
            printf("%d is not Perfect number:\n", head->Data);
        }

        head = head->next;
    }
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
    InsertFirst(&First, 496);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 28);
    InsertFirst(&First, 30);
    InsertFirst(&First, 62);
    InsertFirst(&First, 6);

    Display(First);
    PerfectNum(First);

    return 0;
}