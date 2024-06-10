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

int main() {
    ArvBin *raiz = NULL;
    srand(time(NULL));
    insereValor(&raiz);

    return 0;
}