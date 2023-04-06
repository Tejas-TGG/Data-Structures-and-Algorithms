// Accept link list from user and also number from user and 
//  return position at first occurance



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

int Summation(PNODE Head)
{
    int iSum =0;

    while(Head!= NULL)
    {
        iSum = iSum + (Head->data);
        Head = Head->next;
    }
    return iSum;
}

int Maximum(PNODE  Head)
{
    int iMax = 0;
    if(Head != NULL)
    {
        iMax = Head->data;
    }

    while(Head != NULL)
    {
        if(Head->data > iMax)
        {
            iMax = Head->data;
        }
        Head = Head->next;
    }
    return iMax;
}


int FirstOccurance(PNODE  Head , int no)
{
    int icnt = 1;
    
    while(Head != NULL)
    {
       if(Head->data==no)
       {
          break;
       }

       icnt++;

       Head=Head->next;
    }
    
    if(Head == NULL)
    {
        return -1;
    }
    else
    {
        return icnt ;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo=0;

    InsertFirst(&First,10);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,20);

    Display(First);

    printf("Enter number :\n");
    scanf("%d",&iNo);

    iRet = FirstOccurance(First, iNo );
    
    if(iRet == -1)
    {
        printf("There is no such element");
    }
    else
    {
        printf("First occurance is at %d ",iRet );
    }
    
    return 0;
}
