#ifndef FORCABRUTA_H
#define FORCABRUTA_H 

#include "geral.h"

/*compara dois valores e retorna o maior*/
int max(int a, int b);

/*calcula a maior subsequência crescente usando força bruta; ant é o índice utilizado na interação anterior,
esq é o início da partição, dir é o fim da partição*/
int LISFB(Par *pares, int ant, int esq, int dir);

#endif	//FORCABRUTA_H