#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "cifras.h"
#include "hash.h"
#include "senhas.h"

int teste_padrao(const char *nome, const char *esperado, char *obtido) {
    if (obtido == NULL) {
    printf("[FALHA] %s\n    a funcao retornou NULL\n", nome);
    return 1;
    }
    int falhou;
    
    falhou = (strcmp(esperado, obtido) != 0);
    if (falhou) {
        printf("[FALHA] %s\n    esperado: \"%s\"\n    obtido:   \"%s\"\n", nome, esperado, obtido);
    } else {
        printf("[APROVADO] %s\n", nome);
    }

    free(obtido);
    return falhou;
}


int teste_nulo(const char *nome, char *obtido) {
    if (obtido == NULL) {
        printf("[APROVADO] %s\n", nome);
        return 0;
    }
    printf("[FALHA] %s\n    esperado NULL, obtido \"%s\"\n", nome, obtido);
    free(obtido);
    return 1;
}

int teste_gerar_senhas(const char *nome, const int esperado, char *obtido) {
    if (obtido == NULL) {
    printf("[FALHA] %s\n    a funcao retornou NULL\n", nome);
    return 1;
    }
    int falhou;

    falhou = ((int)strlen(obtido) != esperado);
    if (falhou) {
        printf("[FALHA] %s\n    esperado: \"%d caracteres\"\n    obtido:   \"%zu caracteres\"\n", nome, esperado, strlen(obtido));
    }else {
        printf("[APROVADO] %s\n", nome);
    }
    
    free(obtido);
    return falhou;
}

int teste_padrao_forca(const char *nome, int obtido) {
    if (obtido == 6) {
        printf("[APROVADO] %s\n", nome);
        return 0;
    }
    printf("[FALHA] %s\n    esperado 6, obtido \"%d\"\n", nome, obtido);
    return 1;

}

int teste_invalido_forca(const char *nome, int obtido) {
     if (obtido == -1) {
        printf("[APROVADO] %s\n", nome);
        return 0;
    }
    printf("[FALHA] %s\n    esperado -1, obtido \"%d\"\n", nome, obtido);
    return 1;

}


int main(void) {
    int falhas = 0;

    falhas += teste_padrao("(BASES)teste padrao: texto para ascii", "116 101 115 116 101", texto_para_ascii("teste"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: texto para ascii", texto_para_ascii(NULL));
    falhas += teste_padrao("(BASES)teste padrao: ascii para texto", "teste", ascii_para_texto("116 101 115 116 101"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: ascii para texto", ascii_para_texto(NULL));
    falhas += teste_padrao("(BASES)teste padrao: base 10 para base 16", "AB", base10_para_base16("171"));
    falhas += teste_padrao("(BASES)teste limite entrada 0: base 10 para base 16", "0", base10_para_base16("0"));
    falhas += teste_padrao("(BASES)teste limite int max: base 10 para base 16", "7FFFFFFF", base10_para_base16("2147483647"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: base 10 para base 16", base10_para_base16(NULL));
    falhas += teste_padrao("(BASES)teste padrao: base 16 para base 10", "171", base16_para_base10("AB"));
    falhas += teste_padrao("(BASES)teste limite entrada 0: base 16 para base 10", "0", base16_para_base10("0"));
    falhas += teste_padrao("(BASES)teste limite entrada int max: base 16 para base 10", "2147483647", base16_para_base10("7FFFFFFF"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: base 16 para base 10", base16_para_base10(NULL));
    falhas += teste_padrao("(BASES)teste padrao: base 10 para base 2", "10101011", base10_para_base2("171"));
    falhas += teste_padrao("(BASES)teste limite entrada 0: base 10 para base 2", "0", base10_para_base2("0"));
    falhas += teste_padrao("(BASES)teste limite int max: base 10 para base 2", "1111111111111111111111111111111", base10_para_base2("2147483647"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: base 10 para base 2", base10_para_base2(NULL));
    falhas += teste_padrao("(BASES)teste padrao: base 2 para base 10", "171", base2_para_base10("10101011"));
    falhas += teste_padrao("(BASES)teste limite entrada 0: base 2 para base 10", "0", base2_para_base10("0"));
    falhas += teste_padrao("(BASES)teste limite int max: base 2 para base 10", "2147483647", base2_para_base10("1111111111111111111111111111111"));
    falhas += teste_nulo("(BASES)teste entrada invalida nula: base 2 para base 10", base2_para_base10(NULL));

    falhas += teste_padrao("(CIFRAS)teste padrao: cifrar cesar", "grfgr", cifrar_cesar("teste", 13, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave 0: cifrar cesar", "teste", cifrar_cesar("teste", 0, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave 26: cifrar cesar", "teste", cifrar_cesar("teste", 26, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite virada do alfabeto: cifrar cesar", "abc", cifrar_cesar("xyz", 3, NULL));
    falhas += teste_nulo("(CIFRAS)teste entrada invalida nula: cifrar cesar", cifrar_cesar(NULL, 13, NULL));
    falhas += teste_padrao("(CIFRAS)teste padrao: decifrar cesar", "teste", decifrar_cesar("grfgr", 13, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave 0: decifrar cesar", "teste", decifrar_cesar("teste", 0, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite virada do alfabeto: decifrar cesar", "xyz", decifrar_cesar("abc", 3, NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave 26: decifrar cesar", "teste", decifrar_cesar("teste", 26, NULL));
    falhas += teste_nulo("(CIFRAS)teste entrada invalida nula: decifrar cesar", decifrar_cesar(NULL, 13, NULL));
    falhas += teste_padrao("(CIFRAS)teste padrao: cifrar vigenere", "tfutf", cifrar_vigenere("teste", "abc", NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave de 1 letra: cifrar vigenere", "mxlmx", cifrar_vigenere("teste", "t", NULL));
    falhas += teste_nulo("(CIFRAS)teste entrada invalida nula: cifrar vigenere", cifrar_vigenere(NULL, "abc", NULL));
    falhas += teste_padrao("(CIFRAS)teste padrao: decifrar vigenere", "teste", decifrar_vigenere("tfutf", "abc", NULL));
    falhas += teste_padrao("(CIFRAS)teste limite chave de 1 letra: decifrar vigenere", "teste", decifrar_vigenere("mxlmx", "t", NULL));
    falhas += teste_nulo("(CIFRAS)teste entrada invalida nula: decifrar vigenere", decifrar_vigenere(NULL, "abc", NULL));

    falhas += teste_padrao("(HASH)teste padrao: hash com xor", "11657374", hash_xor("teste"));
    falhas += teste_padrao("(HASH)teste limite entrada vazia: hash com xor", "00000000", hash_xor(""));
    falhas += teste_nulo("(HASH)teste entrada invalida nula: hash com xor", hash_xor(NULL));
    falhas += teste_padrao("(HASH)teste padrao: hash com djb2", "106b756a", hash_djb2("teste"));
    falhas += teste_padrao("(HASH)teste limite entrada vazia: hash com djb2", "00001505", hash_djb2(""));
    falhas += teste_nulo("(HASH)teste entrada invalida nula: hash com djb2", hash_djb2(NULL));

    falhas += teste_gerar_senhas("(SENHAS)teste padrao: gerar senha", 25, gerar_senha(NULL, 25));
    falhas += teste_gerar_senhas("(SENHAS)teste limite entrada 6: gerar senha", 6, gerar_senha(NULL, 6));
    falhas += teste_gerar_senhas("(SENHAS)teste limite entrada 50: gerar senha", 50, gerar_senha(NULL, 50));
    falhas += teste_nulo("(SENHAS)teste entrada invalida abaixo de 6: gerar senha", gerar_senha(NULL, 5));
    falhas += teste_nulo("(SENHAS)teste entrada invalida acima de 50: gerar senha", gerar_senha(NULL, 51));
    falhas += teste_padrao_forca("(SENHAS)teste padrao: analisar forca da senha", analisar_forca_senha("t3st3p@dr@0"));
    falhas += teste_invalido_forca("(SENHAS)teste entrada invalida nula: analisar forca da senha", analisar_forca_senha(NULL));
    
    

    printf("\n%d teste(s) com falha\n", falhas);
    return falhas != 0;

    
}

