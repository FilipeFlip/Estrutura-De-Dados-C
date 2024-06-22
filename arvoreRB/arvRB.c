#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvRB.h"

#define RED 1 // Define as cores
#define BLACK 0


int criar_ArvRB(ArvRB *raiz, int valor){
    raiz = insereArvBin(&raiz, valor);

    if((raiz) != NULL)
        (raiz)->cor = BLACK;
}

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
            insereArvRB(&(*raiz)->esq, valor);
        } else if (valor > (*raiz)->info) {
            insereArvRB(&(*raiz)->dir, valor);
        }
    }
    if(ver_cor((*raiz)->dir) == RED && ver_cor((*raiz)->esq) == BLACK)
        raiz = rotaciona_esq(raiz);

    if(ver_cor((*raiz)->esq) == RED && ver_cor((*raiz)->esq->esq) == RED)
        raiz = rotaciona_dir(raiz);
    
    if(ver_cor((*raiz)->esq) == RED && ver_cor((*raiz)->dir) == RED)
        troca_cor(raiz);
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

ArvRB* moveRedEsq(ArvRB *raiz){
    troca_cor(raiz);

    if(ver_cor(raiz->dir->esq) == RED){
        raiz->dir = rotaciona_dir(raiz->dir);
        raiz = rotaciona_esq(raiz);
        troca_cor(raiz);
    }
    return raiz;
}

ArvRB* moveRedDir(ArvRB *raiz){
    troca_cor(raiz);

    if(ver_cor(raiz->esq->esq) == RED){
        raiz = rotaciona_dir(raiz);
        troca_cor(raiz);
    }
}

ArvRB* balancear(ArvRB *raiz){
    if(ver_cor(raiz->dir) == RED);
        raiz = rotaciona_esq(raiz);

    if((raiz->esq) != NULL && ver_cor(raiz->dir) == RED && ver_cor(raiz->esq->esq) == RED)
        raiz = rotaciona_dir(raiz);

    if(ver_cor(raiz->esq) == RED && ver_cor(raiz->dir) == RED)
        troca_cor(raiz);
}

int busca_NO(ArvRB *raiz, int valor){
    int  achou;

    if((raiz) != NULL){
        if((raiz->info) == valor)
            achou = 1;
        if((raiz->info) > valor)
            busca_NO((raiz->esq), valor);
        if((raiz->info) < valor)
            busca_NO((raiz->dir), valor);
    }

    else
        achou = 0;

    return achou;
}

ArvRB* remove_ArvRB(ArvRB *raiz, int valor){
    if(busca_NO(raiz, valor)){
        ArvRB* NO = raiz;

        NO = remove_NO (raiz, valor);

        if(raiz != NULL)
            (raiz)->cor = BLACK;
    }
}

ArvRB* remove_NO(ArvRB *raiz, int valor){
    if(valor < raiz->info){
        if(ver_cor(raiz->esq) == BLACK && ver_cor(raiz->esq->esq) == BLACK)
            raiz = moveRedDir(raiz);
    }
    else{
        if(ver_cor(raiz->esq) == RED)
            raiz = rotaciona_dir(raiz);
        
        if(valor == (raiz->info) && (raiz->dir == NULL))
            free(raiz);

        if(ver_cor(raiz->dir) == BLACK && ver_cor(raiz->dir->esq) == BLACK)
            raiz = moveRedDir(raiz);

        if(valor == raiz->info){
            ArvRB* x = busca_menor(raiz->dir);
            raiz->info = x->info;
            raiz->dir = remove_menor(raiz->dir);
        }
        else{
            raiz->dir = remove_NO(raiz->dir, valor);
        }
    }
}

ArvRB* remove_menor(ArvRB *raiz){
    if(raiz->esq == NULL)
        free(raiz);
    if(ver_cor(raiz->esq) == BLACK && ver_cor(raiz->esq->esq) == BLACK)

    raiz->esq = remove_menor(raiz->esq);
    return balancear(raiz);
}

ArvRB* busca_menor(ArvRB *raiz){
    ArvRB *no1 = raiz;
    ArvRB *no2 = raiz->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}