

///////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
//      Write a program which display all pallindrome elements of singly linked list
//      
//      Input link-list =   |11|->|17|->|41|->|28|->|50|->|30|->|70|
// 
//      Output      =       11      414     6
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

void DisplayPallindrome(PNODE head)
{
    int iDigit = 0;

    while (head != NULL)
    {
        int iSum = 0;
        int iRev = 0;
        int itemp = head->Data;
        
        while ((head->Data) > 0)
        {

            iDigit = (head->Data) % 10;
            iRev = iRev * 10 + iDigit;

            head->Data = (head->Data) / 10;
        }
        if (iRev == itemp)
        {
            printf("%d\t", iRev);
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
    InsertFirst(&First, 70);
    InsertFirst(&First, 6);
    InsertFirst(&First, 50);
    InsertFirst(&First, 28);
    InsertFirst(&First, 41);
    InsertFirst(&First, 414);
    InsertFirst(&First, 11);

    Display(First);

    DisplayPallindrome(First);

    return 0;
}
