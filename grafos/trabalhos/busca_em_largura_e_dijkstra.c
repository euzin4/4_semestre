#include <stdio.h>
#include <stdlib.h>

typedef struct _exeA{
    int matin[21][30];
    int matbl[4][21];
}exeA;

void inicia(exeA *exa){
    int l,c;

    for(l=0; l<21; l++){
        for(c=0; c<30; c++){
            //
        }
    }
}

int main()
{
    exeA *exa;

    exa = (exeA*) malloc(sizeof(exeA));

    inicia(exa);
}
