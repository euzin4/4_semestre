#include <stdio.h>
#include <stdlib.h>

typedef struct _matin{
    int incid[21][30];
}matin;
typedef struct _matbl{
    int bfs[4][21];
    int atualf, posf, finalf;
}matbl;
typedef struct _exeA{
    matin matin;
    matbl matbl;
}exeA;

void bfs_f(exeA *exa){
    int l,c, col = 20;
    char vert, pred, cor[10];

    while(1){
        if(exa->matbl.bfs[2][exa->matbl.atualf] == 2){ //condição de parada
            break;
        }
        for(c=0; c<30; c++){    //percorre as colunas
            if(exa->matin.incid[exa->matbl.atualf][c] == 1){
                for(l=0; l<21; l++){    //percorre as linhas
                    if(exa->matin.incid[l][c] == 1 && l != exa->matbl.atualf){
                        if(exa->matbl.bfs[2][l] != 1 && exa->matbl.bfs[2][l] != 2){ //ocorre se a cor for diferente de cinza ou preto
                            exa->matbl.bfs[3][exa->matbl.finalf] = l;   //adiciona a fila
                            exa->matbl.finalf++;
                            exa->matbl.bfs[0][l] = exa->matbl.bfs[0][exa->matbl.atualf]+1;  //distancia
                            exa->matbl.bfs[1][l] = exa->matbl.atualf;   //predecessor
                            exa->matbl.bfs[2][l] = 1;   //muda a cor para cinza
                        }
                    }
                }
            }
        }
        exa->matbl.bfs[2][exa->matbl.atualf] = 2;   //vertice atual fica preto
        vert = nomes(exa->matbl.atualf);
        pred = nomes(exa->matbl.bfs[1][exa->matbl.atualf]);
        if(exa->matbl.bfs[2][exa->matbl.atualf] == -1)
            strcpy(cor, "branco");
        if(exa->matbl.bfs[2][exa->matbl.atualf] == 1)
            strcpy(cor, "cinza");
        if(exa->matbl.bfs[2][exa->matbl.atualf] == 2)
            strcpy(cor, "preto");
        printf("vert: %c    dist: %d    pred: %c    cor: %s\n", vert, exa->matbl.bfs[0][exa->matbl.atualf], pred, cor);
        exa->matbl.posf++;
        exa->matbl.atualf = exa->matbl.bfs[3][exa->matbl.posf]; //proxima posição da fila vira o vertice atual
    }
    //---------------------caminho mais curto da A a Z
    printf("\nCaminho mais curto: ");
    while(col != -1){
        vert = nomes(col);
        if(col == 0){
           printf("%c ", vert);
        }else{
            printf("%c <- ", vert);
        }
        col = exa->matbl.bfs[1][col];
    }
    printf("\n\n");
    menu(exa);
}
int nomes(int atu){
    char vert;

    switch(atu){
        case -1:
            vert = '/';
            break;
        case 0:
            vert = 'A';
            break;
        case 1:
            vert = 'B';
            break;
        case 2:
            vert = 'C';
            break;
        case 3:
            vert = 'D';
            break;
        case 4:
            vert = 'E';
            break;
        case 5:
            vert = 'F';
            break;
        case 6:
            vert = 'G';
            break;
        case 7:
            vert = 'H';
            break;
        case 8:
            vert = 'I';
            break;
        case 9:
            vert = 'J';
            break;
        case 10:
            vert = 'K';
            break;
        case 11:
            vert = 'L';
            break;
        case 12:
            vert = 'M';
            break;
        case 13:
            vert = 'N';
            break;
        case 14:
            vert = 'O';
            break;
        case 15:
            vert = 'P';
            break;
        case 16:
            vert = 'Q';
            break;
        case 17:
            vert = 'R';
            break;
        case 18:
            vert = 'S';
            break;
        case 19:
            vert = 'T';
            break;
        case 20:
            vert = 'Z';
            break;
        default:
            break;
    }
    return vert;
}
void inicia(exeA *exa){
    int l,c;

    //-----------------mariz de incidencia
    for(l=0; l<21; l++){
        for(c=0; c<30; c++){
            exa->matin.incid[l][c] = 0;
            if(l==0 && c==0 || l==0 && c==1 || l==1 && c==0 || l==1 && c==2 || l==1 && c==3 || l==2 && c==2 || l==2 && c==4 || l==3 && c==3 || l==3 && c==5 || l==3 && c==6 || l==4 && c==4 || l==4 && c==5 || l==4 && c==7 || l==4 && c==8 || l==5 && c==7 || l==5 && c==9 || l==6 && c==8 || l==6 && c==10 || l==7 && c==9 || l==7 && c==11 || l==7 && c==12 || l==8 && c==10 || l==8 && c==11 || l==8 && c==13 || l==9 && c==12 || l==9 && c==13 || l==9 && c==14 || l==10 && c==1 || l==10 && c==15 || l==10 && c==16 || l==10 && c==17 || l==11 && c==6 || l==11 && c==15 || l==11 && c==18 || l==12 && c==16 || l==12 && c==19 || l==13 && c==17 || l==13 && c==20 || l==14 && c==18 || l==14 && c==19 || l==14 && c==20 || l==14 && c==21 || l==14 && c==22 || l==15 && c==21 || l==15 && c==23 || l==16 && c==23 || l==16 && c==24 || l==16 && c==25 || l==16 && c==26 || l==17 && c==22 || l==17 && c==24 || l==18 && c==25 || l==18 && c==27 || l==18 && c==28 || l==19 && c==26 || l==19 && c==27 || l==19 && c==29 || l==20 && c==14 || l==20 && c==28 || l==20 && c==29)
            {
                exa->matin.incid[l][c] = 1;
            }
        }
    }
    //-----------------matriz de busca em largura----(dist/ant/cor/fila)
    for(l=0; l<4; l++){
        for(c=0; c<21; c++){
            exa->matbl.bfs[l][c] = -1;
        }
    }
    exa->matbl.atualf = 0;  //vertice atual
    exa->matbl.posf = 0;    //posição atual da fila
    exa->matbl.finalf = 1;
    exa->matbl.bfs[0][0] = 0;   //distancia
    exa->matbl.bfs[2][0] = 1;   //cor 'cinza'
    exa->matbl.bfs[3][0] = 0;   //fila
}
void menu(exeA *exa){
    int opc;

    printf("MENU\n");
    printf("1-BFS\n");
    printf("2-Dijkstra\n");
    printf("0-sair\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            bfs_f(exa);
            break;
        case 2:
            //dijkstra_f(exa);
            break;
        case 0:
            printf("\nAte logo!\n");
            break;
        default:
        system("cls");
        printf("Valor invalido!\n\n");
        aux(exa);
    }
}
void aux(exeA *exa){
    menu(exa);
}

int main()
{
    exeA *exa;

    exa = (exeA*) malloc(sizeof(exeA));

    inicia(exa);
    menu(exa);
}
