#ifndef PRATICA_H
#define PRATICA_H

//Definicao da arvore
typedef struct ArvBin{
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} ArvBin;

//Aloca espaço na memoria para a cração da arvore
void cria_NO(ArvBin **raiz, int valor);

//insere um valor novo na Arvore
void insereArvBin(ArvBin **raiz, int valor);

//insere valores aleatórios na info
void insereValor(ArvBin **raiz);

#endif // PRATICA_H