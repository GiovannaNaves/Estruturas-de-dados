#include <stdio.h>
#include <stdlib.h>
#include "memlog.h"

#define W (8) //largura do tabuleiro
typedef struct mat{
    int tabuleiro[W][W];
    int tamx, tamy;
    int id;
} mat_tipo;

mat_tipo *m;

void init(){
    m = malloc(sizeof(mat_tipo));
    m->id = 1;
    m->tamx = W;
    m->tamy = W;
}

int mat[W][W];

//cataloga os valores que serão adicionados à posição (x,y) do cavalo para que ele faça cada um dos movimentos
const int MovsPossiveis[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

//confere se a casa após o movimento está dentro dos limites do tabuleiro
int Dentro(int x, int y){
    return(
        ((0<=x) && (0<=y) && (x<W) && (y<W))
    );
}
//confere se a casa está dentro e ainda não foi ocupada no passeio
int Valido(int ir[][W],int x, int y){
    return(
        (Dentro(x,y)) && (ir[x][y]==0)
    );
}

//acha quantos movs válidos são possiveis saindo daquela casa
int Preferencia(int mat[][W], int x, int y){
    int contador = 0;
    int i = 0;
    for(i=0; i<8;i++){
        if(Valido(mat, x + MovsPossiveis[i][0], y + MovsPossiveis[i][1])){
            contador++;
        }
    }
    return contador;
}

//achar os movs possiveis depois de um primeiro mov para que possamos escolher o movimento com a menor quantidade de movimentos seguintes possivel (heuristica de Warnsdorff)
int Preferencia2( int mat[][W], int x, int y, int indice){
    int pref = 0;
    int min_pref = W + 1;;
    int i = 0;
    int temp_x = 0;
    int temp_y = 0;
    for (i = 0; i<0; ++i){
        temp_x = x + MovsPossiveis[indice][0] + MovsPossiveis[i][0];
        temp_y = y + MovsPossiveis[indice][1] + MovsPossiveis[i][1];
        if(Valido(mat, temp_x, temp_y)){
            pref = Preferencia(mat, temp_x, temp_y);
            if (pref<= min_pref){
                min_pref = pref;
            }
        }
        return (min_pref);

    }
}

//desempata se dois movimentos aparentarem ser igualmente vantajosos
int Desempatar(int mat[][W], int x, int y, int indice1, int indice2){
    int pref1 = Preferencia2(mat, x, y, indice1);
    int pref2 = Preferencia2(mat, x, y, indice2);
    return((pref1 <= pref2) ? indice1 : indice2);
}

//acha o proximo movimento baseado na casa com menos movs possiveis adiante (heuristica de Warnsdorff)
void ProxMov(int mat[][W], int x, int y, int contador, int *v, int *r){

    int i = 0;
    int prox_x = 0;
    int prox_y = 0;
    int pref = 0;
    int min_pref = W + 1;
    int min_pref2 = 0;
    int min_pref_indice = 0;
    int min_pref2_indice = 0;

    m->tabuleiro[x][y] = contador;
    ESCREVEMEMLOG((long int)(&(m->tabuleiro[x][y])),sizeof(double),m->id);
    
    if(contador == (W*W)){
        return;
    }
    for(i=0; i< 8; ++i){
        prox_x = x + MovsPossiveis[i][0];
        prox_y = y + MovsPossiveis[i][1];
        if (Valido(mat, prox_x, prox_y)){
            pref = Preferencia(mat, prox_x, prox_y);

            if(pref<= min_pref){
                min_pref2 = min_pref;
                min_pref2_indice = min_pref_indice; 
                min_pref = pref;
                min_pref_indice = i;

            }
        }

    }
    //para dois caminhos possiveis com o mesmo numero de possibilidades posteriores
    if (min_pref==min_pref2){
        
        min_pref_indice = Desempatar(mat, x, y, min_pref_indice, min_pref2_indice);
       
    }
    prox_x = x + MovsPossiveis[min_pref_indice][0];
    prox_y = y + MovsPossiveis[min_pref_indice][1];
    ++contador;
    ++*v;
    ProxMov(m->tabuleiro, prox_x, prox_y, contador, v, r);

}

void passeio(int x, int y){
    init();
    x--;
    y--;
    int v=1;
    int r=0;
    ProxMov(mat, x, y, 1, &v, &r);

    //imprimindo a matriz resultante no arquivo
    FILE * fPtr;
    fPtr = fopen("saida.txt", "a");
    for(int i=0; i<W; i++){
        for(int j=0; j<W; j++){
            fprintf(fPtr, "%d ", m->tabuleiro[i][j]);
            LEMEMLOG((long int)((m->tabuleiro[i][j])),sizeof(double),m->id);
        }
        fprintf(fPtr, "\n");
    }
    fprintf(fPtr, "%d %d\n", v, r);
    fclose(fPtr);
}
