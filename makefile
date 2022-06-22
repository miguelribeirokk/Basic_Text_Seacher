all:
	 gcc -o main main.c cores/cores.c funcoes.c tads/patricia.c tads/linked_list.c -lm

run:
	./main