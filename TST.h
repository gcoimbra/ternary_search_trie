// TRABALHO PRÁTICO DE AEDS II

// Alunos: Gabriel Coimbra - 3044
// 				 Maria Dalila Vieira - 3030
//				 Naiara - 3005

// Fontes: https://github.com/FurlanV/Ternary-Search-Tree
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define G_ERROR  "\x1B[1m \x1B[31m"
#define MAX_DICIONARIO 100000UL
#define MAX_PALAVRA 50
#define VERBOSE

typedef struct nodeTST nodeTST;
typedef struct nodeTST
{
		char item;

		//verdadeiro caso a letra seja a ultima letra de uma das palavras
		unsigned int fim_string: 1;

		struct nodeTST *esq;
		struct nodeTST *mid;
		struct nodeTST *dir;
} nodeTST;

nodeTST *novoNo(char item);
void tstInsere(nodeTST **nodeTST, char *palavra);

void tstImprimeAux(nodeTST **nodeTST, char *buffer, int profundidade);
void tstImprime(nodeTST **nodeTST);
int tstPesquisa(nodeTST **no_atual,char *palavra, int64_t *comparacoes);
int tstPesquisaAux(nodeTST **no_atual,char *palavra, int64_t *comparacoes);

int64_t tstContaNos(nodeTST **nodeTST);
void tstContaNosAux(nodeTST **nodeTST, int64_t *quantidade);

void tstAlturaMaiorPalavraAux(nodeTST **nodeTST, int64_t *max_palavra_global, int64_t max_palavra);
int64_t tstAlturaMaiorPalavra(nodeTST **nodeTST);

void tstAlturaPalavraAux(nodeTST **no_atual, char *palavra, int64_t *profundidade);
int64_t tstAlturaPalavra(nodeTST **no_atual,char *palavra);
