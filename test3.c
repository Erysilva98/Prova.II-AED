/*
            Aula 266: Como imprimir uma Árvore Binária de Busca?

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Tip_Chave;

typedef struct 
{
    Tip_Chave chave;
}Reg;

typedef struct no{
    Reg valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, Reg num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num.chave < raiz->valor.chave)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;
    int opcao;
    Reg r1, r2, r3, r4, r5;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            r1.chave = 10;
            r1.chave = 20;
            r3.chave = 5;
            r4.chave = 1;
            r5.chave = 8;

            raiz = inserir_versao_1(raiz, r1);
            raiz = inserir_versao_1(raiz, r2);
            raiz = inserir_versao_1(raiz, r3);
            raiz = inserir_versao_1(raiz, r4);
            raiz = inserir_versao_1(raiz, r5);

            break;
        case 2:
            printf("\n\tPrimeira impresao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impresao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}