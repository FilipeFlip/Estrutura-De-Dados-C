#ifndef ARVRB_H
#define ARVRB_H

//definição da arvore
typedef struct ArvRB{
    int info;
    struct ArvRB *esq;
    struct ArvRB *dir;
    int cor;
} ArvRB;

//Cria a raiz da Arvore binaria
int criar_ArvRB(ArvRB* raiz,int valor);

//Aloca espaço na memória para criar o nó da arvore
void cria_NO(ArvRB **NO, int valor);

//insere valor no nó
void insereArvRB(ArvRB **NO, int valor);

//Rotação para a esquerda
ArvRB* rotaciona_esq(ArvRB *NO);

//Rotação para a direita
ArvRB* rotaciona_dir(ArvRB *NO);

//troca a cor do no filho com o pai
void troca_cor(ArvRB *NO);

//Vê a cor do nó
int ver_cor(ArvRB *NO);

//move o nó vermelho
ArvRB* moveRedEsq(ArvRB *NO);

ArvRB* moveRedDir(ArvRB *NO);

// Balanceia o nó
ArvRB* balancear(ArvRB *NO);

//apaga a árvore quando não tem manis nenhum nó
ArvRB* remove_ArvRB(ArvRB *NO, int valor);

// remove um nó
ArvRB* remove_NO(ArvRB *NO, int valor);

// remove o menor nó
ArvRB* remove_menor(ArvRB *NO);

//busca o menor nó
ArvRB* busca_menor(ArvRB *NO);

#endif