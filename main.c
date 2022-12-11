/*
    -- Implementação de Árvore de Buscar Binária
    -- Metódos:
        Buscar,
        Inserção,
        Remoção.
    -- Autor: Erimilson Silva
    -- 12/12/2022
*/

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Tip_Chave;

typedef struct //Registro
{
    Tip_Chave chave;
}Reg;

typedef struct no
{
    Reg cadastro;
    struct no *esquerda;
    struct no *direita;
}No;

typedef struct // Árvore Binária
{
    No *raiz;
}ArvB;

ArvB *initArvB()
{
    ArvB *arv = malloc(sizeof(ArvB));

    arv->raiz = NULL;

    return arv;
}

No *criarNo(Reg cad)
{
    No *no = malloc(sizeof(No));

    no->cadastro.chave = cad.chave;

    no->direita = NULL;
    no->esquerda = NULL;

    return no;
}

int arvoreVazia(ArvB *no)
{
    return (no->raiz == NULL);
}

void addEsquerda(No *no, Reg cad)
{
    if(no->esquerda == NULL)
    {
        No *novo = criarNo(cad);
        novo->esquerda = novo;
    }
    else
    {
        if(cad.chave < no->esquerda->cadastro.chave);
        {
            addEsquerda(no->esquerda, cad);
        }
        if(cad.chave > no->esquerda->cadastro.chave)
        {
            addDireita(no->esquerda, cad);
        }
    }
}

void addDireita(No *no, Reg cad)
{
    if(no->direita == NULL)
    {
        No *novo = criarNo(cad);
        novo->direita = novo;
    }
    else
    {
        if(cad.chave > no->direita->cadastro.chave)
        {
            addDireita(no->direita, cad);
        }
        if(cad.chave < no->direita->cadastro.chave);
        {
            addEsquerda(no->direita, cad);
        }
    }
}

void imprimir(No *no)
{
    if(no == NULL)
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        
    }
}

void AddArvore(ArvB *arv, Reg cad )
{
    if(arvoreVazia(arv))
    {
        No *novo = criarNo(cad);
        arv->raiz = novo;
    }
    else
    {
        if(cad.chave < arv->raiz->cadastro.chave)
        {
            addEsquerda(arv->raiz, cad);
        }
        if(cad.chave > arv->raiz->cadastro.chave)
        {
            addDireita(arv->raiz, cad);
        }
    }
}

int main()
{

    return False;
}