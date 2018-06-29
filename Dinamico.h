#ifndef DINAMICO_H
#define DINAMICO_H 

#include "geral.h" 

/*realiza a busca de um valor x dentro do vetor utilizando pesquisa binária*/
int PBinaria(int *array, int esq, int dir, int x);

/*calcula a maior subsequência crescente usando programação dinâmica; N é o número de pares no vetor*/
int LISDP(Par *pares, int N);
 
#endif	//DINAMICO_H