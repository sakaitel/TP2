#include "senhas.h"
#include <stdio.h>

int gerar_senha(char *saida, size_t tamanho) {
    if (saida == NULL || tamanho == 0) {
        return -1;
    }

    saida[0] = '\0';
    return 0;
}

int analisar_forca_senha(const char *senha, int *pontuacao) {
    if (senha == NULL || pontuacao == NULL) {
        return -1;
    }

    *pontuacao = 0;
    return 0;
}