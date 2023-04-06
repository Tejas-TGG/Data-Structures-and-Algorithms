//////////////////////////////////////////////////////////////////////////////////
// 
//  Singly Linear Linked List
//  Technology used - C programming
// 
// 
//////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head, int no)
{
    // Allocate memory for node(Dynamically)
    // Initialize that node

    // Check whether LL is empty or not
    // If LL is empty then new node is the first node so update its address in first pointer through head

    // If LL is not empty then store the address of first node in the next pointer of our new node
    // Update the first pointer through head

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    
    // insert Node
    if (*head == NULL) // LL is empty
    {
        *head = newn;
    }
    else // LL contains atleast one node
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    // Allocate memory for node(Dynamically)
    // Initialize that node

    // Check whether LL is empty or not
    // If LL is empty then new node is the first node so update its address in first pointer through head

    // If LL is not empty then
    // travel till last node of LL
    // store address of new node in next pointer of last node

    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*head == NULL) // LL is empty
    {
        *head = newn;
    }
    else // LL contains atleast one node
    {
        // Travel till last node
        // Store address of new node in next pointer of last node

        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE head)
{
    printf("Elements from linked list are :\n");

    while (head != NULL)
    {
        printf("| %d | ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while (head != NULL)
    {
        iCnt++;
        head = head->next;
    }

    return iCnt;
}

void DeleteFirst(PPNODE head)
{
    // If LL is empty then return
    // If LL contains atleast one node then
    //  Store the address of second node in the first pointer through head
    //  And delete the first code

    PNODE temp = NULL;

    if (*head == NULL) // LL is empty
    {
        return;
    }
    else // LL contains atleast one node
    {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    // if LL is empty then return
    //  if LL contains one node then delete that node and return
    //  if LL contains more than one node then travel till second last node and delete last node

    PNODE temp = NULL;

    if (*head == NULL) // LL is empty
    {
        return;
    }
    else if ((*head)->next == NULL) // LL contains one node
    {
        free(*head);
        *head = NULL;
    }
    else
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
    // Consider no of nodes are 4
    // If position is invalid then return directly (<1 or >5)
    // If position is 1 then call insertfirst
    // If position is N+1 then call Insertlast   ((position is 5)

    int Size = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    Size = Count(*head);

    if ((pos < 1) || (pos > (Size + 1)))
    {
        printf("Position is invalid\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(head, no);
    }

    else if (pos == Size + 1)
    {
        InsertLast(head, no);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *head;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE head, int pos)
{
    // Consider no of nodes are 4
    // If position is invalid then return directly (<1 or >4)
    // If position is 1 then call insertfirst
    // If position is N then call Insertlast   (position is 4)

    int Size = 0;
    int iCnt = 0;
    PNODE temp = NULL;
    PNODE tempdelete = NULL;

    Size = Count(*head);

    if ((pos < 1) || (pos > (Size)))
    {
        printf("Position is invalid\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(head);
    }

    else if (pos == Size)
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

        tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
    }
}

int main()
{
    int iRet = 0;
    PNODE first = NULL;

    InsertFirst(&first, 101); // Call by address;
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertAtPos(&first, 75, 3); // Call to insertAtPos

    DeleteAtPos(&first, 3); // Call to DeleteAtPos

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    InsertFirst(&first, 1); // Call to InsertFirst

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    InsertLast(&first, 111); // Call to InsertLast
    InsertLast(&first, 121); // Call to InsertLast

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    DeleteFirst(&first); // Call to DeleteFirst
    DeleteFirst(&first); // Call to DeleteFirst

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    DeleteLast(&first); // Call to DeleteLast

    Display(first); //  Call by value
    iRet = Count(first);
    printf("NUmber of nodes are : %d\n ", iRet);

    return 0;
}
