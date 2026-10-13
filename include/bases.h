#ifndef BASES_H
#define BASES_H

#include <stddef.h>

/**
 * Pega um texto normal e transforma nos codigos ASCII em decimal separados por espaco.
 *
 * @warning Suporta apenas caracteres da tabela ASCII padrao (sem acentos ou caracteres especiais).
 *
 * @param senha Texto original pra converter.
 * @return String alocada com os codigos numericos (lembrar de dar free depois).
 */
char* texto_para_ascii(char* senha);

/**
 * Pega os codigos ASCII em texto (tipo "65 66 67") e remonta a palavra original.
 *
 * @warning Decodifica apenas codigos da tabela ASCII padrao (0 a 127).
 *
 * @param senha String com os codigos ASCII separados por espaco.
 * @return String com o texto original decodificado.
 */
char* ascii_para_texto(char* senha);

/**
 * Pega um numero decimal em texto e devolve em hexadecimal.
 *
 * @param senha Numero em base 10 passado como string (ex: "255").
 * @return String com o valor em hexadecimal (ex: "FF").
 */
char* base10_para_base16(char* senha);

/**
 * Pega uma string em hexadecimal e converte pra decimal.
 *
 * @param senha Texto em hexadecimal (ex: "1A" ou "ff").
 * @return String com o valor correspondente em decimal (ex: "26").
 */
char* base16_para_base10(char* senha);

/**
 * Pega um numero decimal em texto e devolve os bits dele em binario.
 *
 * @param senha Numero em base 10 passado como string (ex: "13").
 * @return String com os bits em binario (ex: "1101").
 */
char* base10_para_base2(char* senha);

/**
 * Pega uma string de 0s e 1s e devolve o valor em decimal.
 *
 * @param senha Sequencia binaria (ex: "1101").
 * @return String com o valor em base 10 (ex: "13").
 */
char* base2_para_base10(char* senha);

#endif /* BASES_H */