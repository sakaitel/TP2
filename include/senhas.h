#ifndef SENHAS_H
#define SENHAS_H

#include <stddef.h>

/**
 * Gera uma senha aleatoria forte com letras, numeros e simbolos.
 *
 * @param senha Ponteiro onde a senha gerada sera gravada.
 * @param tamanho Tamanho desejado da senha (sem contar o '\0').
 * @return Ponteiro para a senha gerada, ou NULL em caso de erro.
 */
char* gerar_senha(char *senha, int tamanho);

/**
 * Analisa a complexidade de uma senha e atribui uma pontuacao de forca de 0 a 10.
 *
 * @param senha String da senha a ser analisada.
 * @return Pontuacao de 0 a 10 em caso de sucesso, ou -1 em caso de erro.
 */
int analisar_forca_senha(char *senha);

#endif /* SENHAS_H */