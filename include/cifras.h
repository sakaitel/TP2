#ifndef CIFRAS_H
#define CIFRAS_H

#include <stddef.h>



/**
 * Aplica a cifra de Cesar a uma string.
 *
 * @param texto String original a ser cifrada.
 * @param deslocamento Valor do deslocamento (chave) da cifra.
 * @param resultado Ponteiro onde o texto cifrado sera gravado.
 * @return Ponteiro para a string resultante, ou NULL em caso de erro.
 * @warning O usuario e responsavel por usar free() na string retornada para evitar vazamento de memoria.
 */
char* cifrar_cesar(char *texto, int deslocamento, char *resultado);

/**
 * Reverte a cifra de Cesar de uma string.
 *
 * @param texto_cifrado String cifrada a ser revertida.
 * @param deslocamento Valor do deslocamento (chave) utilizado na cifra.
 * @param resultado Ponteiro onde o texto em claro sera gravado.
 * @return Ponteiro para a string revertida, ou NULL em caso de erro.
 * @warning O usuario e responsavel por usar free() na string retornada para evitar vazamento de memoria.
 */
char* decifrar_cesar(char *texto_cifrado, int deslocamento, char *resultado);



/**
 * Aplica a cifra de Vigenere a uma string baseada em uma palavra-chave.
 *
 * @param texto String original a ser cifrada.
 * @param chave Palavra-chave utilizada para a cifra.
 * @param resultado Ponteiro onde o texto cifrado sera gravado.
 * @return Ponteiro para a string resultante, ou NULL em caso de erro.
 * @warning O usuario e responsavel por usar free() na string retornada para evitar vazamento de memoria.
 */
char* cifrar_vigenere(char *texto, char *chave, char *resultado);

/**
 * Reverte a cifra de Vigenere de uma string baseada na palavra-chave.
 *
 * @param texto_cifrado String cifrada a ser revertida.
 * @param chave Palavra-chave utilizada na cifra original.
 * @param resultado Ponteiro onde o texto em claro sera gravado.
 * @return Ponteiro para a string revertida, ou NULL em caso de erro.
 * @warning O usuario e responsavel por usar free() na string retornada para evitar vazamento de memoria.
 */
char* decifrar_vigenere(char *texto_cifrado, char *chave, char *resultado);

#endif /* CIFRAS_H */