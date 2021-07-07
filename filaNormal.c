#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "filaNormal.h"
#include "filaPrioridade.h"

void criafila(struct fila *f, int cap){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->cap = cap;
    f->valores = (int *) malloc (cap * sizeof(int));
}

void inserir_elemento(struct fila *f, int elemento){
    f->valores[f->fim] = elemento;
    f->fim = (f->fim+1)%f->cap;
    f->total = f->total+1;
}

int retirar_elemento(struct fila *f){
    int elemento = f->valores[f->inicio];
    f->inicio = (f->inicio + 1)%f->cap;
    f->total = f->total-1;
    return elemento;
}

int isEmpty(struct fila *f){ // Verifica se o total de inteiros da fila � igual a 0
    return(f->total == 0);
}

int isFull(struct fila *f){
    return(f->total == f->cap); // verifica se o valor total de inteiros da fila � igual a capacidade da mesma
}

int Fila_Tamanho(struct fila *f){
    return(f->total); // Est� retornando o valor total da fila
}

void mostra_elementos(struct fila *f){
    if(isEmpty(f)){
        printf("Fila Vazia!\n");
    }else{
       for(int i=f->inicio;i<f->total;i++){ //Se i for igual ao come�o da fila e menor que o total da fila vai mostrar os valores
            printf("%d", f->valores[i]);
            break;
       }
    }
}
