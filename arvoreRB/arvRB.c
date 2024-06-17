#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvRB.h"

#define RED 1 // Define as cores
#define BLACK 0

void cria_NO(ArvRB **raiz, int valor) {
    *raiz = (ArvRB*)malloc(sizeof(ArvRB));
    if (*raiz != NULL) {
        (*raiz)->info = valor;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }
}

void insereArvRB(ArvRB **raiz, int valor) {
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

ArvRB* rotaciona_esq(ArvRB *raiz){
    ArvRB *B = raiz->dir;

    raiz->dir = B->esq;
    B->esq = raiz;
    B->cor = raiz->cor;
    raiz->cor = RED;

    return B;
}

ArvRB* rotaciona_dir(ArvRB *raiz){
    ArvRB *nova = raiz->esq;

    raiz->esq = nova->dir;
    nova->dir = raiz;
    nova->cor = raiz->cor;
    raiz->cor = RED;

    return nova;
}