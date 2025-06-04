#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função abs

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade (ex: 5x5)

// Função para imprimir o tabuleiro
// Recebe o tabuleiro como parâmetro para imprimir seu estado atual
void imprimirTabuleiro(char tabuleiro[LINHA][COLUNA]) {
    for (int y = 0; y < LINHA; y++) {
        for (int x = 0; x < COLUNA; x++) {
            printf("%c ", tabuleiro[y][x]); // Imprime o caractere da posição
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }
}

// Função para aplicar uma habilidade ao tabuleiro
// habilidade_matriz: a matriz 0/1 que define a forma da habilidade
// origem_linha, origem_coluna: o ponto central da aplicação da habilidade no tabuleiro principal
// tabuleiro_principal: o tabuleiro onde a habilidade será aplicada
void aplicarHabilidade(int habilidade_matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origem_linha, int origem_coluna,
                       char tabuleiro_principal[LINHA][COLUNA]) {

    // Calcula o centro da matriz da habilidade para centralizar a aplicação
    int centro_habilidade = TAMANHO_HABILIDADE / 2;

    // Itera sobre cada célula da matriz da habilidade
    for (int h_linha = 0; h_linha < TAMANHO_HABILIDADE; h_linha++) {
        for (int h_coluna = 0; h_coluna < TAMANHO_HABILIDADE; h_coluna++) {
            // Se a posição na matriz da habilidade é '1' (parte da área de efeito)
            if (habilidade_matriz[h_linha][h_coluna] == 1) {
                // Calcula as coordenadas correspondentes no tabuleiro principal
                // Ajusta a posição da habilidade para que seu centro coincida com 'origem_linha' e 'origem_coluna'
                int t_linha = origem_linha + (h_linha - centro_habilidade);
                int t_coluna = origem_coluna + (h_coluna - centro_habilidade);

                // Verifica se as coordenadas calculadas estão dentro dos limites do tabuleiro principal
                if (t_linha >= 0 && t_linha < LINHA &&
                    t_coluna >= 0 && t_coluna < COLUNA) {
                    // Se a posição no tabuleiro não for um navio ('N'), marca como área afetada ('5')
                    // Isso evita sobrescrever navios com a marca de habilidade
                    if (tabuleiro_principal[t_linha][t_coluna] != 'N') {
                        tabuleiro_principal[t_linha][t_coluna] = '5';
                    }
                }
            }
        }
    }
}



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

    // --- CRIAÇÃO DAS MATRIZES DE HABILIDADE ---

    // MATRIZ DE HABILIDADE: CONE
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeCone[i][j] = 0; // Inicializa a matriz do cone
        }
    }

    int centro_cone_habilidade = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = centro_cone_habilidade - i; j <= centro_cone_habilidade + i; j++) {
            if (j >= 0 && j < TAMANHO_HABILIDADE) {
                habilidadeCone[i][j] = 1; // Preenche a área do cone
            }
        }
    }

    // MATRIZ DE HABILIDADE: CRUZ
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeCruz[i][j] = 0; // Inicializa a matriz da cruz com 0s
        }
    }
    int centro_cruz_habilidade = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        habilidadeCruz[centro_cruz_habilidade][i] = 1; // Linha central
        habilidadeCruz[i][centro_cruz_habilidade] = 1; // Coluna central
    }

    // MATRIZ DE HABILIDADE: OCTAEDRO (LOSANGO)
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeOctaedro[i][j] = 0; // Inicializa a matriz do octaedro com 0s
        }
    }
    int centro_octa_habilidade = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        int dist = abs(i - centro_octa_habilidade);
        for (int j = centro_octa_habilidade - (centro_octa_habilidade - dist); j <= centro_octa_habilidade + (centro_octa_habilidade - dist); j++) {
            if (j >= 0 && j < TAMANHO_HABILIDADE) {
                habilidadeOctaedro[i][j] = 1; // Preenche a área do octaedro
            }
        }
    }

     // --- APLICANDO HABILIDADES AO TABULEIRO ---

    // Ponto de origem para a Habilidade CONE (ex: linha 2, coluna 2)
    int origem_cone_linha = 2;
    int origem_cone_coluna = 2;
    aplicarHabilidade(habilidadeCone, origem_cone_linha, origem_cone_coluna, Batalha);
    printf("--- TABULEIRO COM HABILIDADE CONE (Origem: [%d,%d]) ---\n", origem_cone_linha, origem_cone_coluna);
    imprimirTabuleiro(Batalha);
    printf("\n");

    // Ponto de origem para a Habilidade CRUZ (ex linha 7, coluna 7)
    int origem_cruz_linha = 7;
    int origem_cruz_coluna = 7;
    aplicarHabilidade(habilidadeCruz, origem_cruz_linha, origem_cruz_coluna, Batalha);
    printf("--- TABULEIRO COM HABILIDADE CRUZ (Origem: [%d,%d]) ---\n", origem_cruz_linha, origem_cruz_coluna);
    imprimirTabuleiro(Batalha);
    printf("\n");

    // Ponto de origem para a Habilidade OCTAEDRO (ex: linha 5, coluna 0)
    int origem_octa_linha = 5;
    int origem_octa_coluna = 0;
    aplicarHabilidade(habilidadeOctaedro, origem_octa_linha, origem_octa_coluna, Batalha);
    printf("--- TABULEIRO COM HABILIDADE OCTAEDRO (Origem: [%d,%d]) ---\n", origem_octa_linha, origem_octa_coluna);
    imprimirTabuleiro(Batalha);
    printf("\n");
    
    

    return 0;
}
