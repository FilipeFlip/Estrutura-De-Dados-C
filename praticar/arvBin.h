#ifndef ARVBIN_H
#define ARVBIN_H

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

//insere valores aleatórios na info da raiz
void insereValor(ArvBin **raiz);

//Busca valores em uma arvore binaria com o metodo inorder
void busca_inorder(ArvBin *raiz);

#endif // ARVBIN_H