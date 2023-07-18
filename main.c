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
int matrizCompleta(void);
void verificarempate(void);


void main(){
    char end = ' ';
    srand((unsigned int)time(NULL));
    montarmatrix();
    do{
        verificarempate();
        jogadadoplayer();
        verificarempate();
        jogadadocomputador();
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
    int posicao = verificarescolha(l, c); // Ordem dos argumentos invertida aqui
    if(posicao){
        matrix[l][c] = 'X';
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
    int numero = rand() % 3;
    return numero;
}


void jogadadocomputador(void){
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


int matrizCompleta(void) {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            if (matrix[l][c] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}


void verificarempate(void){
    if (matrizCompleta()) {
        printf("A matriz esta completa. O jogo empatou.\n");
        visualizarmatrix();
        exit(0);
    }
}