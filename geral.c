#ifndef GERAL_C
#define GERAL_C 

#include "geral.h"

Par *LeEntrada(int *N, char *gdb) {
	/*i: contador para for, x: primeiro índice, y: segundo índice*/
	int i = 0, x = 0, y = 0; 
	/*vetor de pares*/
	Par *pares = NULL;

	/*recebe seletor*/
	do {
		scanf(" %c", gdb);	
	}while(*gdb != 'g' && *gdb != 'd' && *gdb != 'b');

	/*recebe número de pares*/
	scanf("%d", N);

	/*monta estrutura*/
	pares = CriaPares(*N);

	for (i = 0; i < *N; i++) {
		/*recebe índices*/
		scanf("%d", &x);
		scanf("%d", &y);
		/*confere se x recebeu o índice par*/
		if((x % 2) != 0) {
			int temp = x;
			x = y;
			y = temp;
		}
		/*insere índices na estrutura*/
		pares = InserePar(pares, x, y, i);
	}
	
	/*ordena estrutura pelo lado par do vetor*/
	qsort(pares, *N, sizeof(Par), Compara);

	return pares;
} /*LeEntrada*/

Par *CriaPares(int N) {
	Par *pares = NULL;

	/*aloca e inicializa estrutura*/
	pares = calloc(N, sizeof(Par));
	return pares;
} /*CriaPares*/

Par *InserePar(Par *pares, int par, int impar, int pos) {
	/*insere par na posição dada*/
	pares[pos].par = par;
	pares[pos].impar = impar;

	return pares;
} /*InserePar*/

int Compara(const void *a, const void *b) {
	/*recebe dois pares e compara de acordo com o índice par*/
	Par *A = (Par*)a;
    Par *B = (Par*)b;

    return (A->par < B->par ? -1 : 1);
} /*Compara*/

#endif	//GERAL_C