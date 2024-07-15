#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "curso.h"
#include "disciplina.h"

//Funções Inserir Curso 
void criaCurso(Curso **raiz, const char* nomeCurso, int code) {
    insereCurso(raiz, nomeCurso, code);
    if ((*raiz) != NULL)
        (*raiz)->Info->cor = BLACK;  // Garantir que a raiz seja sempre preta
}

void insereCurso(Curso **raiz,const char* nomeCurso, int code){
    if (*raiz == NULL) {
        *raiz = cria_NOCurso(nomeCurso, code);
    } else if (code < (*raiz)->Info->codigo) {
        insereCurso(&(*raiz)->esquerda, nomeCurso, code);
    } else if (code > (*raiz)->Info->codigo) {
        insereCurso(&(*raiz)->direita, nomeCurso, code);
    } else {
        printf("Codigo repetido");
    }
    *raiz = balancearCurso(*raiz);
}

Curso* cria_NOCurso(const char* nomeCurso, int code){
    Curso *novo_NO = (Curso*)malloc(sizeof(Curso));
    if (novo_NO != NULL){
        novo_NO->Info = (Info*)malloc(sizeof(Info));
        if (novo_NO->Info != NULL){
            strcpy(novo_NO->Info->nomeCurso, nomeCurso);
            novo_NO->Info->codigo = code;
            novo_NO->Info->cor = RED;
            novo_NO->direita = NULL;
            novo_NO->esquerda = NULL;
        }
    }
    return novo_NO;
}

//Funções Auxiliares 
Curso* buscaCurso(Curso *NO, int code){
    Curso *achou = NULL;
    if (NO == NULL || NO->Info->codigo == code) {
        achou = NO;
    } else if (NO->Info->codigo > code) {
        achou = buscaCurso(NO->esquerda, code);
    } else {
        achou = buscaCurso(NO->direita, code);
        printf("aasdfa");
    }

    return achou;
}

int buscaCodCurso(Curso *NO, int code){
    int achou = 0; // Inicializa com 0, já que estamos buscando um código inteiro

    if (NO == NULL) {
        achou = 0; // Árvore vazia ou curso não encontrado
    } else if (NO->Info->codigo == code) {
        achou = code; // Encontrou o curso com o código especificado
    } else if (NO->Info->codigo > code) {
        achou = buscaCodCurso(NO->esquerda, code); // Busca na subárvore esquerda
    } else {
        achou = buscaCodCurso(NO->direita, code); // Busca na subárvore direita
    }

    return achou;
}

Curso* balancearCurso(Curso *NO) {
    // Caso 1: Nó à direita é vermelho e nó à esquerda é preto
    if (corCurso(NO->direita) == RED && corCurso(NO->esquerda) == BLACK)
        NO = rotacionaEsquerdaCurso(NO);

    // Caso 2: Nó à esquerda é vermelho e o filho esquerdo do nó à esquerda também é vermelho
    if (corCurso(NO->esquerda) == RED && corCurso(NO->esquerda->esquerda) == RED)
        NO = rotacionaDireitaCurso(NO);

    // Caso 3: Ambos filhos são vermelhos
    if (corCurso(NO->esquerda) == RED && corCurso(NO->direita) == RED)
        trocaCorCurso(NO);

    return NO;
}


int corCurso(Curso *NO){
    int ver;
    if(NO == NULL)
        ver = BLACK;
    else{
        ver = NO->Info->cor;
    }
    return ver;
}

void trocaCorCurso(Curso *NO){
    NO->Info->cor = !NO->Info->cor;
    if(NO->Info != NULL)
        NO->esquerda->Info->cor = !NO->esquerda->Info->cor;
    if(NO->direita != NULL)
        NO->direita->Info->cor = !NO->direita->Info->cor; 
}

Curso* rotacionaDireitaCurso(Curso *NO){
    Curso *aux = NO->esquerda;
    NO->esquerda = aux->direita;
    aux->direita = NO;
    aux->Info->cor = NO->Info->cor;
    NO->Info->cor = RED;

    return aux;
}

Curso* rotacionaEsquerdaCurso(Curso *NO){
    Curso *aux = NO->direita;
    NO->direita = aux->esquerda;
    aux->esquerda = NO;
    aux->Info->cor = NO->Info->cor;
    NO->Info->cor = RED;

    return aux;
}

void listaCurso(Curso *NO) {
    if (NO != NULL) {
        listaCurso(NO->esquerda);
        printf("\nNome do Curso: %s", NO->Info->nomeCurso);
        printf("\nCodigo do Curso: %d", NO->Info->codigo);
        printf("\nCor do NO: %s\n", NO->Info->cor == RED ? "RED" : "BLACK");
        printf("\n-------------------------------------------------\n");
        listaCurso(NO->direita);
    }
}

Curso* moveRedEsquerdaCurso(Curso *NO) {
    trocaCorCurso(NO);
    if (corCurso(NO->direita->esquerda) == RED) {
        NO->direita = rotacionaDireitaCurso(NO->direita);
        NO = rotacionaEsquerdaCurso(NO);
        trocaCorCurso(NO);
    }
    return NO;
}

Curso* moveRedDireitaCurso(Curso *NO) {
    trocaCorCurso(NO);
    if (corCurso(NO->esquerda->esquerda) == RED) {
        NO = rotacionaDireitaCurso(NO);
        trocaCorCurso(NO);
    }
    return NO;
}

Curso* buscaMenorCurso(Curso *NO){
    Curso *no1 = NO;
    Curso *no2 = NO->esquerda;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esquerda;
    }
    return no1;
}

//Funções Remoção
int remove_Curso(Curso **NO, int code) {
    int x = 0;
    if (buscaCodCurso(*NO, code) == code) {
        *NO = remove_NOCurso(*NO, code);
        if (*NO != NULL) {
            (*NO)->Info->cor = BLACK; // Garante que a raiz seja preta após a remoção
        }
        x = 1; // Indica que o curso foi removido com sucesso
    } else {
        printf("Curso não encontrado ou não pode ser removido.\n");
    }
    
    return x;
}


Curso* remove_NOCurso(Curso *NO, int code) {
    Curso *retorno = NO;

    if (NO == NULL) {
        retorno = NULL;// Caso base: nó não encontrado
    }

    if (code < NO->Info->codigo) {
        if (NO->esquerda != NULL && (corCurso(NO->esquerda) == RED || corCurso(NO->esquerda->esquerda) == RED)) {
            NO = moveRedDireitaCurso(NO);
        }
        NO->esquerda = remove_NOCurso(NO->esquerda, code);
    } else {
        if (corCurso(NO->esquerda) == RED) {
            NO = rotacionaDireitaCurso(NO);
        }
        if (code == NO->Info->codigo && NO->direita == NULL) {
            free(NO);
            retorno = NULL; // Nó encontrado e é uma folha
        } else {
            if (NO->direita != NULL && (corCurso(NO->direita) == RED || corCurso(NO->direita->esquerda) == RED)) {
                NO = moveRedEsquerdaCurso(NO);
            }
            if (code == NO->Info->codigo) {
                Curso* menor = buscaMenorCurso(NO->direita);
                NO->Info = menor->Info;
                NO->direita = removeMenorCurso(NO->direita);
            } else {
                NO->direita = remove_NOCurso(NO->direita, code);
            }
        }
    }

    if (retorno != NULL) {
        retorno = balancearCurso(retorno); // Retorna o nó balanceado após a remoção
    }

    return retorno;
}

Curso* removeMenorCurso(Curso *NO) {
    if (NO->esquerda == NULL) {
        free(NO);
        NO = NULL;
    } else {
        if (corCurso(NO->esquerda) == BLACK && corCurso(NO->esquerda->esquerda) == BLACK) {
            NO = moveRedDireitaCurso(NO);
        }

        NO->esquerda = removeMenorCurso(NO->esquerda);

        if (NO != NULL) {
            NO = balancearCurso(NO);
        }
    }
    return NO;
}
