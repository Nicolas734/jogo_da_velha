#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char matrix[3][3];

void montarmatrix(void);
void visualizarmatrix(void);
void jogadadoplayer(void);
void jogadadocomputador(void);
int verificarescolha(int coluna, int linha);
int gerarNumeroAleatorio(void);
void verificarlinha(void);
void verificarcoluna(void);



void main(){
    montarmatrix();
    visualizarmatrix();
    jogadadoplayer();
    visualizarmatrix();
    jogadadoplayer();
    visualizarmatrix();
    jogadadoplayer();
    verificarlinha();
}


void montarmatrix(void){
    int l, c;
    for(c=0; c<3; c++){
        for(l=0; l<3; l++){
            matrix[l][c] = ' ';
        }
    }
}


void visualizarmatrix(void){
    for(int i=0; i<3; i++){
        printf(" %c | %c | %c \n", matrix[0][i], matrix[1][i], matrix[2][i]);
    }
}

void jogadadoplayer(void){
    int l, c;
    printf("digite a posicao do X ");
    scanf("%d %d", &l, &c);
    l--; c--;
    int posicao = verificarescolha(c, l);
    if(posicao){
        matrix[c][l] = 'X';
    }else{
        printf("posição já ocupada\n");
        jogadadoplayer();
    }
}

int verificarescolha(int coluna, int linha){
    if(matrix[coluna][linha] == ' '){
        return 1;
    }else{
        return 0;
    }
}

int gerarNumeroAleatorio(void) {
    int numero = 0;
    numero = rand() % 4;
    return numero;
}

void jogadadocomputador(void){
    srand(time(NULL));
    int coluna, linha;
    coluna = gerarNumeroAleatorio();
    linha = gerarNumeroAleatorio();
    int posicao = verificarescolha(coluna, linha);
    if(posicao){
        matrix[coluna][linha] = 'O';
    }else{
        printf("posição ocupada\n");
        jogadadocomputador();
    }
}

void verificarlinha(void){
    int end = 0;
    for(int l = 0; l<3; l++){
        if(matrix[0][l] == matrix[1][l] && matrix[1][l] == matrix[2][l]){
            end = 1;
            break;
        }
    }
    if(end){
        printf("fim de jogo");
    }else{
        printf("ainda não");
    }
}