#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvRB.h"

void criaArv(Curso **raiz, int code, int ndisciplina){
    insere(raiz, code, ndisciplina);
    if((*raiz) != NULL)
        (*raiz)->info->cor = BLACK;
}

void insere(Curso **raiz, int code, int ndisciplina) {
    
    if (*raiz == NULL) {
        printf("test raiz");
        cont ++;
        *raiz = cria_NO(code, ndisciplina);
    } else if (code < (*raiz)->info->codigo) {
        printf("test esq");
        insere(&(*raiz)->esq, code, ndisciplina);
    } else if (code > (*raiz)->info->codigo) {
        printf("test dir");
        insere(&(*raiz)->dir, code, ndisciplina);
    } else {
    }
    *raiz = balancear(*raiz);
}

Curso* cria_NO(int code, int ndisciplina){
    Curso *novo_NO = (Curso*)malloc(sizeof(Curso));
    if (novo_NO != NULL){
        novo_NO->info = (Info*)malloc(sizeof(Info));
        if (novo_NO->info != NULL){
            novo_NO->info->codigo = code;
            novo_NO->info->disciplinas = ndisciplina;
            novo_NO->info->cor = RED;
            novo_NO->dir = NULL;
            novo_NO->esq = NULL;
        }
    }
    return novo_NO;
}

Curso* balancear(Curso *NO) {
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

int cor(Curso *NO){
    int ver;
    if(NO == NULL)
        ver = BLACK;
    else{
        ver = NO->info->cor;
        printf("cor do no %d\n", ver);
    }
    return ver;
}

void trocaCor(Curso *NO){
    printf("trocou");
    NO->info->cor = !NO->info->cor;
    if(NO->esq != NULL)
        NO->esq->info->cor = !NO->esq->info->cor;
    if(NO->dir != NULL)
        NO->dir->info->cor = !NO->dir->info->cor; 
}

Curso* rotacionaDireita(Curso *NO){
    Curso *aux = NO->esq;
    NO->esq = aux->dir;
    aux->dir = NO;
    aux->info->cor = NO->info->cor;
    NO->info->cor = RED;

    return aux;
}

Curso* rotacionaEsquerda(Curso *NO){
    Curso *aux = NO->dir;
    NO->dir = aux->esq;
    aux->esq = NO;
    aux->info->cor = NO->info->cor;
    NO->info->cor = RED;

    return aux;
}


int codigoCurso(){
    // int x = 1 + ( rand() % 1000 );
    int x;
    printf("\nCodigo do Curso: ");
    scanf("%d", &x);
    return x;
}

void busca_inorder(Curso *NO) {
    if (NO != NULL) {
        busca_inorder(NO->esq);
        printf("\nCodigo do curso: %d", NO->info->codigo);
        printf("\nQuantidade de disciplinas: %d", NO->info->disciplinas);
        printf("\nCor do NO: %s\n", NO->info->cor == RED ? "RED" : "BLACK");
        printf("\n-------------------------------------------------\n");
        busca_inorder(NO->dir);
    }
}

int main(){
    srand(time(NULL));
    int code, escolha, ndisciplina;
    Curso* raiz = NULL;

    do{
        // Exibir o menu
        printf("\n***********************************\n");
        printf("Menu:\n");
        printf("0 - Sair\n");
        printf("1 - ADICIONAR NOVO CURSO 1\n");
        printf("2 - EXIBIR CURSOS\n");
        printf("3 - MOSTRAR COR DOS CURSOS\n");
        printf("4 - Op 4\n");
        printf("5 - Op 5\n\n");
        printf("Escolha uma op (0-5): \n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            code = codigoCurso();
            printf("Quantidade de Disciplinas: \n");
            scanf("%d", &ndisciplina);
            criaArv(&raiz, code, ndisciplina);
            break;

        case 2:
            if (raiz != NULL) {
                    printf("Cursos:\n");
                    busca_inorder(raiz);
                } else {
                    printf("\nNenhum curso adicionado.\n");
                }
            break;

        case 3:
            break;
        }
    } while (escolha != 0);

    return 0;
}

// ArvRB* moveRedEsq(ArvRB *NO){
//     troca_cor(NO);

//     if(ver_cor(NO->dir->esq) == RED){
//         NO->dir = rotaciona_dir(NO->dir);
//         NO = rotaciona_esq(NO);
//         troca_cor(NO);
//     }
//     return NO;
// }

// ArvRB* moveRedDir(ArvRB *NO){
//     troca_cor(NO);

//     if(ver_cor(NO->esq->esq) == RED){
//         NO = rotaciona_dir(NO);
//         troca_cor(NO);
//     }
// }

// ArvRB* balancear(ArvRB *NO){
//     if(ver_cor(NO->dir) == RED);
//         NO = rotaciona_esq(NO);

//     if((NO->esq) != NULL && ver_cor(NO->dir) == RED && ver_cor(NO->esq->esq) == RED)
//         NO = rotaciona_dir(NO);

//     if(ver_cor(NO->esq) == RED && ver_cor(NO->dir) == RED)
//         troca_cor(NO);
// }

// int busca_NO(ArvRB *NO, int valor){
//     int  achou;

//     if((NO) != NULL){
//         if((NO->info) == valor)
//             achou = 1;
//         if((NO->info) > valor)
//             busca_NO((NO->esq), valor);
//         if((NO->info) < valor)
//             busca_NO((NO->dir), valor);
//     }

//     else
//         achou = 0;

//     return achou;
// }

// ArvRB* remove_ArvRB(ArvRB *NO, int valor){
//     if(busca_NO(NO, valor)){
//         ArvRB* NO = NO;

//         NO = remove_NO (NO, valor);

//         if(NO != NULL)
//             (NO)->cor = BLACK;
//     }
// }

// ArvRB* remove_NO(ArvRB *NO, int valor){
//     if(valor < NO->info){
//         if(ver_cor(NO->esq) == BLACK && ver_cor(NO->esq->esq) == BLACK)
//             NO = moveRedDir(NO);
//     }
//     else{
//         if(ver_cor(NO->esq) == RED)
//             NO = rotaciona_dir(NO);

//         if(valor == (NO->info) && (NO->dir == NULL))
//             free(NO);

//         if(ver_cor(NO->dir) == BLACK && ver_cor(NO->dir->esq) == BLACK)
//             NO = moveRedDir(NO);

//         if(valor == NO->info){
//             ArvRB* x = busca_menor(NO->dir);
//             NO->info = x->info;
//             NO->dir = remove_menor(NO->dir);
//         }
//         else{
//             NO->dir = remove_NO(NO->dir, valor);
//         }
//     }
// }

// ArvRB* remove_menor(ArvRB *NO){
//     if(NO->esq == NULL)
//         free(NO);
//     if(ver_cor(NO->esq) == BLACK && ver_cor(NO->esq->esq) == BLACK)

//     NO->esq = remove_menor(NO->esq);
//     return balancear(NO);
// }

// ArvRB* busca_menor(ArvRB *NO){
//     ArvRB *no1 = NO;
//     ArvRB *no2 = NO->esq;
//     while(no2 != NULL){
//         no1 = no2;
//         no2 = no2->esq;
//     }
//     return no1;
// }
