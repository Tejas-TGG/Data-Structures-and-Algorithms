

///////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
//      Write a program which display product of all digits of all elements  of singly linked list
//      
//      Input link-list =   |11|->|17|->|41|->|28|->|50|->|30|->|70|
// 
//      Output      =       1       1       1       2       0       0       0
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

void MinDigit(PNODE head)
{

    while (head != NULL)
    {
        int iDigit = 0;
        int temp = head->Data;
        int imin = temp;                             // Here we have to initialize with greater number ie head->data ,if we initialize with 0 ,condition will never satisfy...

        while ((head->Data) > 0)
        {
            iDigit = (head->Data) % 10;

            if (imin > iDigit)
            {
                imin = iDigit;
            }
            head->Data = (head->Data) / 10;
        }
        printf("%d\t", imin);
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

    MinDigit(First);

    return 0;
}
