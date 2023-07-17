#include <stdio.h>

char matrix[3][3];

void montarmatrix(void);
void visualizarmatrix(void);
void jogadadoplayer(void);
int verificarescolha(int coluna, int linha);


void main(){
    montarmatrix();
    visualizarmatrix();
    jogadadoplayer();
    visualizarmatrix();
    jogadadoplayer();
    visualizarmatrix();
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