#ifndef SENHAS_H
#define SENHAS_H

#include <stddef.h>

/**
 * Gera uma senha aleatoria forte com letras, numeros e simbolos.
 *
 * @param saida Ponteiro onde a senha gerada sera gravada.
 * @param tamanho Tamanho desejado da senha (incluindo o '\0').
 * @return 0 em caso de sucesso, ou -1 em caso de erro.
 */
int gerar_senha(char *saida, size_t tamanho);

/**
 * Analisa a complexidade de uma senha e atribui uma pontuacao de forca.
 *
 * @param senha String da senha a ser analisada.
 * @param pontuacao Ponteiro onde a pontuacao sera gravada.
 * @return 0 em caso de sucesso, ou -1 em caso de erro.
 */
int analisar_forca_senha(const char *senha, int *pontuacao);

#endif /* SENHAS_H */