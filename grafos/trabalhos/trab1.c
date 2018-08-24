#include <stdio.h>
#include <stdlib.h>

typedef struct _matrizes{
    int mat1a[5][5];
    float mat1i[5][8];
}matriz;

void matriz1a(matriz *matr){
    int l=0, c=0, aux, val=99, cont, dist=0;

    system("cls");
    printf("tabela 1 (adjacencia)\n");
    for(cont=0; cont<5; cont++){    //numero de vertices caminhadas
        for(c=0;c<5;c++){   //percorre as colunas para achar o menor valor de aresta
            if(matr->mat1a[l][c] < val && matr->mat1a[l][c] != 0){
                val = matr->mat1a[l][c];
                aux = c;
            }
            if(c == 4){ //entra neste caso quando achou o menor valor de aresta
                if(cont < 4){
                    dist = dist + val;  //o valor da aresta é somada a distancia
                }
                if(cont == 4){  //caso usado para exibir o ultimo vertice sem erros
                    printf("(%d)", l+1);
                }else{  //caso usado para exibir os outros vertices e o valor da aresta usada
                    printf("(%d)-%d-", l+1, val);
                    l=aux;
                }
            }
        }
        val=99;
    }
    printf("\ndistancia: %d\n\n", dist);
    menu(matr);
}
void matriz1i(matriz *matr){
    int l=0 , c, cont, val=99, auxc, auxl, auxl1, dist=0;

    system("cls");
    printf("tabela 1 (incidencia)\n");
    for(cont=0; cont<5; cont++){    //numero de vertices caminhadas
        for(c=0; c<8; c++){
            if(matr->mat1i[l][c] < val && matr->mat1i[l][c] > 0){//procura a aresta com menor valor sendo ele maior que zero
                val = matr->mat1i[l][c];
                auxc = c;   //salva a coluna do menor valor de aresta
                auxl1 = l;  //salva a linha da mesma aresta
            }
            if(c == 7){
                if(cont < 4){
                    dist = dist + val;
                }
                if(cont == 4){
                    printf("(%d)", l+1);
                }else{
                    printf("(%d)-%d-", l+1, val);
                }
            }
        }
        for(auxl=0; auxl<5 ; auxl++){   //procura na coluna o vertice que recebe a aresta
            if(matr->mat1i[auxl][auxc] != 0 && auxl1 != auxl){  //se o valor for diferente de zero e não estiver na linha do vertice de origem
                l = auxl;
            }
        }
        val=99;
    }
    printf("\ndistancia: %d\n\n", dist);
    menu(matr);
}
void menu(matriz *matr){
    int opc;

    printf("MENU\n");
    printf("1-matriz 1 (adjacencia)\n");
    printf("2-matriz 1 (incidencia)\n");
    printf("3-matriz 2 (adjacencia)\n");
    printf("4-matriz 2 (incidencia)\n");
    printf("0-sair\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            matriz1a(matr);
            break;
        case 2:
            matriz1i(matr);
            break;
        case 0:
            printf("\nAte logo!\n");
            break;
        default:
        system("cls");
        printf("Valor invalido!\n\n");
        aux(matr);
    }
}
void aux(matriz *matr){
    menu(matr);
}
void inicia(matriz *matr){
    int l, c;
    //--matr1a
    for(l=0;l<5;l++){
        for(c=0;c<5;c++){
            matr->mat1a[l][c]=0;
        }
    }
    matr->mat1a[0][1]=30;
    matr->mat1a[0][4]=20;
    matr->mat1a[1][3]=50;
    matr->mat1a[2][0]=15;
    matr->mat1a[2][1]=10;
    matr->mat1a[2][3]=5;
    matr->mat1a[3][1]=50;
    matr->mat1a[4][2]=10;
    matr->mat1a[4][3]=30;
    //--matr1i
    for(l=0; l<5; l++){
        for(c=0; c<8; c++){
            matr->mat1i[l][c]=0;
        }
    }
    matr->mat1i[0][0]=20;
    matr->mat1i[0][1]=-15;
    matr->mat1i[0][2]=30;
    matr->mat1i[1][2]=-30;
    matr->mat1i[1][4]=-10;
    matr->mat1i[1][7]=50;
    matr->mat1i[2][1]=15;
    matr->mat1i[2][3]=-10;
    matr->mat1i[2][4]=10;
    matr->mat1i[2][6]=5;
    matr->mat1i[3][5]=-30;
    matr->mat1i[3][6]=-5;
    matr->mat1i[3][7]=50;
    matr->mat1i[4][0]=-20;
    matr->mat1i[4][3]=10;
    matr->mat1i[4][5]=30;
}
int main(){
    matriz *matr;

    matr=(matriz*)malloc(sizeof(matriz));
    inicia(matr);
    menu(matr);
}
