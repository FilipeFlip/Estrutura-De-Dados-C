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

//Busca o maior filho da esquerda
ArvBin* maior_filho(ArvBin *raiz);

// remove um no da arvore binaria
void remove_NO(ArvBin **raiz, int valor);



#endif // ARVBIN_H