#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

int main() {

    // Tabuleiro principal
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // Matrizes das habilidades
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int i, j;

    // =========================
    // Posicionamento de navios
    // =========================

    // Navio horizontal
    for(i = 2; i <= 4; i++) {
        tabuleiro[1][i] = 3;
    }

    // Navio vertical
    for(i = 4; i <= 6; i++) {
        tabuleiro[i][7] = 3;
    }

    // =========================
    // HABILIDADE CONE
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            int centro = TAM_HAB / 2;

            if(j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }
        }
    }

    // =========================
    // HABILIDADE CRUZ
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            if(i == TAM_HAB/2 || j == TAM_HAB/2) {
                cruz[i][j] = 1;
            }
        }
    }

    // =========================
    // HABILIDADE OCTAEDRO
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            int centro = TAM_HAB / 2;

            if((i - centro >= 0 ? i - centro : centro - i) +
               (j - centro >= 0 ? j - centro : centro - j)
               <= centro) {

                octaedro[i][j] = 1;
            }
        }
    }

    // =========================
    // Pontos de origem
    // =========================

    int origemConeL = 2;
    int origemConeC = 2;

    int origemCruzL = 6;
    int origemCruzC = 3;

    int origemOctL = 6;
    int origemOctC = 7;

    // =========================
    // Sobreposição do CONE
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            int linha = origemConeL + i - TAM_HAB/2;
            int coluna = origemConeC + j - TAM_HAB/2;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB &&
               cone[i][j] == 1 &&
               tabuleiro[linha][coluna] == 0) {

                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =========================
    // Sobreposição da CRUZ
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            int linha = origemCruzL + i - TAM_HAB/2;
            int coluna = origemCruzC + j - TAM_HAB/2;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB &&
               cruz[i][j] == 1 &&
               tabuleiro[linha][coluna] == 0) {

                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =========================
    // Sobreposição do OCTAEDRO
    // =========================
    for(i = 0; i < TAM_HAB; i++) {
        for(j = 0; j < TAM_HAB; j++) {

            int linha = origemOctL + i - TAM_HAB/2;
            int coluna = origemOctC + j - TAM_HAB/2;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB &&
               octaedro[i][j] == 1 &&
               tabuleiro[linha][coluna] == 0) {

                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =========================
    // Exibição do tabuleiro
    // =========================

    printf("\nTABULEIRO:\n\n");

    for(i = 0; i < TAM_TAB; i++) {

        for(j = 0; j < TAM_TAB; j++) {

            if(tabuleiro[i][j] == 0)
                printf("~ ");

            else if(tabuleiro[i][j] == 3)
                printf("N ");

            else if(tabuleiro[i][j] == 5)
                printf("* ");
        }

        printf("\n");
    }

    return 0;
}