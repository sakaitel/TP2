#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char* gerar_senha(char *senha, int tamanho) {
    if (tamanho < 6 || tamanho > 50 ) {
        return NULL;
    }
    
    char letras_maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    char letras_minusculas[] = "abcdefghijklmnopqrstuvwxyz"; 
    char numeros[] = "1234567890"; 
    char caracteres_especiais[] = "!#$%&'()*+,-./:;<=>?@"; 
    srand(time(NULL));
    
    senha = (char*)malloc((tamanho+1)* sizeof(char));
    
    for (int i = 0; i < tamanho; i++){
        switch (i%4){
            case 0: senha[i] = letras_maiusculas[(rand() % strlen(letras_maiusculas))]; break;
            case 1: senha[i] = letras_minusculas[(rand() % strlen(letras_minusculas))]; break;
            case 2: senha[i] = numeros[(rand() % strlen(numeros))]; break;
            case 3: senha[i] = caracteres_especiais[(rand() % strlen(caracteres_especiais))]; break;
        }
   }
    
    for (int i = tamanho - 1; i > 0; i--) {
        int j = (rand() % (i + 1));
        char temp = senha[j];
        senha[j] = senha[i];
        senha[i] = temp;
    }

    senha[tamanho] = '\0';
    
    return senha;
}

int analisar_forca_senha(char *senha) {
    if (senha == NULL) {
        return -1;
    }
    
    int tamanho = strlen(senha);

    if (tamanho < 6) {
        return 0;
    }
    
    int maiusculas = 0, minusculas = 0, numeros = 0, car_especiais = 0;
    int pontuacao = 0, penalidades = 0;

    for(int i = 0; i < tamanho; i++){
        if (senha[i] == senha[(i+1) % tamanho]) penalidades++; //caracteres repetidos

        //contagem de maiusculas, minusculas, numeros e caracteres especiais ( !#$%&'()*+,-./  :;<=>?@ )
        int x = (int) senha[i];
        if('A' <= x && x <= 'Z') maiusculas++;
        else if('a'<= x && x <='z') minusculas++;
        else if('0' <= x && x <= '9') numeros++;
        else if(('!' <= x && x <= 47)||(':' <= x && x <= 64)) car_especiais++;
    }

    if (tamanho >= 12) pontuacao+=2;
    if (maiusculas >= 1) pontuacao+=2;
    if (minusculas >= 1) pontuacao+=2;
    if (numeros >= 1) pontuacao+=2;
    if (car_especiais >= 1) pontuacao+=2;
    
    pontuacao -= penalidades;
    if (pontuacao < 0) pontuacao = 0;
    if (pontuacao > 10) pontuacao = 10;
    
    return pontuacao;
}


/*
int main(){
    char *senha;
    int tamanho = 0;
    
    //gerar_senha
    printf("Escolha o tamanho desejado da sua senha (entre 6 e 50 caracteres):\n");
    scanf("%d", &tamanho);

    senha = gerar_senha(senha, tamanho);

    if (senha == NULL) {
        printf("Erro: Tamanho da senha deve ser entre 6 e 50 caracteres.\n");
        return -1;
    }

    printf("\nSenha gerada: %s\n", senha);

    printf("\n--------------\n\n");

    //analisar_forca_senha
    printf("Escreva sua senha forte:\n");
    scanf("%s", senha);

    int pontuacao = analisar_forca_senha(senha);

    printf("\nForça da senha (de 0 a 10): %d\n", pontuacao);

    free(senha);
    
    return 0;
}

*/