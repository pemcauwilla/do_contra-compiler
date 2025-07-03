# Compilador do_contra

Este projeto implementa um compilador para uma linguagem simples, "do_contra". O compilador traduz o código-fonte em "do_contra" para a linguagem C.

## Pré-requisitos

### Linux (Debian/Ubuntu)

É necessário ter os pacotes `make`, `gcc`, `flex` e `bison` instalados. Para instalá-los, execute:

```bash
sudo apt-get update
sudo apt-get install make gcc flex bison
```

### Windows

Para compilar e executar no Windows, você precisará de um ambiente de desenvolvimento C com as ferramentas `gcc`, `flex` e `bison`. Recomendamos o uso do [MinGW-w64](https://www.mingw-w64.org/). Após a instalação do MinGW, certifique-se de que o diretório `bin` está no `PATH` do sistema e instale o `flex` e `bison` através do `pacman`:

```bash
pacman -S flex bison
```

## Como Compilar e Executar

### Linux (com `make`)

O `makefile` automatiza todo o processo de compilação e execução dos exemplos.

1.  **Limpar o Projeto:**
    Para remover todos os arquivos gerados (`bin`, `build`, `output`), execute:
    ```bash
    make clean
    ```

2.  **Compilar o Compilador:**
    Para construir o compilador (`meu_compilador`), execute:
    ```bash
    make
    ```
    Isso criará o executável em `bin/meu_compilador`.

3.  **Executar os Exemplos:**
    Para compilar e executar os três arquivos de exemplo (`exemplo1_io.con`, `exemplo2_condicional.con`, `exemplo3_repeticao.con`), execute:
    ```bash
    make run
    ```
    Este comando irá:
    - Usar o `meu_compilador` para traduzir os arquivos `.con` para arquivos `.c` (em `output/`).
    - Gerar uma lista de tokens para cada exemplo (em `output/`).
    - Compilar os arquivos `.c` gerados com o `gcc`.
    - Executar os programas resultantes.



### Windows (manualmente)

Primeiramente, para executar novamente o trabalho, remova as pastas bin, build e output

```bash
rd /s /q bin
rd /s /q build
rd /s /q output
```

Execute os seguintes comandos no terminal.

1.  **Criar os diretórios:**
    ```bash
    mkdir bin build output
    ```

2.  **Compilar o Compilador:**
    ```bash
    bison -d -o build/sintatico.tab.c src/sintatico.y
    flex -o build/lexico.yy.c src/lexico.l
    gcc build/sintatico.tab.c build/lexico.yy.c -o bin/meu_compilador -lfl
    ```

3.  **Executar um Exemplo (ex: `exemplo1_io.con`):**
    - **Traduza o código "do_contra" para C:**
      ```bash
      ./bin/meu_compilador test_code/exemplo1_io.con output/ex1_saida.c output/ex1_tokens.txt
      ```
    - **Compile o código C gerado:**
      ```bash
      gcc output/ex1_saida.c -o bin/ex1.exe
      ```
    - **Execute o programa:**
      ```bash
      ./bin/ex1.exe
      ```
    - **Exemplo 2 (`exemplo2_condicional.con`):**
      ```bash
      ./bin/meu_compilador test_code/exemplo2_condicional.con output/ex2_saida.c output/ex2_tokens.txt
      gcc output/ex2_saida.c -o bin/ex2.exe
      ./bin/ex2.exe
      ```

    - **Exemplo 3 (`exemplo3_repeticao.con`):**
      ```bash
      ./bin/meu_compilador test_code/exemplo3_repeticao.con output/ex3_saida.c output/ex3_tokens.txt
      gcc output/ex3_saida.c -o bin/ex3.exe
      ./bin/ex3.exe
      ```
