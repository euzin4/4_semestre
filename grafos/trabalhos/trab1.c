#include <stdio.h>
#include <stdlib.h>

typedef struct _matrizes{
    int mat1a[4][4];
    float mat1i[4][7];
}matriz;

void matriz1a(matriz *matr){
    int l=0, c=0, aux=99, val=99, cont=0, dist=0;

    system("cls");
    printf("\n");
    while(cont < 5){
        for(c=0;c<5;c++){
            if(matr->mat1a[l][c] < val && matr->mat1a[l][c] != 0){
                val = matr->mat1a[l][c];
                aux = c;
            }
            if(c == 4){
                if(cont < 4){
                    dist = dist + val;
                }
                if(cont == 4){
                    printf("(%d)", l+1);
                }else{
                    printf("(%d)-%d-", l+1, val);
                    l=aux;
                }
            }
        }
        cont++;
        val = 99;
    }
    printf("\ndistancia: %d\n\n", dist);
    menu(matr);
}
void matriz1i{

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
            //matriz1i(matr);
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
}
int main(){
    matriz *matr;

    matr=(matriz*)malloc(sizeof(matriz));
    inicia(matr);
    menu(matr);
}
