/*
    -- Implementação de um Lista Duplamente Encadeada Circular
    -- Autor: Erimilson Silva
    -- 10/12/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

//Cursos
#define INFORMATICA 0
#define AGROINDUSTRIA 1
#define AGROPECUARIA 2
#define ENG_SOFTWARE 3
#define ENFERMAGEM 4
#define MUSICA 5

typedef int Tip_Chave;

typedef struct Registro
{
    Tip_Chave chave;
    char *nome;
    int idade;
    char *matricula;
    int curso;
    int periodo;

}Reg;

typedef struct no
{
    Reg cadastro;
    struct no *proximo; 
    struct no *anterior;   
}No;

typedef struct Circ_lista
{
    No *inicio;
    No *final;
    size_t tam;     // Atalho para usar long int
}cLista;

No *criarNo(Reg cad)
{
    No *no = malloc (sizeof(No));

    no->cadastro.chave = cad.chave;
    no->cadastro.nome = cad.nome;
    no->cadastro.idade = cad.idade;
    no->cadastro.matricula = cad.matricula;
    no->cadastro.curso = cad.curso;
    no->cadastro.periodo = cad.periodo;
    
    no->proximo = no;
    no->anterior = no;

    return no;
}

cLista *iniciarLista()
{
    cLista *lista = malloc(sizeof(cLista));

    lista->inicio = NULL;
    lista->final = NULL;
    lista->tam = 0;

    return lista;
}

int isVazia(cLista *lista)
{
    return (lista->tam == 0);
}

void addLista(cLista *lista, Reg cad)
{
    No *novo = criarNo(cad);
    novo->proximo = lista->inicio;

    if(isVazia(lista))      // Se a Lista está Vazia
    {
        lista->inicio = novo;
        lista->final = novo;
        printf("\n\tSucesso \n");
    }
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        // Circulo
        novo->anterior = lista->final;
        lista->final->proximo = novo;
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
        No *novo = lista->inicio;
        printf("\n\t    Registros \n");
        do
        {
            printf("\n\n\t- Registro do Aluno -\t\n");
            printf("\n\tChave: %2d",novo->cadastro.chave);
            printf("\n\tNome: %s",novo->cadastro.nome);
            printf("\n\tIdade: %2d",novo->cadastro.idade);
            printf("\n\tMatricula: %s",novo->cadastro.matricula);
            printf("\n\tCurso: %2d",novo->cadastro.curso);
            printf("\n\tPeriodo: %2d",novo->cadastro.periodo);          
            novo = novo->proximo;
        }
        while(novo != lista->inicio);
    }
    printf("\n\n\tNumero de Registros: %lu\n\n",lista->tam);
}

int removeLista(cLista *lista, int ch)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *aux, *prox;

        if(lista->inicio)
        {
            aux = lista->inicio;
            prox = aux->proximo;
            while (prox != lista->inicio)
            {
                if(prox->cadastro.chave == ch)
                {
                    aux->proximo = prox->proximo;
                    free(prox);
                    lista->tam--;
                    printf("\n\tSucesso! \n");
                    return True;
                }
                else
                {
                    aux = prox;
                    prox = prox->proximo;
                }
            }
            if(prox->cadastro.chave == ch)
            {
                if(aux == prox)
                {
                    lista->inicio = NULL;
                }
                else
                {
                    aux->proximo = prox->proximo;
                    lista->inicio = prox->proximo;
                }
                free(prox);
                lista->tam--;
                printf("\n\tSucesso! \n");
                return True;
            }                
        }
    }
    printf("\n\tRegistro não Encontrado! \n");
    return False;
}

void resetaNo(cLista *lista)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = lista->inicio;
        printf("\n\t    Registros \n");
        do
        {
            novo->cadastro.chave = -1;
            novo->cadastro.nome = NULL;
            novo->cadastro.idade = -1;
            novo->cadastro.matricula = NULL;
            novo->cadastro.curso = -1;
            novo->cadastro.periodo = -1;
        }
        while(novo != lista->inicio);
        novo->anterior = NULL;
        novo->proximo = NULL;
        lista->tam = 0;
    }
    printf("\n\n\tRegistros: %lu\n\n",lista->tam);
    printf("\n\tSucesso Registros Deletados! ");
}

int main()
{
    int opc, anterior, ch;
    No *removido, *buscando;
    Reg r1, r2, r3, r4, r5;
    cLista *lista = iniciarLista();

    do
    {
        printf("\n\t MENU ");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - REMOVER");
        printf("\n\t 4 - LIMPAR");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");
            r1.chave = 1;
            r1.nome = "Erimilson Silva";
            r1.idade = 23;
            r1.matricula = "2022-AEB";
            r1.curso = 3;
            r1.periodo = 2;

            r2.chave = 7;
            r2.nome = "Lídia Silva";
            r2.idade = 21;
            r2.matricula = "2022-AEB";
            r2.curso = 2;
            r2.periodo = 4;

            r3.chave = 03;
            r3.nome = "Kelly Ferraz";
            r3.idade = 21;
            r3.matricula = "2022-AEB";
            r3.curso = 1;
            r3.periodo = 3;

            addLista(lista,r1);
            addLista(lista,r2);
            addLista(lista,r3);
            break;

        case 2:
            // Metodo de Imprimir
            imprimir(lista);
            break;
        
        case 3:
            printf("\n\n\tRemovendo Registros da Lista");
            printf("\n\n\t A Chave a ser Removido da Lista = 3 ");    
            ch = 3;
            removeLista(lista,ch); 
            break;

        case 4:
            printf("\n\tLimpando os Registros \n");
            resetaNo(lista);
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
