#ifndef GULOSO_C
#define GULOSO_C 

#include "geral.h"
#include "Guloso.h"

int LISG(Par *pares, int N) {
	/*algoritmo baseado no Patience Sort*/
	/*pilhas: vetor pra armazenar elementos no topo das pilhas, comp: total de pilhas utilizadas, i: percorre for*/
	int pilhas[N], comp = 0, i = 0;

	/*adiciona primeiro elemento do vetor à pilha*/
	pilhas[0] = pares[0].impar;
	/*informa que primeira pilha foi usada*/
	comp = 1;

	for(i = 1; i < N; i++) {
		/*para cada elemento do vetor, faz pesquisa binária para saber a pilha de inserção*/
		int meio = 0, esq = 0, dir = comp - 1;
		while(esq <= dir) {
			meio = (esq + dir)/2;
			(pares[i].impar > pilhas[meio]) ? (esq = meio + 1) : (dir = meio - 1); 
		}
		/*se a esquerda é maior que o comprimento, uma nova pilha foi preenchida*/
		comp += (esq >= comp);
		/*se não, adiciona o elemento atual na pilha mais esquerda possível*/
		pilhas[esq] = pares[i].impar;
	}
	/*retorna número de pilhas*/
	return comp;
} /*LISG*/

#endif	//GULOSO_C
