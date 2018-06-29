#ifndef FORCABRUTA_C
#define FORCABRUTA_C 

#include "geral.h"
#include "ForcaBruta.h"

int max(int a, int b) {
	return (a > b) ? a : b; 
} /*max*/

int LISFB(Par *pares, int ant, int esq, int dir) {
	/*se percorreu todo vetor = testou todas as possibilidades*/
	if(esq > dir)
		return 0;
	/*se o anterior é maior que o atual, mantém o anterior*/
	else if(pares[esq].impar <= ant)
		return LISFB(pares, ant, esq + 1, dir);
	else {
		/*se o atual é maior que o anterior, testa as duas possibilidades = colocar o atual na lista ou não
		depois compara respostas das possibilidades e devolve a maior*/
		int a = LISFB(pares, ant, esq + 1, dir);
		int b = 1 + LISFB(pares, pares[esq].impar, esq + 1, dir);
		return max(a, b);
	}
} /*LISFB*/

#endif	//FORCABRUTA_C