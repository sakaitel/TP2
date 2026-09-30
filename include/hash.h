#ifndef HASH_H
#define HASH_H

/** 
* @brief Cria hash de string passada utilizando a operação XOR
* @param texto_original String a ser transformada em seu respectivo hash
* @return String representando o hash gerado
*/
char hash_xor (char texto_original[])

/** 
* @brief Cria hash de string passada utilizando o algoritmo djb2
* @param texto_original String a ser transformada em seu respectivo hash
* @return String representando o hash gerado
*/
char hash_djb2 (char texto_original[])

#endif