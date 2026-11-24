#include "elegibilidade.h"

int candidato_apto(int idade, int ensino_medio_completo)
{
    if (idade >= IDADE_MINIMA && ensino_medio_completo == 1) {
        return 1;
    }
    return 0;
}