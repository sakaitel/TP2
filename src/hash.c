#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

char* hash_xor (char *texto_original) {
    if (texto_original == NULL) {
        return NULL;
    }
    
    int tamanho = strlen(texto_original);
    unsigned char hash[4] = {0, 0, 0, 0};
    for(int i=0; i<tamanho; i++){
        hash[i%4] ^= (unsigned char)texto_original[i]; 
    }
    char *hash_hex = (char *) malloc (9 * sizeof(char));
    if (hash_hex == NULL) {
        return NULL;
    }
    
    sprintf(hash_hex, "%02x%02x%02x%02x", hash[0], hash[1], hash[2], hash[3]);
    return hash_hex;
}

char* hash_djb2 (char *texto_original) {
    if (texto_original == NULL){
        return NULL;
    }
    
    int tamanho = strlen(texto_original);
    unsigned int hash = 5381;
    for(int i=0; i<tamanho; i++){
        hash = (((hash<<5) + hash) + (unsigned char)texto_original[i]);
    }
    char *hash_hex = (char*) malloc (9 * sizeof(char));
    if (hash_hex == NULL){
        return NULL;
    }
    
    snprintf(hash_hex, 9, "%08lx", hash);
    return hash_hex;
}
