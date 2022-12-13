/*
    -- Implementação de Árvore de Buscar Binária
    -- Metódos:
        Inserção,
        Impressão em Ordenada,
        Remoção.
    -- Autor: Erimilson Silva
    -- 16/12/2022
*/
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Tip_Chave;

typedef struct // Registros 
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
    struct no *dereita, *esquerda;    
}No;

No *initLista()
{
    No *arv = malloc(sizeof(No));

    arv->cadastro.chave = 0;
    
    arv->esquerda = NULL;
    arv->dereita = NULL;

    return arv;
}

No *criarNo(Reg cad)
{
    No *no = malloc (sizeof(No));

    no->cadastro.chave = cad.chave;
    no->cadastro.nome = cad.nome;
    no->cadastro.idade = cad.idade;
    no->cadastro.matricula = cad.matricula;
    no->cadastro.curso = cad.curso;
    no->cadastro.periodo = cad.periodo;

    no->esquerda = NULL;
    no->dereita = NULL;

    return no;
}

No *inserir(No *raiz, Reg cad)
{
    if(raiz == NULL)
    {
        criarNo(cad);
    }
    else
    {
        if(cad.chave < raiz->cadastro.chave)
        {
            raiz->esquerda = inserir(raiz->esquerda, cad);
        }
        if(cad.chave > raiz->cadastro.chave)
        {
            raiz->dereita = inserir(raiz->dereita, cad);
        }
        return raiz;
    }
}

No *buscar(No *raiz, Reg cad)
{
    if(raiz)
    {
        if(cad.chave == raiz->cadastro.chave)
        {
            return raiz;
        }
        else if (cad.chave < raiz->cadastro.chave)
        {
            return buscar(raiz->esquerda, cad);
        }
        else
        {
            return buscar(raiz->dereita,cad);
        }
        return NULL;        
    }
}

void imprimir(No *raiz)
{
    if(raiz)
    {
        imprimir(raiz->esquerda);
        printf("\n\n\t- Registro do Aluno - %2d\t\n",raiz->cadastro.chave);
        printf("\nNome: %s",raiz->cadastro.nome);
        printf("\nIdade: %2d",raiz->cadastro.idade);
        printf("\nMatricula: %s",raiz->cadastro.matricula);
        printf("\nCurso: %2d",raiz->cadastro.curso);
        printf("\nPeriodo: %2d",raiz->cadastro.periodo);  
        imprimir(raiz->dereita);
    }
}

int main()
{
    int i, opc;
    Reg ch, r1, r2, r3, r4, r5;
    No *pesquisar, *arv = NULL;

    do
    {
        printf("\n\n\t-----MENU-----");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - PESQUISAR");
        printf("\n\t 4 - REMOVER");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");

            r1.chave = 50;
            r1.nome = "Erimilson Silva";
            r1.idade = 23;
            r1.matricula = "2022-AEB";
            r1.curso = 3;
            r1.periodo = 2;

            r2.chave = 20;
            r2.nome = "Lídia Silva";
            r2.idade = 21;
            r2.matricula = "2022-AEB";
            r2.curso = 2;
            r2.periodo = 4;

            r3.chave = 21;
            r3.nome = "Kelly Ferraz";
            r3.idade = 21;
            r3.matricula = "2022-AEB";
            r3.curso = 1;
            r3.periodo = 3;
            
            r4.chave = 18;
            r4.nome = "Milena Almeida";
            r4.idade = 25;
            r4.matricula = "2020-AEB";
            r4.curso = 4;
            r4.periodo = 6;
            
            r5.chave = 23;
            r5.nome = "Amanda Silva";
            r5.idade = 25;
            r5.matricula = "2020-AEB";
            r5.curso = 5;
            r5.periodo = 3;

            arv = inserir(arv,r1);
            arv = inserir(arv,r2);
            arv = inserir(arv,r3);
            arv = inserir(arv,r4);
            arv = inserir(arv,r5);
                        
            break;

        case 2:
            // Imprimir Registro
            imprimir(arv);
            break;
        
        case 3:
            // Buscando código de Regsitros 
            printf("\n\tDigite o Chave do Registro: ");
            scanf("%d",&ch);

            pesquisar = buscar(arv,ch);

            if(pesquisar)
            {
                printf("\n\t Resgitro Encontrado: %d",pesquisar->cadastro.chave);
                printf("\nInformações: ");
                printf("\nNome: %s",pesquisar->cadastro.nome);
                printf("\nIdade: %2d",pesquisar->cadastro.idade);
                printf("\nMatricula: %s",pesquisar->cadastro.matricula);
                printf("\nCurso: %2d",pesquisar->cadastro.curso);
                printf("\nPeriodo: %2d",pesquisar->cadastro.periodo);  

            }
            else
            {
                printf("\n\t Nenhum Reggistro Encontrado! \n");
            }
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
