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

void busca_inorder(ArvBin *raiz){
    if(raiz != NULL){
        busca_inorder(raiz->esq);
        printf("%d   ", raiz -> info);
        busca_inorder(raiz -> dir);
    }
}

void busca_preorder(ArvBin *raiz){
    if(raiz != NULL){
        printf("%d   ", raiz -> info);
        busca_preorder(raiz->esq);
        busca_preorder(raiz -> dir);
    }
}

void busca_postorder(ArvBin *raiz){
    if(raiz != NULL){
        busca_postorder(raiz->esq);
        busca_postorder(raiz -> dir);
        printf("%d   ", raiz -> info);
    }
}

int main() {
    ArvBin *raiz = NULL;
    srand(time(NULL));
    insereValor(&raiz);
    busca_inorder(raiz);
//    busca_preorder(raiz);
//    busca_postorder(raiz);
    return 0;
}