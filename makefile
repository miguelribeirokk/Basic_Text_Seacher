all:
	 gcc -o main main.c cores/cores.c funcoes.c tads/patricia.c tads/linked_list.c tads/hashAssets.c tads/bst.c -lm

run:
	./main