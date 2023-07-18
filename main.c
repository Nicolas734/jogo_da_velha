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
char verificarvencedor(void);



void main(){
    char end = ' ';
    montarmatrix();
    do{
        jogadadoplayer();
        end = verificarvencedor();
        if(end != ' ')break;
    } while (end == ' ');
    visualizarmatrix();
    if(end == 'X'){
        printf("Voce ganhou!\n");
    }else{
        printf("O computador ganhou\n");
    }
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
    visualizarmatrix();
    printf("\nDigite a posicao do X ");
    scanf("%d %d", &l, &c);
    l--; c--;
    int posicao = verificarescolha(c, l);
    if(posicao){
        matrix[c][l] = 'X';
        jogadadocomputador();
    }else{
        printf("Posição já ocupada\n");
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
    numero = rand() % 3;
    return numero;
}


void jogadadocomputador(void){
    srand(time(NULL));
    int coluna, linha;
    coluna = gerarNumeroAleatorio();
    linha = gerarNumeroAleatorio();
    int posicao = verificarescolha(linha, coluna);
    if(posicao){
        matrix[linha][coluna] = 'O';
    }else{
        jogadadocomputador();
    }
}


char verificarvencedor(void){
    int i;

    /* Verifica as linhas */
    for(i = 0; i < 3; i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]){
            return matrix[i][0];
        }
    }

    /* Verifica as colunas */
    for(i = 0; i < 3; i++){
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]){
            return matrix[0][i];
        }
    }

    /* Verifica as diagonais */
    if(matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]){
        return matrix[0][0];
    }

    if(matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]){
        return matrix[0][2];
    }

    return ' ';
}
