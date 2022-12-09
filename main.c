/*
    -- Implementação de um Lista Duplamente Encadeada Circular
    -- Autor: Erimilson Silva
    -- 10/12/2022
*/
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct no
{
    int chave;
    struct no *proximo;
    struct no *anterior;
}No;

typedef struct Circ_lista
{
    No *inicio;
    No *final;
    size_t tam;     // Atalho para usar long int
}cLista;


No *criarNo(int ch)
{
    No *no = malloc (sizeof(No));

    no->chave = ch;
    no->proximo = no;
    no->anterior = no;

    return no;
}

cLista *initLista()
{
    cLista *lista = malloc(sizeof(cLista));

    lista->inicio = NULL;
    lista->final = NULL;
    lista->tam = 0;

    return lista;
}

void popLista(cLista **ref_lista)
{
    cLista *lista = *ref_lista;
    
    No *p = lista->inicio;
    No *aux = NULL;

    while(p != lista->final)
    {
        aux = p;
        p = p->proximo;
        free(aux);
    }
    free(p);
    free(lista);
    *ref_lista = NULL;
}

int isVazia(cLista *lista)
{
    return (lista->tam == 0);
}

void pushLista(cLista *lista, int ch)
{
    No *p = criarNo(ch);
    p->proximo = lista->inicio;

    if(isVazia(lista))     // Se a Lista está vazia 
    {
        lista->inicio = p;
        lista->final = p;
        printf("\n\tSucesso \n");
    }
    else                // Se a Lista Não está Vazia
    {
        p->proximo = lista->inicio;
        lista->inicio->anterior = p;
        lista->inicio = p;
        // Circulo
        p->proximo = lista->final;
        lista->final->proximo = p;
        printf("\n\tSucesso \n");
    }
    lista->tam++;
}

void imprimir(cLista *lista)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *p = lista->inicio;
        printf("\n\tLista -> ");
        do
        {
           printf("%d ",p->chave);
           p = p->proximo;
        } while(p != lista->inicio); 
    }
    printf("\n\tTamanho: %lu\n\n",lista->tam);
}


int main()
{
    int ch1, ch2, ch3, ch4, ch5;
    int opc, anterior;
    No *removido, *buscando;
    cLista *lista = initLista();

    do
    {
        printf("\n\t MENU ");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR NO INICIO");
        printf("\n\t 2 - ADICIONAR NO FINAL");
        printf("\n\t 3 - ADICIONAR NO MEIO");
        printf("\n\t 4 - ADICIONAR ORDENADO");
        printf("\n\t 5 - REMOVER DA LISTA ");
        printf("\n\t 6 - IMPRIMIR LISTA ");
        printf("\n\t 7 - BUSCAR NA LISTA ");
        printf("\n\t 8 - IMPRIMIR LISTA INVERSA ");
        printf("\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista");
            ch1 = 7; 
            ch2 = 5; 
            ch3 = 4;
            ch4 = 2;
            ch5 = 10;
            pushLista(lista,ch1);
            pushLista(lista,ch2);
            pushLista(lista,ch3);
            pushLista(lista,ch4);
            pushLista(lista,ch5);

            break;

        case 2:
            imprimir(lista);
            break;

        default:
            if(opc != 0)
            {
                printf("\n\t Opcao Invalida! \n");
            }
        }
    }
    while (opc != 0);

    return False;
}
