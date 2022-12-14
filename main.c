/*
    -- Implementação de um Lista Circular Duplamente Encadeada 
    -- Metódos:
        Iniciar Lista, 
        Adicionar Registro, 
        Remover Registro, 
        Reinciar Lista, 
        Imprimir Lista.
    -- Autor: Erimilson Silva
    -- 10/12/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

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
    struct no *inicio;
    struct no *final;
    size_t tam;
}No;

typedef struct No cLista;

cLista *iniciarLista()
{
    No *lista = malloc(sizeof(No));

    lista->inicio = NULL;
    lista->final = NULL;
    lista->tam = 0;

    return lista;
}

No *criarNo(Reg cad)
{
    No *no = malloc(sizeof(No));

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

int isVazia(No lista)
{
    // Retorna True
    return (lista.tam == 0);   
}

void adicionarLista(No lista, Reg cad)
{

}