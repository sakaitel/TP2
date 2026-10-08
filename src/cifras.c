#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cifrar_cesar(char *texto, int deslocamento, char *resultado) {
    if (texto == NULL) return NULL;
    
    int tamanho_texto = strlen(texto);
    resultado = (char*)malloc((tamanho_texto + 1) * sizeof(char));
    
    if (resultado == NULL) return NULL;

    deslocamento = deslocamento % 26;
    if (deslocamento < 0) deslocamento += 26;

    for (int i = 0; i < tamanho_texto; i++) {
        char caractere_atual = texto[i];
        if (caractere_atual >= 'A' && caractere_atual <= 'Z') {
            resultado[i] = ((caractere_atual - 'A' + deslocamento) % 26) + 'A';
        } else if (caractere_atual >= 'a' && caractere_atual <= 'z') {
            resultado[i] = ((caractere_atual - 'a' + deslocamento) % 26) + 'a';
        } else {
            resultado[i] = caractere_atual;
        }
    }
    resultado[tamanho_texto] = '\0';
    
    return resultado;
}

char* decifrar_cesar(char *texto_cifrado, int deslocamento, char *resultado) {
    return cifrar_cesar(texto_cifrado, -deslocamento, resultado);
}

char* cifrar_vigenere(char *texto, char *chave, char *resultado) {
    if (texto == NULL || chave == NULL) return NULL;
    
    int tamanho_texto = strlen(texto);
    int tamanho_chave = strlen(chave);
    
    if (tamanho_chave == 0) return NULL;

    resultado = (char*)malloc((tamanho_texto + 1) * sizeof(char));
    
    if (resultado == NULL) return NULL;

    int j = 0;
    for (int i = 0; i < tamanho_texto; i++) {
        char caractere_atual = texto[i];
        
        if (caractere_atual >= 'A' && caractere_atual <= 'Z') {
            int shift;
            char char_chave = chave[j % tamanho_chave];
            
            if (char_chave >= 'A' && char_chave <= 'Z') {
                shift = char_chave - 'A';
            } else if (char_chave >= 'a' && char_chave <= 'z') {
                shift = char_chave - 'a';
            } else {
                shift = 0;
            }
            
            resultado[i] = ((caractere_atual - 'A' + shift) % 26) + 'A';
            j++;
            
        } else if (caractere_atual >= 'a' && caractere_atual <= 'z') {
            int shift;
            char char_chave = chave[j % tamanho_chave];
            
            if (char_chave >= 'A' && char_chave <= 'Z') {
                shift = char_chave - 'A';
            } else if (char_chave >= 'a' && char_chave <= 'z') {
                shift = char_chave - 'a';
            } else {
                shift = 0;
            }
            
            resultado[i] = ((caractere_atual - 'a' + shift) % 26) + 'a';
            j++;
            
        } else {
            resultado[i] = caractere_atual;
        }
    }
    resultado[tamanho_texto] = '\0';
    
    return resultado;
}

char* decifrar_vigenere(char *texto_cifrado, char *chave, char *resultado) {
    if (texto_cifrado == NULL || chave == NULL) return NULL;
    
    int tamanho_texto = strlen(texto_cifrado);
    int tamanho_chave = strlen(chave);
    
    if (tamanho_chave == 0) return NULL;

    resultado = (char*)malloc((tamanho_texto + 1) * sizeof(char));
    
    if (resultado == NULL) return NULL;

    int j = 0;
    for (int i = 0; i < tamanho_texto; i++) {
        char caractere_atual = texto_cifrado[i];
        
        if (caractere_atual >= 'A' && caractere_atual <= 'Z') {
            int shift;
            char char_chave = chave[j % tamanho_chave];
            
            if (char_chave >= 'A' && char_chave <= 'Z') {
                shift = char_chave - 'A';
            } else if (char_chave >= 'a' && char_chave <= 'z') {
                shift = char_chave - 'a';
            } else {
                shift = 0;
            }
            
            int calculo_modulo = (caractere_atual - 'A' - shift) % 26;
            if (calculo_modulo < 0) calculo_modulo += 26;
            resultado[i] = calculo_modulo + 'A';
            j++;
            
        } else if (caractere_atual >= 'a' && caractere_atual <= 'z') {
            int shift;
            char char_chave = chave[j % tamanho_chave];
            
            if (char_chave >= 'A' && char_chave <= 'Z') {
                shift = char_chave - 'A';
            } else if (char_chave >= 'a' && char_chave <= 'z') {
                shift = char_chave - 'a';
            } else {
                shift = 0;
            }
            
            int calculo_modulo = (caractere_atual - 'a' - shift) % 26;
            if (calculo_modulo < 0) calculo_modulo += 26;
            resultado[i] = calculo_modulo + 'a';
            j++;
            
        } else {
            resultado[i] = caractere_atual;
        }
    }
    resultado[tamanho_texto] = '\0';
    
    return resultado;
}