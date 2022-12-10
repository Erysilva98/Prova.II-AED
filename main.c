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

void removeLista(cLista **ref_lista)
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

void removerLista(cLista **ref_lista)
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

int main()
{
    int opc, anterior, cod;
    No *removido, *buscando;
    Reg r1, r2, r3, r4, r5;
    cLista **ch, *lista = iniciarLista();

    do
    {
        printf("\n\t MENU ");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - REMOVER");
        printf("\n\t 4 - LIMPAR");
        printf("\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");
            r1.chave = 01;
            r1.nome = "Erimilson Silva";
            r1.idade = 23;
            r1.matricula = "2022-AEB";
            r1.curso = 3;
            r1.periodo = 2;

            r2.chave = 07;
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
            printf("\n\t Informe a Chave do Registro a ser Removido da Lista: ");
            scanf("%d",&cod);

            // removerLista(ch);
           
            break;

        case 4:
            printf("\n\tLimpando os Registros \n");
            // limpaLista(lista);
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
