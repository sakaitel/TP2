# Checkpoints
Horario limite de entrega para todos os dias: *23:99*  

## Checkpoint 1: 30/09 (Quarta-feira)
- Git inicial (Arthur): isso aqui.  
- README basico (Arthur): criar o README.md com a explicacao inicial do projeto e como ele funciona.  
- Definicao das funcoes (Todos): Cada um deve criar o seu arquivo .h dentro da pasta include com os nomes e parametros das funcoes que vai fazer. Precisamos ter pelo menos 10 funcoes no total.  

**CIFRAS** - Gabrielle  
- criar cesar  
- desfazer cesar  
- fazer vigenere  
- desfazer vigenere  \

**SENHAS** - Arthur  
- gera senha forte  
- analisa quao forte é a senha  \

**MUDANCA DE BASE** - Andre Henrique  
- texto pra ASCII  
- ASCII pra texto  
- base 10 pra base 16  
- base 16 pra base 10  
- base 10 pra base 2  
- base 2 pra base 10  

**HASHING** - Maria Eduarda  
- hash com XOR  
- hash djb2  

## Checkpoint 2: 03/10 (Sabado)  
- Funcoes prontas (Todos): Terminar de escrever o codigo em C das funcoes na pasta src.  
- Programa principal (Gabrielle): Fazer o arquivo main.c dentro da pasta app.  

## Checkpoint 3: 07/10 (Quarta-feira)
- Makefile (Andre): Criar o Makefile do projeto com todos os comandos (all, clean, run, test e install)  
- Bibliotecas estatica e dinamica (Maria Eduarda): Deixar pronto no Makefile o jeito de gerar a biblioteca estatica (.a) e a dinamica (.so), garantindo que o programa funcione com as duas.  

## Checkpoint 4: 10/10 (Sexta-feira) - Sistema Pronto  
- Testes automatizados (Maria Eduarda): Criar a suite de testes que roda com o comando make test. Precisamos salvar a prova de um teste que falhou antes e depois passou.  
- Versao final no Git (Arthur)  
- Divisao dos slides (Todos): Reuniao rapida para decidir o que cada um vai falar.  

## Checkpoint 5: 14/10 (Quarta-feira)
- Relatorio tecnico (Arthur)  
- Slides da apresentacao (Gabrielle)  
- Video demonstrativo (Andre)  


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

A organização de diretórios do projeto segue o seguinte gráfico:

```text
TP2/
├── include/              
│   ├── AAAAAAAAA
│   ├── senhas.h
│   ├── AAAAAAAAA
│   └── AAAAAAAAA
├── src/                  
│   ├── AAAAAAAAA
│   ├── senhas.c
│   ├── AAAAAAAAA
│   └── AAAAAAAAA
├── app/                  
│   └── main.c
├── tests/                
│   └── test_main.c
├── Makefile              
└── README.md             
```
Os artefatos gerados na compilação (build/, .o, .a, .so e executáveis) são mantidos fora do controle de versão via .gitignore.

## Módulos e API Pública

A biblioteca conta com AAAAAAAA funções públicas em 4 módulos:  

1. Cifras  
-   

2. Senhas (`include/passwords.h`)  
-   

3. Conversão de Bases (`include/base_conv.h`)  
-   

4. Hashing (`include/hashing.h`)  
-   


## Makefile

A compilação usa o Makefile:

- `make`: Compila a biblioteca e a aplicação.
- `make run`: Executa usando a biblioteca estática.
- `make run-dynamic`: Executa usando a biblioteca dinâmica (.so).
- `make test`: Executa os testes automatizados.
- `make clean`: Limpa os arquivos compilados.
- `make install`: Instala os arquivos da biblioteca.