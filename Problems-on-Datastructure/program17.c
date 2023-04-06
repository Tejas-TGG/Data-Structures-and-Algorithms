// Problems on linked-list...........

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head , int no)
{
    PNODE newn = NULL;
    newn= (PNODE)malloc(sizeof(NODE));
    newn->Data=no;
    newn->next=NULL;

    if(*head == NULL)
    {
        *head=newn;
    }
    else
    {
        newn->next=*head;
        *head=newn;

    }
}

void Display(PNODE head)
{

    printf("Elements of linked list are : \n");
    while(head != NULL)
    {
        printf("|%d|-> ",head->Data);
        head = head->next;
    }
    printf("NULL \n");

}

int main()
{
    PNODE first =NULL;

    InsertFirst(&first , 101);
    InsertFirst(&first , 51);
    InsertFirst(&first , 21);
    InsertFirst(&first , 11);

    Display(first);


    return 0;
}

