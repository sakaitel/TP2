#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cifras.h"
#include "senhas.h"
#include "bases.h"
#include "hash.h"

int char_invalido(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((unsigned char)str[i] > 127) {
            return 1;
        }
    }
    return 0;
}

void menu_cifras() {
    int opcao;
    char texto[256], chave[256];
    int deslocamento;
    char *resultado = NULL;

    printf("\n=== Modulo de Cifras ===\n");
    printf("1 - Cifrar com Cesar\n");
    printf("2 - Decifrar com Cesar\n");
    printf("3 - Cifrar com Vigenere\n");
    printf("4 - Decifrar com Vigenere\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 0) return;

    printf("Digite o texto: ");
    scanf(" %[^\n]", texto);

    if (char_invalido(texto)) {
        printf("\nErro: O texto contem caracteres acentuados ou especiais invalidos.\n");
        return;
    }

    switch (opcao) {
        case 1:
            printf("Digite o deslocamento numerico: ");
            scanf("%d", &deslocamento);
            resultado = cifrar_cesar(texto, deslocamento, resultado);
            break;
        case 2:
            printf("Digite o deslocamento numerico: ");
            scanf("%d", &deslocamento);
            resultado = decifrar_cesar(texto, deslocamento, resultado);
            break;
        case 3:
            printf("Digite a palavra-chave (sem espacos): ");
            scanf("%s", chave);
            if (char_invalido(chave)) {
                printf("\nErro: A chave contem caracteres acentuados.\n");
                return;
            }
            resultado = cifrar_vigenere(texto, chave, resultado);
            break;
        case 4:
            printf("Digite a palavra-chave (sem espacos): ");
            scanf("%s", chave);
            if (char_invalido(chave)) {
                printf("\nErro: A chave contem caracteres acentuados.\n");
                return;
            }
            resultado = decifrar_vigenere(texto, chave, resultado);
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    if (resultado != NULL) {
        printf("\nResultado: %s\n", resultado);
        free(resultado);
    } else {
        printf("\nErro ao processar a cifra.\n");
    }
}

void menu_senhas() {
    int opcao, tamanho, forca;
    char senha_input[256];
    char *senha_gerada = NULL;

    printf("\n=== Modulo de Senhas ===\n");
    printf("1 - Gerar senha forte\n");
    printf("2 - Analisar forca de senha\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o tamanho da senha (6 a 50): ");
            scanf("%d", &tamanho);
            senha_gerada = gerar_senha(senha_gerada, tamanho);
            if (senha_gerada != NULL) {
                printf("\nSenha gerada: %s\n", senha_gerada);
                free(senha_gerada);
            } else {
                printf("\nTamanho invalido!\n");
            }
            break;
        case 2:
            printf("Digite a senha para analise: ");
            scanf(" %[^\n]", senha_input);
            if (char_invalido(senha_input)) {
                printf("\nErro: A senha contem caracteres acentuados.\n");
                return;
            }
            forca = analisar_forca_senha(senha_input);
            printf("\nPontuacao da senha (0 a 10): %d\n", forca);
            break;
        case 0:
            return;
        default:
            printf("Opcao invalida!\n");
    }
}

void menu_bases() {
    int opcao;
    char entrada[256];
    char *resultado = NULL;

    printf("\n=== Modulo de Bases ===\n");
    printf("1 - Texto para ASCII\n");
    printf("2 - ASCII para Texto\n");
    printf("3 - Base 10 para Base 16\n");
    printf("4 - Base 16 para Base 10\n");
    printf("5 - Base 10 para Base 2\n");
    printf("6 - Base 2 para Base 10\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 0) return;

    printf("Digite a entrada: ");
    scanf(" %[^\n]", entrada);

    if (char_invalido(entrada)) {
        printf("\nErro: A entrada contem caracteres acentuados ou especiais invalidos.\n");
        return;
    }

    switch (opcao) {
        case 1:
            resultado = texto_para_ascii(entrada);
            break;
        case 2:
            resultado = ascii_para_texto(entrada);
            break;
        case 3:
            resultado = base10_para_base16(entrada);
            break;
        case 4:
            resultado = base16_para_base10(entrada);
            break;
        case 5:
            resultado = base10_para_base2(entrada);
            break;
        case 6:
            resultado = base2_para_base10(entrada);
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    if (resultado != NULL) {
        printf("\nResultado: %s\n", resultado);
        free(resultado);
    } else {
        printf("\nErro na conversao.\n");
    }
}

void menu_hash() {
    int opcao;
    char texto[256];
    char *resultado = NULL;

    printf("\n=== Modulo de Hashing ===\n");
    printf("1 - Hash XOR\n");
    printf("2 - Hash djb2\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 0) return;

    printf("Digite a string para hashing: ");
    scanf(" %[^\n]", texto);

    if (char_invalido(texto)) {
        printf("\nErro: A string contem caracteres acentuados ou especiais invalidos.\n");
        return;
    }

    switch (opcao) {
        case 1:
            resultado = hash_xor(texto);
            break;
        case 2:
            resultado = hash_djb2(texto);
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    if (resultado != NULL) {
        printf("\nHash resultante: %s\n", resultado);
        free(resultado);
    } else {
        printf("\nErro ao gerar hash.\n");
    }
}

int main() {
    int opcao_principal;

    do {
        printf("\n===================================\n");
        printf("    BIBLIOTECA DE CRIPTOGRAFIA\n");
        printf("===================================\n");
        printf("1 - Cifras\n");
        printf("2 - Senhas\n");
        printf("3 - Conversao de Bases\n");
        printf("4 - Hashing\n");
        printf("0 - Sair\n");
        printf("Escolha um modulo: ");
        scanf("%d", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                menu_cifras();
                break;
            case 2:
                menu_senhas();
                break;
            case 3:
                menu_bases();
                break;
            case 4:
                menu_hash();
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao_principal != 0);

    return 0;
}