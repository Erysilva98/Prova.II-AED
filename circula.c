#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Tip_Chave;

struct no
{
    int valor;
    struct no *proximo;
    struct no *anterior;
};

struct listaDupla
{
    struct no *inicial;    
};

void initLista(struct listaDupla *lista)
{
    lista->inicial = NULL;
}

int isVazia(struct listaDupla *lista)
{
    return (lista->inicial == NULL);
}

void pushInicio(struct listaDupla *lista, int valor)
{
    struct no *novo = malloc(sizeof(struct no));

    novo->valor = valor;

    if(lista->inicial == NULL) // Esta vazia
    {
        novo->proximo = novo;
        novo->anterior = novo;
        lista->inicial = novo;
        printf("\n\t Sucesso! \n");
    }
    else
    {
        struct no *aux = lista->inicial;

        while (aux->proximo != lista->inicial)
        {
            aux = aux->proximo;
        }
        novo->proximo = lista->inicial;
        novo->anterior = aux;  
        aux->proximo = novo;   
        aux->anterior = novo;
        printf("\n\t Sucesso! \n");
    }
}

void imprimir(struct listaDupla *lista)
{
    struct no *aux = lista->inicial;

    printf("\n\t Lista \n");
    while (lista)
    {
        printf("%d ",aux->valor);
        aux = aux->proximo;
    }
    printf("\n\n");
}

int main()
{
    int opc, valor, anterior;
    struct listaDupla *lista;
    struct no *removido, *buscando;

    initLista(lista);

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
            valor = 9;
            pushInicio(&lista, valor);
            valor = 1;
            pushInicio(&lista, valor);
            valor = 5;
            pushInicio(&lista, valor);
            break;

        case 2:
            printf("\n\n\tAdicionando Registros no Final da Lista");
           
            break;
        
        case 3:
            printf("\n\n\tAdicionando Registros no Meio da Lista");
           
            printf("\n\t Informe a Referencia da Lista para Adiciona: ");
            scanf("%d",&anterior);
            
            if(anterior)
            {
                valor = 12;
               
            }
            else
            {
                printf("\n\tErro, nenhuma Referencia! \n");
            }

            break;
        
        case 4:
            printf("\n\n\tAdicionando Registros Ordenado na Lista");
            valor = 30;
            
            break;

        case 5:
            printf("\n\n\tRemovendo Registros da Lista");
           
            printf("\n\t Informe o Registro a ser Removido da Lista: ");
            scanf("%d",&valor);
            
           

            if(removido)
            {
                printf("\n\tRegistro Removido: ");
               
            }
            else
            {
                printf("\n\tErro, Registro Inexistente! \n");
            }
            break;

        case 6:
            imprimir(lista);
            break;;

        case 7:
            printf("\n\tInforme o Registro a ser Procurado: ");
            scanf("%d",&valor);

           

            if(buscando)
            {
                printf("\n\tRegistro Encontrado: %d\n",buscando->valor);
            }
            else
            {
                printf("\n\tRegistro nao Encontrado! \n");
            }
            break;

        case 8:
           
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