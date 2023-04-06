
///////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
//      Write a program which reverse each element of singly linked list
//      
//      Input link-list =   |11|->|17|->|41|->|28|->|50|->|30|->|70|
// 
//      Output      =       11      71      14      82      5       3       7
// 
////////////////////////////////////////////////////////////////////////////////////////////////////


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

void Reverse(PNODE head)
{
    int iDigit = 0;

    while (head != NULL)
    {
        int iSum = 0;
        int iRev = 0;
        while ((head->Data) > 0)
        {
            iDigit = (head->Data) % 10;
            iRev = iRev * 10 + iDigit;

            head->Data = (head->Data) / 10;
        }
        printf("%d\t", iRev);
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
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 28);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 11);

    Display(First);

    Reverse(First);

    return 0;
}
