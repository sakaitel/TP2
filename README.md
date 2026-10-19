# Biblioteca Modular de Criptografia em C

Essa biblioteca foi desenvolvida em linguagem C para o **Trabalho Prático 2** da disciplina de Técnicas de Programação.

O objetivo do projeto é fornecer um conjunto reutilizável de ferramentas para criptografia clássica, análise e geração de senhas, conversões de base e funções de integridade (hashing), acompanhado de uma aplicação cliente.

---

## Requisitos e Tecnologias

- **Linguagem:** C 
- **Compilador:** GCC
- **Automação de Build:** GNU Make
- **Controle de Versão:** Git
- **Sistema Operacional:** Linux / Ambiente POSIX (ou WSL no Windows)

---

## Estrutura do Projeto

A organização de diretórios do projeto segue o seguinte formato:

```text
TP2/
├── include/            
│   ├── cifras.h
│   ├── senhas.h
│   ├── bases.h
│   └── hash.h
├── src/                
│   ├── cifras.c
│   ├── senhas.c
│   ├── bases.c
│   └── hash.c
├── app/                
│   └── main.c
├── testes/             
│   └── testes_main.c
├── build/       # objetos .o gerados
├── lib/         # bibliotecas .a e .so geradas
├── bin/         # executáveis gerados
├── .gitignore
├── Makefile
└── README.md
```
Os diretórios build/, lib/ e bin/ são criados durante o processo de compilação e armazenam, respectivamente, os arquivos objeto, as bibliotecas compiladas e os executáveis. Esses artefatos são gerados pelo Makefile e não precisam estar presentes no repositório antes da primeira compilação.

## Módulos e API Pública

A biblioteca conta com 14 funções públicas em 4 módulos:  

1. Cifras  (`include/cifras.h`)  
-   char* cifrar_cesar(char *texto, int deslocamento, char *resultado);
-   char* decifrar_cesar(char *texto_cifrado, int deslocamento, char *resultado);
-   char* cifrar_vigenere(char *texto, char *chave, char *resultado);
-   char* decifrar_vigenere(char *texto_cifrado, char *chave, char *resultado);


2. Senhas (`include/senhas.h`)  
-   char* gerar_senha(char *senha, int tamanho);
-   int analisar_forca_senha(char *senha);

3. Conversão de Bases (`include/bases.h`)  
-   char* texto_para_ascii(char* senha);
-   char* ascii_para_texto(char* senha);
-   char* base10_para_base16(char* senha);
-   char* base16_para_base10(char* senha);
-   char* base10_para_base2(char* senha);
-   char* base2_para_base10(char* senha);

4. Hashing (`include/hash.h`)  
-   char* hash_xor(char *texto_original);
-   char* hash_djb2(char *texto_original);

## Makefile

A compilação usa o Makefile.

## Compilação

Na raiz do projeto, execute:

- `make`: Compila a biblioteca e a aplicação.
- `make run`: Executa usando a biblioteca estática.
- `make run-dinamico`: Executa usando a biblioteca dinâmica.
- `make test`: Executa os testes automatizados.
- `make clean`: Limpa os arquivos compilados.
- `make install`: Instala os arquivos da biblioteca.
