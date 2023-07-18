#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char matrix[3][3];
char end = ' ';

void montar_matrix(void);
void visualizar_matrix(void);
void jogada_do_player(void);
void jogada_do_computador(void);
void verificar_empate(void);
int verificar_escolha(int coluna, int linha);
int gerar_numero_aleatorio(void);
int matriz_completa(void);
char verificar_vencedor(void);


void main(){
    srand((unsigned int)time(NULL));
    montar_matrix();
    do{
        jogada_do_player();
        jogada_do_computador();
        if(end != ' ')break;
    } while (end == ' ');
    visualizar_matrix();
    if(end == 'X'){
        printf("Voce ganhou!\n");
    }else{
        printf("O computador ganhou\n");
    }
}


void montar_matrix(void){
    int l, c;
    for(c=0; c<3; c++){
        for(l=0; l<3; l++){
            matrix[l][c] = ' ';
        }
    }
}


void visualizar_matrix(void){
    for(int i=0; i<3; i++){
        printf(" %c | %c | %c \n", matrix[0][i], matrix[1][i], matrix[2][i]);
    }
}


void jogada_do_player(void){
    int l, c;
    end = verificar_vencedor();
    if(end != ' '){
        return;
    }
    visualizar_matrix();
    printf("\nDigite a posicao do X ");
    scanf("%d %d", &l, &c);
    l--; c--;
    int posicao = verificar_escolha(l, c); // Ordem dos argumentos invertida aqui
    if(posicao){
        matrix[l][c] = 'X';
    }else{
        printf("Posição já ocupada\n");
        jogada_do_player();
    }
}

int verificar_escolha(int coluna, int linha){
    if(matrix[coluna][linha] == ' '){
        return 1;
    }else{
        return 0;
    }
}


int gerar_numero_aleatorio(void) {
    int numero = rand() % 3;
    return numero;
}


void jogada_do_computador(void){
    end = verificar_vencedor();
    if(end != ' '){
        return;
    }
    int coluna, linha;
    coluna = gerar_numero_aleatorio();
    linha = gerar_numero_aleatorio();
    int posicao = verificar_escolha(linha, coluna);
    if(posicao){
        matrix[linha][coluna] = 'O';
    }else{
        jogada_do_computador();
    }
}


char verificar_vencedor(void){
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

    verificar_empate();

    return ' ';
}


int matriz_completa(void) {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            if (matrix[l][c] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}


void verificar_empate(void){
    if (matriz_completa()) {
        printf("A matriz esta completa. O jogo empatou.\n");
        visualizar_matrix();
        exit(0);
    }
}