#include <stdio.h>
#include "isort.h"
#define SIZE 50

void shift_element(int*arr,int i)
{
    int j=0;   
    while(j<i)
    {
        *(arr+i-j)=*(arr+i-j-1);
        j++;
    }
}
void insertion_sort(int *arr,int length)
{
    for(int i=0;i<length-1;i++)
    {
        int* left=arr+i;
        int* key=arr+i+1;
        int temp=*key;
        int counter=0;
        while(key-counter>arr && *key <*(left-counter))
            counter++;
        shift_element(key-counter,counter);
        *(key-counter)=temp;
    }
}
