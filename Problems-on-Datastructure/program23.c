//  accept number from user and display sum  of digits of each element in linked list


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



void DisplaysumDigits(PNODE  Head)
{
    int iNo=0;
    int iSum=0;
    int iDigit=0;

    while(Head != NULL)
    {
        iNo = Head->data;
        iSum = 0 ;
        
        while(iNo>0)
        {
            iDigit=iNo % 10 ;
            iSum = iSum + iDigit ;
            iNo =iNo /10 ;
        }

       
        printf("sum of Digits of  number %d is : %d \n",Head->data,iSum);
        
      
       Head=Head->next;

    }
    
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo=0;

    InsertFirst(&First,28);
    InsertFirst(&First,6);
    InsertFirst(&First,496);
    InsertFirst(&First,24);
    InsertFirst(&First,22);

    Display(First);

    DisplaysumDigits(First);

    return 0;
}
