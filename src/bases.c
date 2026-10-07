#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"

char* texto_para_ascii(char* senha) {
    if (senha == NULL) return NULL;

    int tam = strlen(senha);
    char* senha_criptografada = (char*) malloc(tam * 4 + 1);
    int pos = 0;

    for (int i = 0; i < tam; i++) {
        pos += sprintf(senha_criptografada + pos, "%d ", (char)senha[i]);
    }

    if (pos > 0) senha_criptografada[pos - 1] = '\0';
    else senha_criptografada[0] = '\0';

    return senha_criptografada;
}

char* ascii_para_texto(char* senha) {
    if (senha == NULL || strlen(senha) == 0) return NULL;

    int tam = strlen(senha);
    char* texto = (char*) malloc(tam + 1);
    int pos = 0;
    int valorAtual = 0;

    for (int i = 0; senha[i] != '\0'; i++) {
        if (senha[i] == ' ') {
            if (valorAtual > 0) {
                texto[pos++] = (char) valorAtual;
                valorAtual = 0;
            }
            continue;
        }
        valorAtual = valorAtual * 10 + (senha[i] - '0');
    }

    if (valorAtual > 0) {
        texto[pos++] = (char) valorAtual;
    }

    texto[pos] = '\0';
    return texto;
}

char* base10_para_base16(char* senha) {
    if (senha == NULL) return NULL;

    int num = atoi(senha);
    char* resultado = (char*) malloc(32 * sizeof(char));
    sprintf(resultado, "%X", num);
    return resultado;
}

char* base16_para_base10(char* senha) {
    if (senha == NULL) return NULL;

    int valorAtual = 0;

    for (int i = 0; senha[i] != '\0'; i++) {
        char c = senha[i];
        int digito = 0;

        if (c >= '0' && c <= '9') {
            digito = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digito = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digito = c - 'a' + 10;
        } else {
            continue;
        }

        valorAtual = valorAtual * 16 + digito;
    }

    char* resultado = (char*) malloc(33 * sizeof(char));
    sprintf(resultado, "%d", valorAtual);
    return resultado;
}

char* base10_para_base2(char* senha) {
    if (senha == NULL) return NULL;

    unsigned int num = (unsigned int) atoi(senha);
    char* resultado = (char*) malloc(33 * sizeof(char));

    if (num == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        return resultado;
    }

    int pos = 0;
    int iniciou = 0;

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (bit == 1) iniciou = 1;
        if (iniciou) {
            resultado[pos++] = bit + '0';
        }
    }

    resultado[pos] = '\0';
    return resultado;
}

char* base2_para_base10(char* senha) {
    if (senha == NULL) return NULL;

    int valorb10 = 0;

    for (int i = 0; senha[i] != '\0'; i++) {
        if (senha[i] == '1') {
            valorb10 = valorb10 * 2 + 1;
        } else if (senha[i] == '0') {
            valorb10 = valorb10 * 2;
        }
    }

    char* resultado = (char*) malloc(32 * sizeof(char));
    sprintf(resultado, "%d", valorb10);
    return resultado;
}