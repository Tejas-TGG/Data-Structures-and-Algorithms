////////////////////////////////////////////////////////////
// 
// Linear Search algorithm....
// 
////////////////////////////////////////////////////////////

import java.lang.*;
import java.util.*;

class Array 
{
    public int Arr[];

    public Array(int Size)
    {
        Arr= new int[Size];             // Memory allocation.
    }

    protected void finalize()
    {
        Arr=null;
    }

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter Elements");

        for(int i=0; i<Arr.length;i++)
        {
            Arr[i]=sobj.nextInt();
        }
    }


    public void Display()
    {
        
        System.out.println("Elements are");

        for(int i=0; i<Arr.length;i++)
        {
            System.out.println(Arr[i]);
        }
    }

    
}

class Searching extends Array
{
    public Searching(int iSize)
    {
        super(iSize);                   // Passing parameter to class array..
    }

    public int LinearSearch(int iNo)
    {
        int i = 0;
        for(i = 0; i < Arr.length; i++)
        {
            if(Arr[i] == iNo)
            {
                break;
            }
        }
        if(i == Arr.length)
        {
            return -1;
        }
        else
        {
            return i;
        }
    }
}



class program373
{
    public static void main(String args[])
    {

        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter size of array");
        int iSize = sobj.nextInt();

        Searching aobj = new Searching(iSize);

        aobj .Accept();
        aobj.Display();

        System.out.println("Enter the elements that you want to search");
        int iValue=sobj.nextInt();

        int iRet= aobj.LinearSearch(iValue);

        if(iRet==-1)
        {
            System.out.println("There is no such elements");
        }
        else
        {
            System.out.println("Element is there in the array at index : "+iRet);
        }
    }
}