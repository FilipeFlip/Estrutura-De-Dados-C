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
        (*raiz)->dir = RED;
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
    ArvRB *nova = raiz->dir;

    raiz->dir = nova->esq;
    nova->esq = raiz;
    nova->cor = raiz->cor;
    raiz->cor = RED;

    return nova;
}

ArvRB* rotaciona_dir(ArvRB *raiz){
    ArvRB *nova = raiz->esq;

    raiz->esq = nova->dir;
    nova->dir = raiz;
    nova->cor = raiz->cor;
    raiz->cor = RED;

    return nova;
}

void troca_cor(ArvRB *raiz){
    raiz->cor = !raiz->cor;
    if(raiz->esq != NULL)
        raiz->esq->cor = !raiz->esq->cor;
    if(raiz->dir != NULL)
        raiz->dir->cor = !raiz->dir->cor;
}

int ver_cor(ArvRB *raiz){
    ArvRB *ver = raiz->cor;
    if(raiz == NULL)
        ver = BLACK;
    else
        ver = raiz->cor;
    return ver;
}

