#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

char* hash_xor (char *texto_original ) {
    int tamanho = strlen(texto_original);
    char hash = 0;
    for(int i=0; i<tamanho; i++){
        hash ^= texto_original[i]; 
    }
    char *hash_hex = (char *) malloc (3 * sizeof(char));
    sprintf(hash_hex, "%02X", hash);
    return hash_hex;
}

char* hash_djb2 (char *texto_original) {
    int tamanho = strlen(texto_original);
    long hash = 5381;
    for(int i=0; i<tamanho; i++){
        hash = ((hash<<5 + hash) + texto_original[i]);
    }
    char *hash_hex = (char*) malloc (17 * sizeof(char));
    snprintf(hash_hex, 17, "%016lX", hash);
    return hash_hex;
}
