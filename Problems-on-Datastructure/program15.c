

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//      Write a program which display largest digits of all elements form singly linked list
//
//      Input link-list =   |11|->|17|->|41|->|28|->|50|->|30|->|70|
//
//      Output      =       1       7       4       8       5       3       7
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

    while (head != NULL)
    {
        int iDigit = 0;

        int iMax = iDigit;

        while ((head->Data) > 0)
        {
            iDigit = (head->Data) % 10;
            if (iMax < iDigit)
            {
                iMax = iDigit;
            }
            head->Data = (head->Data) / 10;
        }
        printf("%d\t", iMax);
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
