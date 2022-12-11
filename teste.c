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

typedef struct Registro
{
    Tip_Chave chave;
    // char *nome;
    // int idade;
    // char *matricula;
    // int curso;
    // int periodo;

}Reg;

typedef struct no
{
    Reg cadastro;
    struct no *esquerda; 
    struct no *direita;   
}No;

typedef struct arvore_Binaria
{
    No *raiz;
    size_t tam;    // Determinar o tamanho da Lista
}ArvB;  // Árvore Binária

No *criarNo(Reg cad)
{
    No *no = malloc(sizeof(no));

    no->cadastro.chave = cad.chave;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

void addEsquerda(No *no, Reg cad);
void addDireita(No *no, Reg cad);

ArvB *initArvore()
{
    ArvB *arv = malloc(sizeof(ArvB));

    arv->raiz = NULL;

    return arv;
}

int isVazia(ArvB *arv)
{
    // Retorna True
    return (arv->raiz == 0);  
}

void addEsquerda(No *no, Reg cad)
{
    if(no->esquerda == NULL)
    {
        No *novo = malloc(sizeof(No));
        novo = criarNo(cad);
        no->esquerda = novo;
        printf("\n Sucesso! \n");
    }   
    else
    {
        if(cad.chave < no->esquerda->cadastro.chave)
        {
            addEsquerda(no->esquerda,cad);
        }
        if(cad.chave > no->esquerda->cadastro.chave)
        {
            addDireita(no->esquerda,cad);
        }
    }
}

void addDireita(No *no, Reg cad)
{
    if(no->direita == NULL)
    {
        No *novo = malloc(sizeof(No));
        novo = criarNo(cad);
        novo->direita = novo;
        printf("\n Sucesso! \n");
    }
    else
    {

        if(cad.chave > no->cadastro.chave)
        {
            addDireita(no->direita,cad);
        }
        if(cad.chave < no->cadastro.chave)
        {
            addEsquerda(no->direita,cad);
        }
    }
}

No *addArvore(ArvB *arv, Reg cad)
{
    if(isVazia)
    {
        No *novo = malloc(sizeof(No));
        novo = criarNo(cad);
        arv->raiz = novo;
        printf("\n Sucesso! \n");
    }
    else
    {
        if(cad.chave < arv->raiz->cadastro.chave )
        {
            addEsquerda(arv->raiz,cad);
        }
        if(cad.chave > arv->raiz->cadastro.chave )
        {
            addDireita(arv->raiz,cad);
        }
    }
}

void imprimir(No *no)
{
    if(no != NULL)
    {
        imprimir(no->esquerda); 
        printf("%d ",no->cadastro.chave); 
        imprimir(no->direita);   
    }
}

int main()
{
    int opc, ch;
    Reg r1, r2, r3, r4, r5;
    ArvB *arv = initArvore();

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
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");
            r1.chave = 10;
            // r1.nome = "Erimilson Silva";
            // r1.idade = 23;
            // r1.matricula = "2022-AEB";
            // r1.curso = 3;
            // r1.periodo = 2; 
            addArvore(arv,r1);

            r2.chave = 20;
            // r2.nome = "Lídia Silva";
            // r2.idade = 21;
            // r2.matricula = "2022-AEB";
            // r2.curso = 2;
            // r2.periodo = 4;
            addArvore(arv,r2);

            r3.chave = 15;
            // r3.nome = "Kelly Ferraz";
            // r3.idade = 21;
            // r3.matricula = "2022-AEB";
            // r3.curso = 1;
            // r3.periodo = 3; 
            addArvore(arv,r3);

            r4.chave = 25;
            // r4.nome = "Milena Almeida";
            // r4.idade = 25;
            // r4.matricula = "2020-AEB";
            // r4.curso = 4;
            // r4.periodo = 6;
            addArvore(arv,r4);

            r5.chave = 12;
            // r5.nome = "Amanda Silva";
            // r5.idade = 25;
            // r5.matricula = "2020-AEB";
            // r5.curso = 5;
            // r5.periodo = 3;
            addArvore(arv,r5);

            break;

        case 2:
            // Imprimir Registro
            imprimir(arv->raiz);
            break;

        case 3:
            // Remover Registro da Lista
            // printf("\n\nRegistro a ser Removido da Lista - %s\n",r3.nome);    
            // ch = 3;
            // removeArvore(arv,ch); 
            // printf("\n\nRegistro a ser Removido da Lista - %s\n",r4.nome);    
            // ch = 4;
            // removeArvore(arv,ch);
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