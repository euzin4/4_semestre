#include <stdio.h>
#include <stdlib.h>

typedef struct _exeA{
    int matin[21][30];
    int matbl[4][21];
}exeA;

void inicia(exeA *exa){
    int l,c;

    //-----------------mariz de incidencia
    for(l=0; l<21; l++){
        for(c=0; c<30; c++){
            exa->matin[l][c] = 0;
            if(l==0 && c==0 || l==0 && c==1 || l==1 && c==0 || l==1 && c==2 || l==1 && c==3 || l==2 && c==2 || l==2 && c==4 || l==3 && c==3 || l==3 && c==5 || l==3 && c==6 || l==4 && c==4 || l==4 && c==5 || l==4 && c==7 || l==4 && c==8 || l==5 && c==7 || l==5 && c==9 || l==6 && c==8 || l==6 && c==10 || l==7 && c==9 || l==7 && c==11 || l==7 && c==12 || l==8 && c==10 || l==8 && c==11 || l==8 && c==13 || l==9 && c==12 || l==9 && c==13 || l==9 && c==14 || l==10 && c==1 || l==10 && c==15 || l==10 && c==16 || l==10 && c==17 || l==11 && c==6 || l==11 && c==15 || l==11 && c==18 || l==12 && c==16 || l==12 && c==19 || l==13 && c==17 || l==13 && c==20 || l==14 && c==18 || l==14 && c==19 || l==14 && c==20 || l==14 && c==21 || l==14 && c==22 || l==15 && c==21 || l==15 && c==23 || l==16 && c==23 || l==16 && c==24 || l==17 && c==22 || l==17 && c==24 || l==18 && c==25 || l==18 && c==27 || l==18 && c==28 || l==19 && c==26 || l==19 && c==27 || l==19 && c==29 || l==20 && c==14 || l==20 && c==28 || l==20 && c==29)
            {
                exa->matin[l][c] = 1;
            }
        }
    }
    //-----------------matriz de busca em largura----(dist/pi/cor/fila)
    for(l=0; l<4; l++){
        for(c=0; c<21; c++){
            exa->matbl[l][c] = -1;
        }
    }
    exa->matbl[0][0] = 0;
    exa->matbl[2][0] = 1;
    exa->matbl[3][0] = 0;
}

int main()
{
    exeA *exa;

    exa = (exeA*) malloc(sizeof(exeA));

    inicia(exa);
    menu(exa);
}
