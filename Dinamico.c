#ifndef DINAMICO_C
#define DINAMICO_C 

#include "geral.h"
#include "Dinamico.h"

int PBinaria(int *array, int esq, int dir, int x) {
	while(dir - esq > 1) {
		/*pega elemento do meio*/
		int meio = (esq + dir)/2;
		/*se elemento do meio é maior ou igual ao elemento buscado, pega a parte mais à direita*/
		if(array[meio] >= x)		
			dir = meio;
		else
			/*se o elemento buscado é menor, pega a parte da esquerda*/
			esq = meio;				
	}
	return dir;
} /*PBinaria*/

int LISDP(Par *pares, int N) {
	/*memória: tabela que guarda soluções parciais, comp: número de elementos na memória, i: percorre for*/
	int memoria[N], comp = 1, i = 0;
	/*zera memória*/
	memset(memoria, 0, N*sizeof(int));

	/*insere primeiro item na memória*/
	memoria[0] = pares[0].impar;
	for(i = 1; i < N; i++) {
		/*se item atual é menor do que os outros candidatos, cria nova possibilidade*/
		if(pares[i].impar < memoria[0])
			memoria[0] = pares[i].impar;
		/*se item atual é maior que os candidatos, adiciona no final da memória*/
		else if(pares[i].impar > memoria[comp - 1])
			memoria[comp++] = pares[i].impar;
		else
			/*se ele se encontra em alguma posição no meio, 
			insere na possiblidade onde é maior e substitui a possibilidade de mesmo tamanho*/
			memoria[PBinaria(memoria, -1, comp - 1, pares[i].impar)] = pares[i].impar;
	}
	/*retorna o número de elementos da subsequência crescente máxima*/
	return comp;
} /*LISDP*/

#endif	//DINAMICO_C