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
    int l, l1, c, c0, c1, c2, contg, vert, mag, list;
    int cor = 1, ts = 0;

    //------------------------------------------------------------------------------organização por grau de vertice
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
    //------------------------------------------------------------------------------
    for(c0=0; c0<11; c0++){//===
    for(c=0; c<11; c++){    //passa pelas colunas da matriz 'wel'
        if(wel[2][c] == 0){ //se encontrar vertice sem cor
            l = wel[0][c];  //pega o numero do vertice
            for(c1=0; c1<16; c1++){ //percorre as colunas do vertice sem cor
                if(incid[l][c1] == 1){  //encontra as arestas do vertice
                    for(l1=0; l1<11; l1++){ //procura a outra extremidade da aresta
                        if(l != l1 && incid[l1][c1] == 1){ //encontra a outra extremidade da aresta
                            for(c2=0; c2<11; c2++){  //percorre 'wel'
                                if(wel[0][c2] == l1){   //encontra o outro vertice
                                    if(cor == wel[2][c2]){ //se tem a mesma cor que a cor atual
                                        ts = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(ts == 0){    //se não encontrar problemas
                wel[2][c] = cor;
            }else{
                ts = 0;
            }
        }
    }
    cor++;
    }//====
    printf("GRAU | VERTICE | COR\n");
    for(list=0; list<11; list++){
        printf("  %d       %d       %d\n", wel[1][list], wel[0][list], wel[2][list]);
    }
}
