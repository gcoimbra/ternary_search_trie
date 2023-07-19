// TRABALHO PRÁTICO DE AEDS II

// Alunos: Gabriel Coimbra - 3044
// 				 Maria Dalila Vieira - 3030
//				 Naiara Cristine - 3005

// Fontes: https://github.com/FurlanV/Ternary-Search-Tree
// Agradecimentos: Daniel Freitas pela correção em tstContaNosAux
#include "TST.h"

nodeTST *novoNo(char item)
{
		nodeTST *novo_no = (nodeTST*)malloc(sizeof(nodeTST));
		if(novo_no == NULL)
		{
			printf("novoNo(): ERRO FATAL impossível alocar espaço!\n");
			exit(-1);
		}
		novo_no->item = item;
		novo_no->fim_string = 0;
		novo_no->dir = NULL;
		novo_no->mid = NULL;
		novo_no->esq = NULL;

		return novo_no;
}

void tstInsere(nodeTST **no_atual,char *palavra)
{
		//Caso Base
		if(!(*no_atual))
				*no_atual = novoNo(*palavra);

		//Se o caracter atual da palavra for menor do que o caracter da no_atual
		//entao inserimos essa palavra na subarvore a esquerda da no_atual
		if((*palavra) < (*no_atual)->item)
				tstInsere(&(*no_atual)->esq,palavra);

		//Se o caracter atual da palavra for maior do que o caracter da no_atual
		//entao inserimos essa palavra na subarvore a direita da no_atual
		else if((*palavra) > (*no_atual)->item)
				tstInsere(&(*no_atual)->dir,palavra);

		//Se o caracter atual da palavra é o mesmo caracter da no_atual
		else
		{
				if(*(palavra+1))
						tstInsere(&(*no_atual)->mid,palavra+1);
				else
						(*no_atual)->fim_string = 1;
		}
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void tstImprimeAux(nodeTST **no_atual, char *palavra, int profundidade)
{
	assert(palavra[profundidade] != '\0');

	if(*no_atual)
	{
		//primeiro percorre a subarvore a esquerda
		tstImprimeAux(&(*no_atual)->esq,palavra,profundidade);

		//Guarda o caracter deste nó
		palavra[profundidade] = (*no_atual)->item;

		if((*no_atual)->fim_string)
		{
				palavra[profundidade+1] = '\0';
				printf("%s\n",palavra);
		}

		//percorre a subarvore do meio
		tstImprimeAux(&(*no_atual)->mid,palavra,profundidade+1);
		//Finalmente percorre a subarvore da direta
		tstImprimeAux(&(*no_atual)->dir,palavra,profundidade);
	}
}

// Imprime todos nós. Função encapsulada
void tstImprime(nodeTST **no_atual)
{
		char palavra[MAX_PALAVRA];
		tstImprimeAux(no_atual,palavra,0);
}

// Busca string específica
int tstPesquisaAux(nodeTST **no_atual,char *palavra, int64_t *comparacoes)
{
	assert(comparacoes != NULL);

	(*comparacoes)++;
		if(!(*no_atual))
		{
			printf("tstPesquisaAux(): Elemento não encontrado!\n");
			return  0;
		}

    // Percorre a árvore
		if(*palavra < (*no_atual)->item)
				return tstPesquisaAux(&(*no_atual)->esq,palavra,comparacoes);

		if (*palavra > (*no_atual)->item)
				return tstPesquisaAux(&(*no_atual)->dir,palavra,comparacoes);
		else
		{
			// Termina busca
				if(*(palavra+1) == 0)
						return (*no_atual)->fim_string;
				return tstPesquisaAux(&(*no_atual)->mid,palavra+1,comparacoes);

		}
}

int tstPesquisa(nodeTST **no_atual,char *palavra, int64_t *comparacoes)
{
	assert(palavra != NULL);

  // Começa em zero...
	*comparacoes = 0;

	int retorno = tstPesquisaAux(no_atual,palavra,comparacoes);

	return retorno;
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void tstContaNosAux(nodeTST **no_atual, int64_t *quantidade)
{
	if(*no_atual)
	{

		//primeiro percorre a subarvore a esquerda
		tstContaNosAux(&(*no_atual)->esq,quantidade);
		*quantidade += 1;

		//percorre a subarvore do meio
		tstContaNosAux(&(*no_atual)->mid,quantidade);

		//Finalmente percorre a subarvore da direta
		tstContaNosAux(&(*no_atual)->dir,quantidade);
	}
}

// Conta quantos nós. Função encapsulada
int64_t tstContaNos(nodeTST **no_atual)
{
	int64_t quantidade = -1;
	tstContaNosAux(no_atual,&quantidade);
	return quantidade;
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void tstAlturaMaiorPalavraAux(nodeTST **no_atual, int64_t *max_palavra_global, int64_t max_palavra)
{
	if(*no_atual)
	{
		max_palavra++;
		//primeiro percorre a subarvore a esquerda
		tstAlturaMaiorPalavraAux(&(*no_atual)->esq,max_palavra_global,max_palavra);

		//percorre a subarvore do meio
		tstAlturaMaiorPalavraAux(&(*no_atual)->mid,max_palavra_global,max_palavra);
		//Finalmente percorre a subarvore da direta
		tstAlturaMaiorPalavraAux(&(*no_atual)->dir,max_palavra_global,max_palavra);
	}
	else
	{
		if(max_palavra > *max_palavra_global)
	    // Subtrai pois o caso base é -1
			*max_palavra_global = max_palavra - 1;
	}
}

// Procura maior palavras todos nós. Função encapsulada
int64_t tstAlturaMaiorPalavra(nodeTST **no_atual)
{
	int64_t max_palavra_global = 0;
	tstAlturaMaiorPalavraAux(no_atual,&max_palavra_global,0);
	return max_palavra_global;
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void tstAlturaPalavraAux(nodeTST **no_atual, char *palavra, int64_t *profundidade)
{
	assert(*palavra != '\0');
	if(!(*no_atual))
			return;

	(*profundidade)++;
	// Percorre a árvore
	if(*palavra < (*no_atual)->item)
			return tstAlturaPalavraAux(&(*no_atual)->esq,palavra,profundidade);
	else if (*palavra > (*no_atual)->item)
			return tstAlturaPalavraAux(&(*no_atual)->dir,palavra,profundidade);
	else
	{
		// Termina busca
		if(*(palavra+1) == 0)
			return;

		return tstAlturaPalavraAux(&(*no_atual)->mid,palavra+1,profundidade);

	}

}

// Procura palavra vê altura dela. Função encapsulada
int64_t tstAlturaPalavra(nodeTST **no_atual,char *palavra)
{
	int64_t profundidade = -1;
	tstAlturaPalavraAux(no_atual,palavra,&profundidade);
	return profundidade;
}
