/////////////////////////////////////////////////////////
// 
// 
// Doubly linear link list...
// Technology used - C programming
// 
// 
/////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev; 
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void display(PNODE head)
{
    printf("Elements from linked list are :\n");

    while (head != NULL)
    {
        printf("| %d | ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int count(PNODE head)
{
    int iCnt = 0;

    while (head != NULL)
    {
        iCnt++;
        head = head->next;
    }

    return iCnt;
}
void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; //*

    if (*head == NULL) // If LL is empty
    {
        *head = newn;
    }
    else // LL contains one node
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; //*

    if (*head == NULL)
    {
        *head = newn;
    }

    else

    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE head)
{
    if (*head == NULL) // If LL is empty
    {
        return;
    }

    if ((*head)->next == NULL) // Single node
    {
        free(*head);
        *head = NULL;
    }
    else // More than one node
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if (*head == NULL) // If LL is empty
    {
        return;
    }

    if ((*head)->next == NULL) // Single node
    {
        free(*head);
        *head = NULL;
    }
    else // More than one node
    {
        temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE head, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int size = 0, iCnt = 0;
    size = count(*head);

    if ((pos < 1) || (pos > (size + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(head, no);
    }

    else if (pos == size + 1)
    {
        InsertLast(head, no);
    }

    else
    {
        temp = *head;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL; //*

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn; //*
        temp->next = newn;
        newn->prev = temp; //*
    }
}

void DeleteAtPos(PPNODE head, int pos)
{

    PNODE temp = NULL;

    int size = 0, iCnt = 0;
    size = count(*head);

    if ((pos < 1) || (pos > (size)))
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(head);
    }

    else if (pos == size)
    {
        DeleteLast(head);
    }

    else
    {
        temp = *head;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    display(first); //  Call by value
    iRet = count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    InsertLast(&first, 51);
    InsertLast(&first, 101);

    display(first);
    iRet = count(first);
    printf("Number of nodes are : |%d|\n", iRet);

    DeleteFirst(&first);

    display(first);
    iRet = count(first);
    printf("Number of nodes are : |%d|\n", iRet);

    DeleteLast(&first);

    display(first);
    iRet = count(first);
    printf("Number of nodes are : |%d|\n", iRet);

    InsertAtPos(&first, 555, 4);
    display(first);

    iRet = count(first);
    printf("Count of elements are:%d\n", iRet);

    DeleteAtPos(&first, 4);
    display(first);

    iRet = count(first);
    printf("Count of elements are:%d\n", iRet);

    return 0;
}
