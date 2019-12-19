#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE 256
#define WORD 30

int substringa(char* str1 , char* str2)
{
    int i=0,j=0,lenstr2=0,lenstr1=0,count=0;
    while(*(str2+j)!='\0')
    {
        lenstr2++;
        j++;
    }
    while(*(str1+i)!='\0')
    {
        lenstr1++;
        i++;
    } 
    if(lenstr1<lenstr2)
    {
        return 0;
    }
    i=0,j=0;
    while(*(str1+i)!='\0')
    {
        if(*(str1+i)==*(str2+j))
        {
            while(*(str1+i)==*(str2+j) && *(str2+j)!='\0' && *(str1+i)!='\0')
            {
                count++;
                i++;
                j++;
            }
            if(lenstr2==count)
            {
                return 1;
            }
            count=0;
            j=0;
        }
        if(*(str1+i)=='\0')
        {
            return 0;
        }
        i++;
    }
    return 0;
}
int substringb(char* str1 , char* str2)
{
    int i=0,j=0,lenstr2=0,lenstr1=0,count=0;
    while(*(str2+j)!='\0')
    {
        lenstr2++;
        j++;
    }
    while(*(str1+i)!='\0')
    {
        lenstr1++;
        i++;
    }    
    if(lenstr1<=(lenstr2+1))
    {     
        i=0;j=0;
        while(*(str1+i)!='\0')
        {
            if(*(str1+i)==*(str2+j))
            {
                count++;
                j++;
            }
            i++;
        }
        if(lenstr2==count)
        {
            return 1;
        }
    }   
    return 0;
}
void print_word(char *str)
{
    char theWord[WORD]="";
    char theLine[LINE]="";
    int indexword=0;
    int indexcur=0;
    
    fgets(theLine,LINE,stdin);
    fgets(theLine,LINE,stdin);

    while(fgets(theLine,LINE,stdin))
    {
        indexcur=0;      
        while(theLine[indexcur]!='\n'&& theLine[indexcur]!='\0')
        {
            theWord[indexword++]+=theLine[indexcur];
            if((theLine[indexcur+1]==' ' || theLine[indexcur+1]=='\t')  || theLine[indexcur+1]=='\n' || theLine[indexcur+1]=='\0') //end word
            {

                indexcur++;
                if(substringb(theWord,str)) 
                {
                    printf("%s \n",theWord);
                }
                memset(theWord,0,sizeof(theWord)); // reset the string
                indexword=0;               
            }
            if(theLine[indexcur]!='\0')
                indexcur++;                  
            }
        }       
    }  


void print_lines(char *str)
{
    char theLine[LINE]="";
    char theWord[WORD]="";
    int indexword=0;
    int indexcur=0;
    int found=0;
    
    fgets(theLine,LINE,stdin);
    
    while(fgets(theLine,LINE,stdin))
    {
        found=0;
        indexword=0;
        indexcur=0;

        while(theLine[indexcur]!='\n'&& theLine[indexcur]!='\0' && !found)
        {
            theWord[indexword++]+=theLine[indexcur];
            if(theLine[indexcur+1]==' ' || theLine[indexcur+1]=='\t' || theLine[indexcur+1]=='\n' ||theLine[indexcur+1]=='\0')
            {
                indexcur++;
                if(substringa(theWord,str))
                {
                    printf("%s",theLine);
                    found=1;                    
                }
                memset(theWord,0,sizeof(theWord));
                indexword=0;
            }
            if(theLine[indexcur]!='\0')
            {
                indexcur++; 
            }
        }
    }   
}
