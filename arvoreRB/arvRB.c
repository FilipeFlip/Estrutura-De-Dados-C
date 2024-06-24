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

void cria_NO(ArvRB **NO, int valor) {
    *NO = (ArvRB*)malloc(sizeof(ArvRB));
    if (*NO != NULL) {
        (*NO)->info = valor;
        (*NO)->esq = NULL;
        (*NO)->dir = NULL;
        (*NO)->dir = RED;
    }
}

void insereArvRB(ArvRB **NO, int valor) {
    if (*NO == NULL) {
        cria_NO(NO, valor);
    } else {
        if (valor < (*NO)->info) {
            insereArvRB(&(*NO)->esq, valor);
        } else if (valor > (*NO)->info) {
            insereArvRB(&(*NO)->dir, valor);
        }
    }
    if(ver_cor((*NO)->dir) == RED && ver_cor((*NO)->esq) == BLACK)
        NO = rotaciona_esq(NO);

    if(ver_cor((*NO)->esq) == RED && ver_cor((*NO)->esq->esq) == RED)
        NO = rotaciona_dir(NO);
    
    if(ver_cor((*NO)->esq) == RED && ver_cor((*NO)->dir) == RED)
        troca_cor(NO);
}

ArvRB* rotaciona_esq(ArvRB *NO){
    ArvRB *nova = NO->dir;

    NO->dir = nova->esq;
    nova->esq = NO;
    nova->cor = NO->cor;
    NO->cor = RED;

    return nova;
}

ArvRB* rotaciona_dir(ArvRB *NO){
    ArvRB *nova = NO->esq;

    NO->esq = nova->dir;
    nova->dir = NO;
    nova->cor = NO->cor;
    NO->cor = RED;

    return nova;
}

void troca_cor(ArvRB *NO){
    NO->cor = !NO->cor;
    if(NO->esq != NULL)
        NO->esq->cor = !NO->esq->cor;
    if(NO->dir != NULL)
        NO->dir->cor = !NO->dir->cor;
}

int ver_cor(ArvRB *NO){
    ArvRB *ver = NO->cor;
    if(NO == NULL)
        ver = BLACK;
    else
        ver = NO->cor;
    return ver;
}

ArvRB* moveRedEsq(ArvRB *NO){
    troca_cor(NO);

    if(ver_cor(NO->dir->esq) == RED){
        NO->dir = rotaciona_dir(NO->dir);
        NO = rotaciona_esq(NO);
        troca_cor(NO);
    }
    return NO;
}

ArvRB* moveRedDir(ArvRB *NO){
    troca_cor(NO);

    if(ver_cor(NO->esq->esq) == RED){
        NO = rotaciona_dir(NO);
        troca_cor(NO);
    }
}

ArvRB* balancear(ArvRB *NO){
    if(ver_cor(NO->dir) == RED);
        NO = rotaciona_esq(NO);

    if((NO->esq) != NULL && ver_cor(NO->dir) == RED && ver_cor(NO->esq->esq) == RED)
        NO = rotaciona_dir(NO);

    if(ver_cor(NO->esq) == RED && ver_cor(NO->dir) == RED)
        troca_cor(NO);
}

int busca_NO(ArvRB *NO, int valor){
    int  achou;

    if((NO) != NULL){
        if((NO->info) == valor)
            achou = 1;
        if((NO->info) > valor)
            busca_NO((NO->esq), valor);
        if((NO->info) < valor)
            busca_NO((NO->dir), valor);
    }

    else
        achou = 0;

    return achou;
}

ArvRB* remove_ArvRB(ArvRB *NO, int valor){
    if(busca_NO(NO, valor)){
        ArvRB* NO = NO;

        NO = remove_NO (NO, valor);

        if(NO != NULL)
            (NO)->cor = BLACK;
    }
}

ArvRB* remove_NO(ArvRB *NO, int valor){
    if(valor < NO->info){
        if(ver_cor(NO->esq) == BLACK && ver_cor(NO->esq->esq) == BLACK)
            NO = moveRedDir(NO);
    }
    else{
        if(ver_cor(NO->esq) == RED)
            NO = rotaciona_dir(NO);
        
        if(valor == (NO->info) && (NO->dir == NULL))
            free(NO);

        if(ver_cor(NO->dir) == BLACK && ver_cor(NO->dir->esq) == BLACK)
            NO = moveRedDir(NO);

        if(valor == NO->info){
            ArvRB* x = busca_menor(NO->dir);
            NO->info = x->info;
            NO->dir = remove_menor(NO->dir);
        }
        else{
            NO->dir = remove_NO(NO->dir, valor);
        }
    }
}

ArvRB* remove_menor(ArvRB *NO){
    if(NO->esq == NULL)
        free(NO);
    if(ver_cor(NO->esq) == BLACK && ver_cor(NO->esq->esq) == BLACK)

    NO->esq = remove_menor(NO->esq);
    return balancear(NO);
}

ArvRB* busca_menor(ArvRB *NO){
    ArvRB *no1 = NO;
    ArvRB *no2 = NO->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}