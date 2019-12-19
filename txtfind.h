#ifndef _TXTFIND
#define _TXTFIND
#define WORD 30
#define LINE 256
extern char theWord[WORD];
extern char theLine[LINE];


int substringa(char*,char*);
int substringb(char*,char*);
void print_word(char *str);
void print_lines(char *str);

#endif
