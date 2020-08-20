#ifndef NAME_ST_H_
#define NAME_ST_H_

#include<string.h>
#define SLEN 32
extern int status;

struct names_st {
    char first[SLEN];
    char last[SLEN];
};

typedef struct names_st names;

void get_names(names *);
void show_names(const names *);
char *s_gets(char *st,int n);

#ifdef MAVIS
    #include<stdlib.h>
#else
    #include<stdbool.h>
#endif

#endif // NAME_ST_H_INCLUDED
