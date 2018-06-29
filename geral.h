#ifndef GERAL_H
#define GERAL_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*estrutura que armazena cada bar e casa respectivos juntos*/
typedef struct Par {
	int par;		/*índice par em um lado da rua*/
	int impar;		/*índice ímpar no outro lado da rua*/
} Par;

/*recebe a entrada e chama funções para montar a estrutura; N é o número de pares, gdb é o seletor de algoritmos*/
Par *LeEntrada(int *N, char *gdb);

/*cria vetor de pares; N é o número de pares*/
Par *CriaPares(int N);

/*insere um novo par ao vetor de pares; par e ímpar são os índices a serem inseridos, pos é a posição de inserção*/
Par *InserePar(Par *pares, int par, int impar, int pos);

/*compara dois pares*/
int Compara(const void *a, const void *b);

#endif	//GERAL_H