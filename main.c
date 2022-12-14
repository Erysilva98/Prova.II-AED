/*
    -- Implementação de um Lista para o Refeitório
    -- Metódos:
        Iniciar Lista, 
        Adicionar Registro, 
        Remover Registro, 
        Reinciar Lista, 
        Imprimir Lista.
    -- Autor: Erimilson Silva
    -- 16/12/2022
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

typedef int Tipo_indentificador;

struct Registro
{
    Tipo_indentificador identificador;
    /*
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
    */
};

typedef struct Registro Reg;

struct Fila_dia
{
    Reg alunos;
    int dia;
    int mes;
    int ano;
    int qtd_alunos;
    struct Fila_dia *proximo;
    struct Fila_dia *anterior;
};

typedef struct Fila_dia No;

struct Colec_filas
{
    No filas;
    No *inicio;
    No *final;
    size_t qtd_filas;
};

typedef struct Colec_filas Ifpe;

No *criarNo(No reg)
{
    No *no = malloc(sizeof(No));

    no->alunos.identificador = 0;

    no->dia = 0;
    no->mes = 0;
    no->ano = 0;

    no->qtd_alunos = 0;

    no->proximo = no;
    no->anterior = no;

    return no;
}

Ifpe *iniciar()
{
    Ifpe *novo = malloc(sizeof(Ifpe));

    novo->filas.alunos.identificador = 0;

    novo->inicio = NULL;
    novo->final = NULL;

    novo->qtd_filas = 0;

    return novo;
}

int isVazia(Ifpe *refeit)
{
    return (refeit->qtd_filas == 0);
}

void addLista(Ifpe *refeit, No reg)
{
    No *novo = criarNo(reg);

    novo->proximo = refeit->inicio;

    if(isVazia(refeit))
    {
        refeit->inicio = novo;
        refeit->final = novo;
        printf("\nSucesso! \n");
    }
    else
    {
        novo->proximo = refeit->inicio;
        refeit->inicio->anterior = novo;
        refeit->inicio = novo;
        // Lista Circula
        novo->anterior - refeit->final;
        refeit->final->proximo = novo;
        printf("\n Sucesso! \n");
    }
    refeit->qtd_filas++;
}

void imprimir(Ifpe *refeit)
{
    if(isVazia(refeit))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = refeit->inicio;
        printf("\n\t*** Registros ***\n");

        do
        {
            printf("\n\t - DATAS - %2d / %2d / %2d ",novo->dia,novo->mes,novo->ano);
            printf("\n\t- Registro do Aluno - %2d \t\n",novo->alunos.identificador);
        } while (novo != refeit->inicio);
        
    }
}

int main()
{
    No r1, r2, r3, r4, r5;
    Ifpe *refeit = iniciar();

    int opc, nfilas;

    do
    {
        printf("\n\n\t-----MENU-----");
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
                printf("\n\n\tRefeitorio do IFPE \n");

                r1.dia = 16;
                r1.mes = 12;
                r1.ano = 2022;

                r1.alunos.identificador = 10;
                addLista(refeit,r1);
                break;

            case 2:
                imprimir(refeit);

                break;

            default:
                if (opc != 0)
                {
                    printf("\n\t Opcao Invalida! \n");
                }  
        }
        
    } while (opc != 0);
    

    return False;
}