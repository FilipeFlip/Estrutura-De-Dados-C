#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvBin.h"

#define VALOR_NUM 10


void cria_NO(ArvBin **raiz, int valor) {
    *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if (*raiz != NULL) {
        (*raiz)->info = valor;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }
}


void insereArvBin(ArvBin **raiz, int valor) {
    if (*raiz == NULL) {
        cria_NO(raiz, valor);
    } else {
        if (valor < (*raiz)->info) {
            insereArvBin(&(*raiz)->esq, valor);
        } else if (valor > (*raiz)->info) {
            insereArvBin(&(*raiz)->dir, valor);
        }

    }
}

void insereValor(ArvBin **raiz) {
    for (int i = 0; i < VALOR_NUM; i++) {
        int valor = rand() % 100;
        insereArvBin(raiz, valor);
    }
}


void remove_NO(ArvBin **raiz, int valor){


    if (*raiz != NULL){
        if(*raiz == valor){
            ArvBin *aux = *raiz;
            if ((*raiz)->esq && (*raiz)->dir == NULL){

                free(aux);

            }
            else if((*raiz)->esq == NULL && (*raiz)->dir != NULL){
                *raiz = (*raiz)->dir;
            }
            else if((*raiz)->esq != NULL && (*raiz)->dir == NULL){
                *raiz = (*raiz)->esq;

            }
            else{
                ArvBin* maior = maior_filho((*raiz)->esq);
                (*raiz)->info = maior->info;
                remove_NO(&(*raiz)->esq, maior->info);
            }
        }

        else if(*raiz < valor)
            remove_NO(&(*raiz)->esq, valor);
        
        else
            remove_NO(&(*raiz)->dir, valor);
    }
}

ArvBin* maior_filho(ArvBin *raiz){
    ArvBin *maior = raiz;
    if(raiz->esq->info > maior->info)
        maior = raiz->esq;
    else
        maior = raiz->dir;
    return maior;
}

void busca_inorder(ArvBin *raiz){
    if(raiz != NULL){
        busca_inorder(raiz->esq);
        printf("%d   ", raiz -> info);
        busca_inorder(raiz -> dir);
    }
}

int main() {
    ArvBin *raiz = NULL;
    srand(time(NULL));
    insereValor(&raiz);
    int valor = 10;
    remove_NO(&raiz, valor);

    return 0;
}