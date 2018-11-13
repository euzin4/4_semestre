#include <stdio.h>
#include <stdlib.h>
//welsh powel - T4

int main(){            //ah ab bd cd di dk ek ef fg gh gk hi hj hk ij jk
    int incid[11][16]={ { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //a(0)
                        { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //b(1)
                        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //c(2)
                        { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //d(3)
                        { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},    //e(4)
                        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},    //f(5)
                        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},    //g(6)
                        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0},    //h(7)
                        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},    //i(8)
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},    //j(9)
                        { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1}};   //k(10)

    int wel[3][11]={    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},   //vertice
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //grau
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};  //cor

    int grau[2][11];
    int l, c, c1, contg, vert, mag;

    for(l=0; l< 11; l++){   //contagem do grau dos vértices
        contg = 0;
        for(c=0; c<16; c++){
            if(incid[l][c] == 1){
                contg++;
            }
            vert = l;
        }
        grau[0][l] = contg; //grau do vertice
        grau[1][l] = vert;  //vertice
    }
    for(c1=0; c1<11; c1++){    //passa em todos os vertices
        mag = grau[0][c1];
        for(c=0; c<11; c++){    //procura o maior grau
            if(grau[0][c] > mag){
                mag = grau[0][c];
                vert = grau[1][c];
            }
        }
        grau[0][vert] = 0;  //zera o maior grau encontrado para não repetir o mesmo vertice
        wel[0][c1] = vert;  //tabela wel recebe o vertice encontrado
        wel[1][c1] = mag;   //tabela wel recebe o grau encontrado
    }
    
}
