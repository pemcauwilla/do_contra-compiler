
.PHONY: all run clean

all: bin/meu_compilador

run: test1 test2 test3

test1: bin/meu_compilador
	@echo "--- Rodando Exemplo 1 (I/O) ---"
	./bin/meu_compilador test_code/exemplo1_io.con output/ex1_saida.c output/ex1_tokens.txt
	@gcc output/ex1_saida.c -o bin/ex1.exe
	@echo "--- Saída do Programa 1: ---"
	@./bin/ex1.exe

test2: bin/meu_compilador
	@echo "--- Rodando Exemplo 2 (Condicionais) ---"
	./bin/meu_compilador test_code/exemplo2_condicional.con output/ex2_saida.c output/ex2_tokens.txt
	@gcc output/ex2_saida.c -o bin/ex2.exe
	@echo "--- Saída do Programa 2: ---"
	@./bin/ex2.exe

test3: bin/meu_compilador
	@echo "--- Rodando Exemplo 3 (Repetição) ---"
	./bin/meu_compilador test_code/exemplo3_repeticao.con output/ex3_saida.c output/ex3_tokens.txt
	@gcc output/ex3_saida.c -o bin/ex3.exe
	@echo "--- Saída do Programa 3: ---"
	@./bin/ex3.exe

clean:
	@echo "Limpando o projeto..."
	@rm -rf bin build output

bin/meu_compilador: build/sintatico.tab.c build/lexico.yy.c
	@mkdir -p bin
	@mkdir -p output
	@gcc $^ -o $@ -lfl

build/sintatico.tab.c: src/sintatico.y
	@mkdir -p build
	@bison -d -o $@ $<

build/lexico.yy.c: src/lexico.l build/sintatico.tab.h
	@mkdir -p build
	@flex -o $@ $<