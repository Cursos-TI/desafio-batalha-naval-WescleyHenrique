#include <stdio.h>
#include <string.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    char Batalha [LINHA][COLUNA];

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            Batalha [i][j] = '0';

        }
        
    }

    //Navios 'N' adicionados na vertical
    Batalha[7][0] = 'N';
    Batalha[8][0] = 'N';
    Batalha[9][0] = 'N';

    //Navios 'N' adicionados na horizontal
    Batalha[4][3] = 'N';
    Batalha[4][4] = 'N';
    Batalha[4][5] = 'N';

    // Navio 'N' adicionado na diagonal 
    Batalha[6][6] = 'N';
    Batalha[7][7] = 'N';
    Batalha[8][8] = 'N';
    // Navio 'N' adicionado na diagonal 
    Batalha[1][3] = 'N';
    Batalha[2][4] = 'N';
    Batalha[3][5] = 'N';

    //Para visualizar o tabuleiro e confirmar o posicionamento
    printf("TABULEIRO DE BATALHA NAVAL:\n");
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            printf("%c ", Batalha[y][x]);
        }
        printf("\n"); // Quebra de linha para a próxima linha do tabuleiro
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
