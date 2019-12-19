#include <stdio.h>
#include "isort.h"
#define SIZE 50

int main()
{
    int arr[SIZE]={0};
    int num;
    int i=0;
    while(i<SIZE)
    {
        scanf("%d",&num);
        arr[i]=num;
        i++;
    }
    insertion_sort(arr,SIZE);
    for(int i= 0 ; i <SIZE ; i++)
    {
        if(i==SIZE-1)
        {
          printf("%d",arr[i]);  
        }
        else
        {
            printf("%d,",arr[i]);
        }
    }
    printf("\n");
    return 0;
}
