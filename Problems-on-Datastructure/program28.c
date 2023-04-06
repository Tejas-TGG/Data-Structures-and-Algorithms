//  Reverse the link list in place.........


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*Head != NULL)
    {
        newn->next = *Head;
    }
    *Head = newn;
}

void reverse(PPNODE Head)
{
    PNODE Previous =NULL;
    PNODE Current =*Head;
    PNODE Next =NULL;

    while(Current != NULL)
    {
        Next=Current->next;
        Current->next=Previous;
        Previous=Current;
        Current=Next ;
    }

    *Head = Previous ;
}


void Display(PNODE Head)
{
    printf("Elements of linked list are : \n");
    while(Head != NULL)
    {
        printf("|%d|-> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo=0;

    
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    reverse(&First);

    Display(First);
    
    return 0;
}

