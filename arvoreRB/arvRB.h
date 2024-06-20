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
void cria_NO(ArvRB **raiz, int valor);

//insere valor no nó
void insereArvRB(ArvRB **raiz, int valor);

//Rotação para a esquerda
ArvRB* rotaciona_esq(ArvRB *raiz);

//Rotação para a direita
ArvRB* rotaciona_dir(ArvRB *raiz);

//troca a cor do no filho com o pai
void troca_cor(ArvRB *raiz);

//Vê a cor do nó
int ver_cor(ArvRB *raiz);

//move o nó vermelho
ArvRB* moveRedEsq(ArvRB *raiz);

ArvRB* moveRedDir(ArvRB *raiz);

// Balanceia o nó
ArvRB* balancear(ArvRB *raiz);

#endif