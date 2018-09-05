#include <stdio.h>
#include <stdlib.h>

typedef struct _celula{
    char novoc;
    int estado;
    int posicao;
}celula;

int main()
{
    celula matriz[8][4];
    char val[50];
    int car, cont, l, c;

    //inicia matriz
    for(l=0; l<8; l++){ //zera a matriz
        for(c=0; c<4; c++){
            matriz[l][c].novoc = 'X';
            matriz[l][c].estado = -9;
            matriz[l][c].posicao = -9;
        }
    }
    matriz[0][0].novoc = '>'; matriz[0][0].estado = 0; matriz[0][0].posicao = 1;
    matriz[0][1].novoc = '>'; matriz[0][1].estado = 2; matriz[0][1].posicao = 1;
    matriz[0][2].novoc = '>'; matriz[0][2].estado = 1; matriz[0][2].posicao = 1;
    matriz[0][3].novoc = 'U'; matriz[0][3].estado = 6; matriz[0][3].posicao = 0;
    matriz[1][1].novoc = '0'; matriz[1][1].estado = 1; matriz[1][1].posicao = 1;
    matriz[1][2].novoc = '1'; matriz[1][2].estado = 1; matriz[1][2].posicao = 1;
    matriz[1][3].novoc = 'U'; matriz[1][3].estado = 3; matriz[1][3].posicao = -1;
    matriz[2][1].novoc = '0'; matriz[2][1].estado = 2; matriz[2][1].posicao = 1;
    matriz[2][2].novoc = '1'; matriz[2][2].estado = 2; matriz[2][2].posicao = 1;
    matriz[2][3].novoc = 'U'; matriz[2][3].estado = 4; matriz[2][3].posicao = -1;
    matriz[3][0].novoc = '>'; matriz[3][0].estado = 6; matriz[3][0].posicao = 0;
    matriz[3][1].novoc = '0'; matriz[3][1].estado = 7; matriz[3][1].posicao = 0;
    matriz[3][2].novoc = 'U'; matriz[3][2].estado = 5; matriz[3][2].posicao = -1;
    matriz[4][0].novoc = '>'; matriz[4][0].estado = 6; matriz[4][0].posicao = 0;
    matriz[4][1].novoc = 'U'; matriz[4][1].estado = 5; matriz[4][1].posicao = -1;
    matriz[4][2].novoc = '1'; matriz[4][2].estado = 7; matriz[4][2].posicao = 0;
    matriz[5][0].novoc = '>'; matriz[5][0].estado = 0; matriz[5][0].posicao = 1;
    matriz[5][1].novoc = '0'; matriz[5][1].estado = 5; matriz[5][1].posicao = -1;
    matriz[5][2].novoc = '1'; matriz[5][2].estado = 5; matriz[5][2].posicao = -1;

    printf("valor:");
    fgets(val, 49, stdin);
    car = strlen(val);    //quantidade de caracteres escritos
    cont = car;
    //adição do 'U'
    val[cont+1] = val[cont-1];
    val[cont-1] = 'U';
    cont++;
    //adição do '>'
    while(1){
        val[cont] = val[cont-1];
        cont--;
        if(cont == 0){
            val[0] = '>';
            break;
        }
    }
    //----
    printf("%s \n",val);
    printf("%d caracteres\n",car-1);
}
