#include <stdio.h>
#include "txtfind.h"


#define WORD 30



int main()
{
    char theWord[WORD];
    char op;
    scanf("%s",theWord);
    scanf(" %c",&op);
   
    if(op=='a')
    {
        print_lines(theWord);
    }
    if(op=='b')
    {
        print_word(theWord);
    }
    return 0;
}
