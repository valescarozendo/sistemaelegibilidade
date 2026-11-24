#include <stdio.h>
#include "elegibilidade.h"

typedef struct {
    const char *descricao;
    int idade;
    int ensino_medio;
    int esperado;
} CasoTeste;

int main(void)
{
    const CasoTeste casos[] = {
        {"Idade exata (18) com ensino medio", 18, 1, 1},
        {"Acima da idade minima com ensino medio", 19, 1, 1},
        {"Idoso com ensino medio", 120, 1, 1},
        {"Um ano abaixo do limite (17) com ensino medio", 17, 1, 0},
        {"Idade exata sem ensino medio", 18, 0, 0},
        {"Maior de idade sem ensino medio", 45, 0, 0},
        {"Menor de idade sem ensino medio", 17, 0, 0},
        {"Crianca com ensino medio (valor extremo)", 0, 1, 0},
        {"Idade zero sem ensino medio", 0, 0, 0},
        {"Flag diferente de 1 e tratada como nao", 30, 2, 0},
        {"Flag negativa e tratada como nao", 30, -1, 0}
    };

    const int total = (int)(sizeof(casos) / sizeof(casos[0]));
    int falhas = 0;

    if (IDADE_MINIMA != 18) {
        printf("[FALHA] IDADE_MINIMA deveria ser 18, mas e %d\n", IDADE_MINIMA);
        falhas++;
    } else {
        printf("[OK]    IDADE_MINIMA == 18\n");
    }

    for (int i = 0; i < total; i++) {
        int obtido = candidato_apto(casos[i].idade, casos[i].ensino_medio);
        if (obtido == casos[i].esperado) {
            printf("[OK]    %s\n", casos[i].descricao);
        } else {
            printf("[FALHA] %s (idade=%d, ensino=%d, esperado=%d, obtido=%d)\n",
                   casos[i].descricao, casos[i].idade, casos[i].ensino_medio,
                   casos[i].esperado, obtido);
            falhas++;
        }
    }

    printf("\nTotal: %d testes | Falhas: %d\n", total + 1, falhas);
    return falhas == 0 ? 0 : 1;
}