#ifndef TP3_C
#define TP3_C 

#include "geral.h"
#include "ForcaBruta.h"
#include "Guloso.h"
#include "Dinamico.h"

int main() {
	/*gdb: seletor de algoritmos*/
	char gdb = '\0';
	/*N: número de pares, sol: valor da soluçãod*/
	int N = 0, sol = 0;
	/*estrutura que armazena os pares*/
	Par *pares = NULL;
	/*recebe a entrada*/
	pares = LeEntrada(&N, &gdb);
	/*seleciona algoritmo a ser executado*/
	switch(gdb) {
		case 'g':
			sol = LISG(pares, N);
			break;
		case 'd':
			sol = LISDP(pares, N);
			break;
		case 'b':
			sol = LISFB(pares, -1, 0, N - 1);
	}

	/*retorna a saída*/
	printf("%d\n", sol);
	/*desaloca vetor*/
	free(pares);
	
	return 0;
}

#endif	//TP3_C