// BINARY SEARCH USING RECURSION //
#include<stdio.h>
#include<conio.h>
int binary_search(int* ptr,int value,int front,int rear);
int main()
{
    int const size   =  10;
    int array[10]  =  {1,2,3,4,5,6,7,8,9,10};
   // int array[10] =  {2,1,5,4,7,6,3,9,8,10};
    int value;

    printf("\n\t Enter the search value : ");
    scanf("%d",&value);

    value = binary_search(array,value,0,size-1);

    if(value==-1)
    {
        printf("\n\t No search value found ");
    }
    else
    {
        printf("\n\t Search value %d at position[%d]",array[value],value);
    }
}
int binary_search(int *ptr,int value,int front,int rear)
{
    int mid = (front+rear)/2;

    if(front>rear)return(-1);

    if(ptr[mid]==value)return(mid);

    if(ptr[mid]<value)
    {
            binary_search(ptr,value,mid+1,rear);
    }
    else
    {
            binary_search(ptr,value,front,mid-1);
    }
}
