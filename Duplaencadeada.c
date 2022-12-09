#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Tip_Chave;

typedef struct no
{
    Tip_Chave valor;
    struct no *proximo;
    struct no *anterior;
}No;

void pushInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;  
        novo->proximo = *lista;
        novo->anterior = NULL;

        if(*lista)
        {
            (*lista)->anterior = novo; 
        }
        *lista = novo;
        printf("\n\t Sucesso! \n");
    }
    else
    {
        printf("\nErro ao Alocar Memoria! \n");
    }    
}

void pushFim(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;
            novo->anterior = NULL;
        }
        else
        {
            aux = *lista;
            while (aux->proximo)
            {
               aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
        printf("\n\t Sucesso! \n");
    }
    else
    {
        printf("\nErro ao Alocar Memoria! \n");
    }
}

void pushMeio(No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        
        // é o primeiro?
        if(*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;

            while (aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;

            if(aux->proximo)
            {
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
        printf("\n\t Sucesso! \n");
    }
    else
    {
        printf("\nErro ao Alocar Memoria! \n");
    }
}

void pushOrdenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        // a lista está vazia?
        if(*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }

        // é o menor?
        else if(novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;

            if(aux->proximo)
            {
                aux->proximo->anterior =  novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
            
        }
        printf("\n\t Sucesso! \n");
    }
    else
    {
        printf("\nErro ao Alocar Memoria! \n");
    }
}

No* popLista(No **lista, int num)
{
    No *aux, *popLista = NULL;

    if(*lista)
    {
        if( (*lista)->valor == num )
        {
            popLista = *lista;
            *lista = popLista->proximo;
            if(*lista)
            {
                (*lista)->anterior = NULL;
            }
        }
        else
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num)
            {
                aux = aux->proximo;

                if(aux->proximo)
                {
                    popLista = aux->proximo;
                    aux->proximo = popLista->proximo;

                    if(aux->proximo)
                    {
                        aux->proximo->anterior = aux;
                    }
                }
            } 
        }
    }
    return popLista;
}

No* buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if(aux)
    {
        no = aux;
    }
    return no; 
}

void imprimir(No *no)
{
    printf("\n\t Lista \n");
    while (no)
    {
        printf("%d ",no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

No* ultimo(No **lista)
{
    No *aux = *lista;
    while (aux->proximo)
    {
        aux = aux->proximo;
    }
    return aux;
}

void imprimirInverso(No *no)
{
    printf("\n\t Lista \n");
    while (no)
    {
        printf("%d ",no->valor);
        no = no->anterior;
    }
    printf("\n\n");
    
}

int main()
{
    int opc, valor, anterior;
    No *removido, *buscando, *lista = NULL;

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
            valor = 71;
            pushFim(&lista, valor);
            valor = 100;
            pushFim(&lista, valor);
            break;
        
        case 3:
            printf("\n\n\tAdicionando Registros no Meio da Lista");
            imprimir(lista);
            printf("\n\t Informe a Referencia da Lista para Adiciona: ");
            scanf("%d",&anterior);
            
            if(anterior)
            {
                valor = 12;
                pushMeio(&lista, valor, anterior);
            }
            else
            {
                printf("\n\tErro, nenhuma Referencia! \n");
            }

            break;
        
        case 4:
            printf("\n\n\tAdicionando Registros Ordenado na Lista");
            valor = 30;
            pushOrdenado(&lista, valor);
            break;

        case 5:
            printf("\n\n\tRemovendo Registros da Lista");
            imprimir(lista);
            printf("\n\t Informe o Registro a ser Removido da Lista: ");
            scanf("%d",&valor);
            
            removido = popLista(&lista, valor);

            if(removido)
            {
                printf("\n\tRegistro Removido: %d\n",removido->valor);
                free(removido);
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

            buscando = buscar(&lista, valor);

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
            imprimirInverso(ultimo(&lista));
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