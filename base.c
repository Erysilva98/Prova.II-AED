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

typedef struct
{
    Tip_Chave chave;
}Reg;

typedef struct no
{
    Reg cadastro;
    struct no *esquerda;
    struct no *direita;
}No;

typedef No *ArvB; // Árvore Binária

No *initArvB()
{
    No *no = malloc(sizeof(No));

    no->cadastro.chave = 0;
    
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

ArvB inserir(ArvB arv, Reg *no)
{
    No *f, *p;

    if(arv == NULL) return no;

    f = arv;
    while (f != NULL)
    {
        p = f;
        if(f->cadastro.chave > no->chave)
        {
            f = f->esquerda;
        }
        else
        {
            f = f->direita;
        }
    }
    if(p->cadastro.chave > no->chave)
    {
        p->esquerda = no;
    }
    else
    {
        p->direita = no;
    }
    return arv;
}

No *removerNo(ArvB arv)
{
    No *p, *q;
    if(arv->esquerda == NULL)
    {
        q = arv->direita;;
    }
    else
    {
        p = arv;
        q = arv->esquerda;

        while (q->direita != NULL)
        {
            p = q;
            q = q->direita;
            /*
                q é o NO anterior a ARV na ordem e-r-q
                p é o pai de q
            */
           if(p != arv)
           {
                p->direita = q->esquerda;
                q->esquerda = arv->esquerda;
           }
           q->direita = arv->direita;
        }         
    }
    free(arv);
    return q;
}

No *buscar(ArvB arv, int ch)
{
    if(arv == NULL || arv->cadastro.chave == ch )
    {
        return arv;
    }
    if(arv->cadastro.chave > ch)
    {
        return buscar(arv->esquerda,ch);
    }
    else
    {
        return buscar(arv->direita, ch);
    }
}



void imprimir(ArvB arv)
{
    if(arv != NULL)
    {
        imprimir(arv->esquerda);
        printf("%d ",arv->cadastro.chave);
        imprimir(arv->direita);
    }
}

int main()
{
    int opc, ch;
    No *arv = initArvB();
    Reg *r1, *r2, *r3, *r4, *r5;

    do
    {
        printf("\n\n\t-----MENU-----");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - REMOVER");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");
            
            r1->chave = 01;

            r2->chave = 02;

            r3->chave = 03;

            r4->chave = 04;

            r5->chave = 05;

            inserir(arv,r1); 
            inserir(arv,r2); 
            inserir(arv,r3); 
            inserir(arv,r4); 
            inserir(arv,r5); 
            
            break;

        case 2:
            // Imprimir Registro
            imprimir(arv);
            break;
        
        case 3:
            // Remover Registro da Lista
            //printf("\n\nRegistro a ser Removido da Lista - %s\n",r3.nome);    
            ch = 3;
            //removeLista(lista,ch); 
            //printf("\n\nRegistro a ser Removido da Lista - %s\n",r4.nome);    
            ch = 4;
            // removeLista(lista,ch);
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
