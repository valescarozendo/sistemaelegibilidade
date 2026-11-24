#include <stdio.h>
#include "elegibilidade.h"

static void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int ler_inteiro(const char *mensagem, int *destino, int min, int max)
{
    int retorno;
    while (1) {
        printf("%s", mensagem);
        retorno = scanf("%d", destino);

        if (retorno == EOF) {
            printf("\nEntrada encerrada inesperadamente.\n");
            return 0;
        }

        if (retorno == 1 && *destino >= min && *destino <= max) {
            limpar_buffer();
            return 1;
        }

        printf("Entrada invalida! Digite um valor entre %d e %d.\n", min, max);
        limpar_buffer();
    }
}

int main(void)
{
    int idade;
    int ensino_medio;

    printf("=== SISTEMA DE ELEGIBILIDADE PARA CONCURSO ===\n\n");

    if (!ler_inteiro("Digite a idade do candidato (0 a 150): ", &idade, 0, 150)) {
        return 1;
    }

    if (!ler_inteiro("Possui ensino medio completo? (1-Sim / 0-Nao): ", &ensino_medio, 0, 1)) {
        return 1;
    }

    printf("\n--- RESULTADO DA AVALIACAO ---\n");
    if (candidato_apto(idade, ensino_medio)) {
        printf("Status: CANDIDATO APTO\n");
    } else {
        printf("Status: CANDIDATO INAPTO\n");
        printf("Motivo(s): ");
        if (idade < IDADE_MINIMA && ensino_medio != 1) {
            printf("Idade inferior a %d anos e Ensino Medio incompleto.\n", IDADE_MINIMA);
        } else if (idade < IDADE_MINIMA) {
            printf("Idade inferior a %d anos.\n", IDADE_MINIMA);
        } else {
            printf("Ensino Medio incompleto.\n");
        }
    }

    return 0;
}