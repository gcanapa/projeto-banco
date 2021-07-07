#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include "filaNormal.h"
#include "filaPrioridade.h"


struct clientes{
    char nome[30];
    int prioridade;
};

struct fila_prioridade{
    int qtd;
    struct clientes dados[MAX];
};

FilaPrio* cria_FilaPrio(){
    FilaPrio *fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_FilaPrio(FilaPrio* fp){
    free(fp);
}

int consulta_FilaPrio(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome,fp->dados[fp->qtd-1].nome);
    return 1;
}

int insere_FilaPrio(FilaPrio* fp, char *nome, int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;

    int i = fp->qtd-1;
    while(i >= 0 && fp->dados[i].prioridade >= prioridade){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }

    strcpy(fp->dados[i+1].nome,nome);
    fp->dados[i+1].prioridade = prioridade;
    fp->qtd++;
    return 1;
}

int remove_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
}

int tamanho_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}

void imprime_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return;
    int i;
    for(i=fp->qtd-1; i >=0 ; i--){
        printf("Nome: %s \tPrioridade: %d\n",fp->dados[i].nome,fp->dados[i].prioridade);
    }
}

void imprime_UltimoFilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return;
    int i;
    for(i=fp->qtd-1; i >=0 ; i--){
        printf("%s",fp->dados[i].nome);
        break;
    }
}
