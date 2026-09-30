#ifndef BASES_H
#define BASES_H

#include <stddef.h>

/**
 * Converte uma cadeia de caracteres (texto) para a sua representacao em codigos ASCII decimais.
 *
 * @param senha String contendo o texto a ser convertido.
 */
void criptoTextoASCII(const char *senha);

/**
 * Converte uma sequencia de codigos ASCII numericos separados por espaco de volta para texto.
 *
 * @param senha String contendo os codigos ASCII decimais separados por espaco.
 */
void criptoASCIITexto(char *senha);

/**
 * Converte e imprime um numero inteiro decimal (base 10) em formato hexadecimal (base 16).
 *
 * @param senha Valor inteiro em base decimal a ser convertido.
 */
void b10b16(int senha);

/**
 * Converte uma string representativa de um valor hexadecimal (base 16) e imprime em decimal (base 10).
 *
 * @param senha String contendo o valor em hexadecimal.
 */
void b16b10(const char *senha);

/**
 * Converte e imprime um numero inteiro decimal (base 10) na sua representacao binaria (base 2).
 *
 * @param senha Valor inteiro em base decimal a ser convertido.
 */
void b10b2(int senha);

/**
 * Converte uma string de bits binarios (base 2) e imprime seu valor em decimal (base 10).
 *
 * @param senha String contendo a sequencia de 0s e 1s.
 */
void b2b10(const char *senha);

/**
 * Exibe o menu interativo de escolhas e processa a operacao de conversao solicitada.
 *
 * @param CriptoDescripto Ponteiro para armazenar a opcao de criptografar (1) ou descriptografar (2).
 * @param tmb Ponteiro para armazenar a base escolhida (1 - ASCII, 2 - Base 16, 3 - Base 2).
 */
void menu(int *CriptoDescripto, int *tmb);

/**
 * Funcao principal do modulo de conversao de bases que inicializa e executa o fluxo do menu.
 */
void funcBase(void);

#endif /* BASES_H */