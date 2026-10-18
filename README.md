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
│   └── hashing.h
├── src/                
│   ├── cifras.c
│   ├── senhas.c
│   ├── bases.c
│   └── hashing.c
├── app/                
│   └── main.c
├── testes/             
│   └── testes_main.c
├── build/              
├── .gitignore        
├── Makefile            
└── README.md
```
Os artefatos gerados na compilação (build/, .o, .a, .so e executáveis) são mantidos fora do controle de versão via .gitignore.

## Módulos e API Pública

A biblioteca conta com 14 funções públicas em 4 módulos:  

1. Cifras  (`include/cifras.h`)  
-   char* cifrar_cesar(const char *texto, int deslocamento);
-   char* decifrar_cesar(const char *texto_cifrado, int deslocamento);
-   char* cifrar_vigenere(const char *texto, const char *chave); 
-   char* decifrar_vigenere(const char *texto_cifrado, const char *chave);


2. Senhas (`include/senhas.h`)  
-   char* gerar_senha(char *senha, int tamanho);
-   int analisar_forca_senha(const char *senha);

3. Conversão de Bases (`include/bases.h`)  
-   char* texto_para_ascii(const char* senha);
-   char* ascii_para_texto(const char* senha);
-   char* base10_para_base16(const char* senha);
-   char* base16_para_base10(const char* senha);
-   char* base10_para_base2(const char* senha);
-   char* base2_para_base10(const char* senha);

4. Hashing (`include/hash.h`)  
-   char* hash_xor(const char *texto_original);
-   char* hash_djb2(const char *texto_original);

## Makefile

A compilação usa o Makefile:

- `make`: Compila a biblioteca e a aplicação.
- `make run`: Executa usando a biblioteca estática.
- `make run-dinamico`: Executa usando a biblioteca dinâmica.
- `make test`: Executa os testes automatizados.
- `make clean`: Limpa os arquivos compilados.
- `make install`: Instala os arquivos da biblioteca.
