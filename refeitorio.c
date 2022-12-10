#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cursos
#define INFORMATICA 0
#define AGROINDUSTRIA 1
#define AGROPECUARIA 2
#define ENG_SOFTWARE 3
#define ENFERMAGEM 4
#define MUSICA 5

typedef int Tipo_indentificador;

typedef struct
{
    Tipo_indentificador identificador;
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
}Reg;

typedef struct
{
    int dia;
    int mes;
    int ano;
    int qtd_alunos;
    Reg alunos;
}Fila_d;

typedef struct 
{
    char *qtd_filas;
    Fila_d filas;
}Cole_f;

typedef struct no
{
    Cole_f p;
    struct no *prox;    
}No;

// Impressão de Dados
void list_Reg(Reg reg)
{
    printf("\n\n\t- Registro do Aluno -\t\n");
    printf("\n\tIdentificador: %d",reg.identificador);
    printf("\n\tNome: %s",reg.nome);
    printf("\n\tMatricula: %s",reg.matricula);
    printf("\n\tIdade: %d",reg.idade);
    printf("\n\tPeriodo: %d",reg.periodo);
    printf("\n\tCurso: %d",reg.curso);
}

void listF_dia(Fila_d d)
{
    printf("\n\t- Fila do Dia - \t\n");
    printf("\n\t%d/%d/%d", d.dia, d.mes, d.ano);
    printf("\n\n\tNumero de Alunos %d",d.qtd_alunos);
    list_Reg(d.alunos);
}

void listC_fila(Cole_f c)
{
    printf("\n\t- Colecao de Filas - \t\n");
    printf("\n\tNumero de Filas: %s", c.qtd_filas);
    listF_dia(c.filas);
}

// Leitura de Dados
Reg addReg1_A()
{
    Reg reg1;

    reg1.curso = 1;
    reg1.idade = 22;
    reg1.identificador = 01;
    reg1.matricula = "MT202121";
    reg1.nome = "Erimilson";
    reg1.periodo = 2;

    printf("\n\t- Registrados 1 Adicionado - ");

    return reg1;
}

Reg addReg2_A()
{
    Reg reg2;

    reg2.curso = 2;
    reg2.idade = 22;
    reg2.identificador = 01;
    reg2.matricula = "MT202121";
    reg2.nome = "Erimilson";
    reg2.periodo = 2;

    printf("\n\t- Registrados 2 Adicionado - ");

    return reg2;
}

Fila_d addFila_d()
{
    Fila_d d1, d2;
    printf("\n\t - Fila do Dia - \n");
    printf("\nDigite a Data no formato dd mm aaaa: ");
    //scanf("%d%d%d", &d1.dia, &d1.mes, &d1.ano);
    printf("\nDigite a Numero de Alunos: ");
    //scanf("%d", &d.qtd_alunos);
    d1.alunos = addReg1_A();
    d2.alunos = addReg2_A();
    getchar();

    return d1, d2;
}

Cole_f addCole_f()
{
    Cole_f c;
    printf("\n\t - Colecao de Filas -\n");
    printf("\nNumero de Filas: ");
    fgets(c.qtd_filas, 19, stdin);
    c.filas = addFila_d();
    return c;
}

void pushFila(No **fila, Cole_f c_filas)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->p = c_filas;
        novo->prox = NULL;
        if(*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            while (aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else
    {
        printf("\nErro ao Alocar Memoria.\n");
    }
}

No* popFila(No **fila)
{
    No *remover = NULL;

    if(*fila)
    {
        remover = *fila;
        *fila = remover->prox;
    }
    else
    {
        printf("\nFila Vazia\n");
    }

    return remover;
}

void imprimir(No *fila)
{
    printf("\n---------------- IFPE - FILAS DO REFEITORIO ----------------\n");
    while(fila)
    {
        listC_fila(fila->p);
        fila = fila->prox;
        if(fila)
        {
            printf("\n\t-------------------------\n\t");
        }
        
        printf("\n\t------ #### ------- \n");
        printf("\n\tDesenvolvedor: Erimilson Silva\n\t");
    }
}

int main()
{
    No *r, *fila = NULL;
    int opc;
    Cole_f p;
    Reg Aluno1, Aluno2;

    do{
        printf("\n 0 - Sair \n");
        printf("\n 1 - Inserir \n");
        printf("\n 2 - Remover \n");
        printf("\n 3 - Imprimir \n");
        printf("\nDigite: ");
        scanf("%d", &opc);
        getchar();

        switch (opc)
        {
        case 1:
            p = addCole_f();
            pushFila(&fila, p);
            break;
        
        case 2:
            r = popFila(&fila);
            if(r)
            {
                listC_fila(r->p);
                free(r);
            }
            break;

        case 3:
            imprimir(fila);
            break;

        default:
            if(opc != 0)
            {
                printf("\nOpcao Invalida!\n");
            }
        }
    }
    while(opc != 0);

    return 0;
}