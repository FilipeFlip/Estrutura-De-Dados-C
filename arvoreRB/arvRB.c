#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvRB.h"

void criaArv(Arvore **raiz, int code, int ndisciplina){
    insere(raiz, code, ndisciplina);
    if((*raiz) != NULL)
        (*raiz)->Curso->cor = BLACK;
}

void insere(Arvore **raiz, int code, int ndisciplina) {
    if (*raiz == NULL) {
        cont ++;
        *raiz = cria_NO(code, ndisciplina);
    } else if (code < (*raiz)->Curso->codigo) {
        insere(&(*raiz)->esq, code, ndisciplina);
    } else if (code > (*raiz)->Curso->codigo) {
        insere(&(*raiz)->dir, code, ndisciplina);
    } else {
        printf("Codigo repetido");
    }
    *raiz = balancear(*raiz);
}

Arvore* cria_NO(int code, int ndisciplina){
    Arvore *novo_NO = (Arvore*)malloc(sizeof(Arvore));
    if (novo_NO != NULL){
        novo_NO->Curso = (Curso*)malloc(sizeof(Curso));
        if (novo_NO->Curso != NULL){
            novo_NO->Curso->codigo = code;
            novo_NO->Curso->disciplinas = ndisciplina;
            novo_NO->Curso->cor = RED;
            novo_NO->dir = NULL;
            novo_NO->esq = NULL;
        }
    }
    return novo_NO;
}

Arvore* balancear(Arvore *NO) {
    // Nó à direita é vermelho e nó à esquerda é preto
    if (cor(NO->dir) == RED && cor(NO->esq) == BLACK)
        NO = rotacionaEsquerda(NO);
    // Caso 2: Nó à esquerda é vermelho e o filho esquerdo do nó à esquerda também é vermelho
    if (cor(NO->esq) == RED && cor(NO->esq->esq) == RED)
        NO = rotacionaDireita(NO);
    // Caso 3: Ambos filhos são vermelhos
    if (cor(NO->esq) == RED && cor(NO->dir) == RED)
        trocaCor(NO);
    
    return NO;
}

int cor(Arvore *NO){
    int ver;
    if(NO == NULL)
        ver = BLACK;
    else{
        ver = NO->Curso->cor;
    }
    return ver;
}

void trocaCor(Arvore *NO){
    NO->Curso->cor = !NO->Curso->cor;
    if(NO->esq != NULL)
        NO->esq->Curso->cor = !NO->esq->Curso->cor;
    if(NO->dir != NULL)
        NO->dir->Curso->cor = !NO->dir->Curso->cor; 
}

Arvore* rotacionaDireita(Arvore *NO){
    Arvore *aux = NO->esq;
    NO->esq = aux->dir;
    aux->dir = NO;
    aux->Curso->cor = NO->Curso->cor;
    NO->Curso->cor = RED;

    return aux;
}

Arvore* rotacionaEsquerda(Arvore *NO){
    Arvore *aux = NO->dir;
    NO->dir = aux->esq;
    aux->esq = NO;
    aux->Curso->cor = NO->Curso->cor;
    NO->Curso->cor = RED;

    return aux;
}

int codigoArvore(){
    // int x = 1 + ( rand() % 1000 );
    int x;
    printf("\nCodigo do Arvore: ");
    scanf("%d", &x);
    return x;
}

void busca_inorder(Arvore *NO) {
    if (NO != NULL) {
        busca_inorder(NO->esq);
        printf("\nCodigo do Arvore: %d", NO->Curso->codigo);
        printf("\nQuantidade de disciplinas: %d", NO->Curso->disciplinas);
        printf("\nCor do NO: %s\n", NO->Curso->cor == RED ? "RED" : "BLACK");
        printf("\n-------------------------------------------------\n");
        busca_inorder(NO->dir);
    }
}

Arvore* moveRedEsquerda(Arvore *NO){
    trocaCor(NO);

    if(cor(NO->dir->esq) == RED){
        NO->dir = rotacionaDireita(NO->dir);
        NO = rotacionaEsquerda(NO);
        trocaCor(NO);
    }
    return NO;
}

Arvore* moveRedDireita(Arvore *NO){
    trocaCor(NO);

    if(cor(NO->esq->esq) == RED){
        NO = rotacionaDireita(NO);
        trocaCor(NO);
    }
    return NO;
}

int buscaNO(Arvore *NO, int code){
    int  achou;
    printf("\naqui\n");
    if((NO) != NULL){
        if((NO->Curso->codigo) == code)
            achou = 1;
        if((NO->Curso->codigo) > code)
            buscaNO((NO->esq), code);
        if((NO->Curso->codigo) < code)
            buscaNO((NO->dir), code);
    }
    else
        achou = 0;
    return achou;
}

Arvore* buscaMenor(Arvore *NO){
    Arvore *no1 = NO;
    Arvore *no2 = NO->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_Arvore(Arvore *NO, int code){
    int x = 0;
    if(buscaNO(NO, code)){
        Arvore* removido = NO;
        printf("aqui 2\n");
        removido = remove_NO(removido, code);
        if(NO != NULL)
            (NO)->Curso->cor = BLACK;
        x = 1;
    }
    return x;
}


Arvore* remove_NO(Arvore *NO, int code) {
    Arvore* retorno;

    if (NO == NULL) {
        retorno = NULL;
    } else {
        if (code < NO->Curso->codigo) {
            if (cor(NO->esq) == BLACK && cor(NO->esq->esq) == BLACK) {
                NO = moveRedDireita(NO);
            }
            NO->esq = remove_NO(NO->esq, code);
        } else {
            if (cor(NO->esq) == RED) {
                NO = rotacionaDireita(NO);
            }
            if (code == NO->Curso->codigo && NO->dir == NULL) {
                // Nó folha, liberar memória e ajustar ponteiros
                free(NO);
                NO = NULL;  // Ajuste para retornar NULL corretamente
            } else {
                if (cor(NO->dir) == BLACK && cor(NO->dir->esq) == BLACK) {
                    NO = moveRedEsquerda(NO);
                }
                if (code == NO->Curso->codigo) {
                    Arvore* menor = buscaMenor(NO->dir);
                    NO->Curso = menor->Curso;
                    NO->dir = removeMenor(NO->dir);
                } else {
                    NO->dir = remove_NO(NO->dir, code);
                }
            }
        }

        if (NO != NULL) {
            NO = balancear(NO);
        }

        retorno = NO;
    }

    return retorno;
}

Arvore* removeMenor(Arvore *NO){
    if(NO->esq == NULL)
        free(NO);
    if (cor(NO->esq) == BLACK && cor(NO->esq->esq) == BLACK) {
        NO = moveRedDireita(NO);
    }
    NO->esq = removeMenor(NO->esq);
    return balancear(NO);
}


int main(){
    srand(time(NULL));
    int code, escolha, ndisciplina;
    Arvore* raiz = NULL;

    do{
        // Exibir o menu
        printf("\n***********************************\n");
        printf("Menu:\n");
        printf("0 - Sair\n");
        printf("1 - ADICIONAR NOVO Arvore 1\n");
        printf("2 - EXIBIR ArvoreS\n");
        printf("3 - REMOVER CURSO\n");
        printf("4 - Op 4\n");
        printf("5 - Op 5\n\n");
        printf("Escolha uma op (0-5): \n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            code = codigoArvore();
            printf("Quantidade de Disciplinas: \n");
            scanf("%d", &ndisciplina);
            criaArv(&raiz, code, ndisciplina);
            break;

        case 2:
            if (raiz != NULL) {
                    printf("Arvores:\n");
                    busca_inorder(raiz);
                } else {
                    printf("\nNenhum Arvore adicionado.\n");
                }
            break;

        case 3:
            printf("Codigo do curso a ser removido: ");
            scanf("%d", &code);
            remove_Arvore(raiz, code);
            break;
        }
    } while (escolha != 0);

    return 0;
}