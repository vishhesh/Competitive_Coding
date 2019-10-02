#include<stdio.h>
int main()
{
    int array[] = {0,3,2,1,6,7,5,10,4,8};
    int offset;

    Counting_sort(array,10);

    printf("\n");

    for(offset=0;offset<10;offset++)
    {
       printf("%d\t",array[offset]);
    }
}
void Counting_sort(int array[],int size)
{
    int min_element = array[0],max_element = array[0],
        offset,*assoc_array,temp,tempsize,*sorted_array;

    for(offset=1;offset<size;offset++)
    {
        if(array[offset]<min_element)
          min_element = array[offset];

        if(array[offset]>max_element)
          max_element = array[offset];
    }

    tempsize = max_element - min_element + 1;

    assoc_array = (int*)calloc(tempsize,sizeof(int));

    for(offset=0;offset<tempsize;offset++)
    {
       assoc_array[array[offset] - min_element]++;
    }

    temp = assoc_array[0];

    for(offset=1;offset<tempsize;offset++)
    {
       assoc_array[offset] = assoc_array[offset] + temp;
       temp = assoc_array[offset];
    }

    sorted_array = (int*)calloc(size,sizeof(int));

    for(offset=0;offset<size;offset++)
    {
      sorted_array[assoc_array[array[offset]-min_element]-1] = array[offset];

      assoc_array[array[offset] - min_element]--;
    }

    for(offset=0;offset<size;offset++)
    {
      array[offset] = sorted_array[offset];
    }
}
