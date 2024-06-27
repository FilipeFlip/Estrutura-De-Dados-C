#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvRB.h"



int criaCurso(Curso **raiz, int valor) {
    int resposta;
    *raiz = insereCurso(*raiz, valor, &resposta);
    if ((*raiz) != NULL)
        (*raiz)->cor = BLACK;
    return resposta;
}

Curso* insereCurso(Curso *curso, int valor, int *resposta){
    if (curso == NULL){
        Curso *novoCurso = (Curso*)malloc(sizeof(Curso));
        if(novoCurso != NULL){
            novoCurso->codCurso = valor;
            novoCurso->quantidadeBlocos = 0;
            novoCurso->quantidadeDisciplina = 0;
            novoCurso->disciplinas = NULL;
            novoCurso->esq = NULL;
            novoCurso->dir = NULL;
            novoCurso->cor = RED;
            *resposta = 1;
            return novoCurso;
        } else {
            *resposta = 0;
            return NULL;
    }
    } else {
        // Insira lógica adicional para inserir o curso na árvore, se necessário
        *resposta = 0;
        return curso;
    //if(valor = curso->codCurso){
    //     printf("\nCodigo duplicado");
    //     *resposta = 0;
    // }
    // else{
    //     if(valor < curso->codCurso)
    //         curso->esq = insereCurso(curso->esq, valor, resposta);
    //     else
    //         curso->dir = insereCurso(curso->dir, valor, resposta);
    // }

    // if(ver_cor(curso->dir) == RED && ver_cor(curso->esq) == BLACK);
    //     curso = rotacionaEsquerda(curso);
    
    // if(ver_cor(curso->esq) == RED && ver_cor(curso->esq->esq) == RED);
    //     curso = rotacionaDireita(curso);

    // if(ver_cor(curso->esq) == RED && ver_cor(curso->dir) == BLACK);
    //     trocaCor(curso);
    }
}
void busca_inorder(Curso *raiz) {
    if (raiz != NULL) {
        busca_inorder(raiz->esq);
        printf("Código do Curso: %d\n", raiz->codCurso);
        busca_inorder(raiz->dir);
    }
}

// ArvRB* rotaciona_esq(ArvRB *NO){
//     ArvRB *nova = NO->dir;

//     NO->dir = nova->esq;
//     nova->esq = NO;
//     nova->cor = NO->cor;
//     NO->cor = RED;

//     return nova;
// }

// ArvRB* rotaciona_dir(ArvRB *NO){
//     ArvRB *nova = NO->esq;

//     NO->esq = nova->dir;
//     nova->dir = NO;
//     nova->cor = NO->cor;
//     NO->cor = RED;

//     return nova;
// }

// void troca_cor(ArvRB *NO){
//     NO->cor = !NO->cor;
//     if(NO->esq != NULL)
//         NO->esq->cor = !NO->esq->cor;
//     if(NO->dir != NULL)
//         NO->dir->cor = !NO->dir->cor;
// }

int ver_cor(Curso *curso){
    int ver = curso->cor;
    if(curso == NULL)
        ver = BLACK;
    else
        ver = curso->cor;
    return ver;
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

int main(){

    int escolha, valor = 1;

    Curso* raiz = NULL;

    do{

        // Exibir o menu
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
            criaCurso(&raiz, valor);
            break;
        
        case 2:
            if (raiz != NULL) {
                    printf("Cursos:\n");
                    busca_inorder(raiz);
                } else {
                    printf("\n Nenhum curso adicionado.\n");
                }
            break;

        case 3:
            if(raiz != NULL){
                int cor = ver_cor(raiz);
                printf("%d", cor);
            }
            break;
        }
    } while (escolha != 0);

    return 0;
}