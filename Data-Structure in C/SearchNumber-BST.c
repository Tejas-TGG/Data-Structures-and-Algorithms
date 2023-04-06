////////////////////////////////////////////////////
//
//  Search number in BST........
// 
////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int iNo)
{
    PNODE temp = *Head;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)   // BST empty
    {
        *Head = newn;
    }
    else
    {
            while(1)
            {
                    if(iNo > temp->data)        // R
                    {
                            if(temp->rchild == NULL)
                            {
                                temp->rchild = newn;
                                break;
                            }
                            temp = temp->rchild;
                    }
                    else if(iNo < temp->data)   // L
                    {
                             if(temp->lchild == NULL)
                            {
                                temp->lchild = newn;
                                break;
                            }
                            temp = temp->lchild;
                    }
                    else if(iNo == temp->data)  // Duplicate
                    {
                        free(newn);
                        printf("Data is already there in BST");
                        break;
                    }
            }
    }
}

bool checknumber(PNODE Head , int No)
{
    bool bret=false ; 

    if(Head == NULL)
    {
        printf("BST is empty");
        return bret;
    }

    while(Head!=NULL)
    {
        if(No == Head->data )
        {
            bret = true ;
            break;
        }
        else if(No > Head->data)
        {
            Head=Head->rchild;
        }
        else if(No < Head->data)
        {
            Head=Head->lchild;
        }
    }

    return bret;

}


void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        printf("%d ",Head->data);
        Inorder(Head->rchild);
    }
}

void Preorder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d ",Head->data);
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

void Postorder(PNODE Head)
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);
        Postorder(Head->rchild);
        printf("%d ",Head->data);
    }
}

int main()
{
    PNODE First =NULL;

    int iValue = 0;

    bool bret=false;

    Insert(&First,11);
    Insert(&First,21);
    Insert(&First,7);

    // 7    11      21          L   D   R           // Inorder
    // 11   7   21              D   L   R           // Preorder
    // 7    21  11              L   R   D           // Postorder

    printf("\nInorder data\n");
    Inorder(First);

    printf("\nPostorder data\n");
    Postorder(First);

    printf("\nPreorder data\n");
    Preorder(First);

    printf("\nEnter element that want to search:\n");
    scanf("%d",&iValue);

    bret=checknumber(First , iValue);

    if(bret == true)
    {
        printf("%d is present in BST\n" , iValue);
    }
    else
    {
        printf("%d is not present in BST\n",iValue);
    }

    return 0;
}
