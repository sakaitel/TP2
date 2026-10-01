#include <stdio.h>
#include <string.h>
#include "bases.h"


void menu(int* CriptoDescripto, int* tmb){

    while(*CriptoDescripto != 1 && *CriptoDescripto != 2){

        printf("O que voce deseja fazer?\n1 - Criptografar\n2 - Descriptografar\nDigite o numero da opcao: ");
        scanf("%d", CriptoDescripto);

        if(*CriptoDescripto != 1 && *CriptoDescripto != 2){
            *CriptoDescripto = -1;
            printf("Selecione uma opcao valida (1 ou 2)\n\n");
        }
    }


    while(*tmb != 1 && *tmb != 2 && *tmb != 3){
        printf("Qual a mudança de base desejada?\n1 - ASCII \n2 - Base 16\n3 - Base 2\nDigite o numero da opcao: ");
        scanf("%d", tmb);

        if(*tmb != 1 && *tmb != 2 && *tmb != 3){
            printf("Selecione uma opcao valida (1, 2, 3)\n\n");
        }
    }

    char texto[256];
    int numero;

    //criptografar
    if (*CriptoDescripto == 1) {
        if (*tmb == 1) { // texto -> ASCII
            printf("Digite o texto: ");
            scanf(" %[^\n]", texto);
            criptoTextoASCII(texto);
        } 
        else if (*tmb == 2) { // b10->b16
            printf("Digite o numero em decimal: ");
            scanf("%d", &numero);
            b10b16(numero);
        } 
        else if (*tmb == 3) { // b10->b2
            printf("Digite o numero em decimal: ");
            scanf("%d", &numero);
            b10b2(numero);
        }
    } 
    //descriptografar
    else if (*CriptoDescripto == 2) {
        if (*tmb == 1) { // ASCII -> texto
            printf("Digite os codigos ASCII separados por espaco: ");
            scanf(" %[^\n]", texto);
            criptoASCIITexto(texto);
        } 
        else if (*tmb == 2) { // b16->b10
            printf("Digite o hexadecimal: ");
            scanf("%s", texto);
            b16b10(texto);
        } 
        else if (*tmb == 3) { // b2->b10
            printf("Digite o binario: ");
            scanf("%s", texto);
            b2b10(texto);
        }
    }
    

}


void criptoTextoASCII(const char* senha){
    for(int i=0; i<((int)strlen(senha)); i++) {
        printf("%d ", (unsigned char) senha[i]);
    }
    printf("\n");
}

void criptoASCIITexto(char* senha){

    if (senha == NULL || strlen(senha) == 0) return;

    int valorAtual = 0;
    int j=0;
    int vetInt[strlen(senha)];
    for (int i = 0; senha[i] != '\0'; i++) {

        if(senha[i] == ' '){
            if(valorAtual > 0) {
                vetInt[j] = valorAtual;
                j++;
                valorAtual = 0;
            }
            continue;
        }
        valorAtual = valorAtual*10 + (senha[i] - '0');
    }

    if (valorAtual > 0) {
        vetInt[j++] = valorAtual;
    }

    for(int i = 0; i<j; i++){
        printf("%c", vetInt[i]);
    }
    printf("\n");
}

void b10b16(int senha){
    printf("%X\n", senha);
}

void b16b10(const char* senha) {
    if (senha == NULL) return;

    int valorAtual = 0;

    for (int i = 0; senha[i]!='\0'; i++) {
        char c = senha[i];
        int digito = 0;

        if (c >= '0' && c <= '9') {
            digito = c-'0';
        } else if (c >= 'A' && c <= 'F') {
            digito = c-'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digito = c-'a' + 10;
        } else {
            continue;
        }

        valorAtual = valorAtual * 16 + digito;
    }

    printf("%d\n", valorAtual);
}


void b10b2(int senha) {
    if (senha == 0) {
        printf("0\n");
        return;
    }

    int iniciou = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (senha >> i) & 1;
        if (bit == 1) iniciou = 1;
        if (iniciou) printf("%d", bit);
    }
    printf("\n");
}

void b2b10(const char* senha){
    int valorb10 = 0, j=0;
    int tamSenha = strlen(senha);
    for(int i=tamSenha-1; i>=0; i--){
        if(senha[i] == '1'){
            valorb10 += (1 << j);
        }
        j++;
    }
    printf("%d\n", valorb10);
}






void funcBase(){
    int CriptoDescripto = -1;
    int tmb = -1; //tmb = Tipo de Mudanca de Base

    menu(&CriptoDescripto, &tmb);
}