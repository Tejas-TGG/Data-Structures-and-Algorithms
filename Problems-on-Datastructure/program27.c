//  Return middle element of link list




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


int MiddleElement(PNODE  Head )
{
    PNODE Fast = Head ;
    PNODE Slow = Head ;
    
    
    while((Fast != NULL) && (Fast->next != NULL))
    {
       Fast=Fast->next->next ; 
       Slow=Slow->next ;
    }

   
    return Slow->data ;
   
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

    iRet = MiddleElement(First );
    
  
    printf("Middle element is %d ",iRet );
    
    
    return 0;
}
