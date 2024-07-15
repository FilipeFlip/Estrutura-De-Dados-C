#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "curso.h"
#include "disciplina.h"

//Funções Disciplina
void criaDisciplina(Disciplina **raiz, const char* nomeDisciplina, int code) {
    insereDisciplina(raiz, nomeDisciplina, code);
    if ((*raiz) != NULL)
        (*raiz)->InfoDisciplina->cor = BLACK;  // Garantir que a raiz seja sempre preta
}

void insereDisciplina(Disciplina **raiz,const char* nomeDisciplina, int code){
    if (*raiz == NULL) {
        *raiz = cria_NODisciplina(nomeDisciplina, code);
    } else if (code < (*raiz)->InfoDisciplina->codigo) {
        insereDisciplina(&(*raiz)->esquerda, nomeDisciplina, code);
    } else if (code > (*raiz)->InfoDisciplina->codigo) {
        insereDisciplina(&(*raiz)->direita, nomeDisciplina, code);
    } else {
        printf("Codigo repetido");
    }
    *raiz = balancearDisciplina(*raiz);
}

Disciplina* cria_NODisciplina(const char* nomeDisciplina, int code){
    Disciplina *novo_NO = (Disciplina*)malloc(sizeof(Disciplina));
    if (novo_NO != NULL){
        novo_NO->InfoDisciplina = (InfoDisciplina*)malloc(sizeof(InfoDisciplina));
        if (novo_NO->InfoDisciplina != NULL){
            strcpy(novo_NO->InfoDisciplina->nomeDisciplina, nomeDisciplina);
            novo_NO->InfoDisciplina->codigo = code;
            novo_NO->InfoDisciplina->cor = RED;
            novo_NO->direita = NULL;
            novo_NO->esquerda = NULL;
        }
    }
    return novo_NO;
}

void listaDisciplina(Disciplina *NO) {
    if (NO != NULL) {
        listaDisciplina(NO->esquerda);
        printf("\nNome da Disciplina: %s", NO->InfoDisciplina->nomeDisciplina);
        printf("\nCodigo Da Disciplina: %d", NO->InfoDisciplina->codigo);
        printf("\nCor do NO: %s\n", NO->InfoDisciplina->cor == RED ? "RED" : "BLACK");
        printf("\n-------------------------------------------------\n");
        listaDisciplina(NO->direita);
    }
}

Disciplina* buscaDisciplina(Disciplina *NO, int code){
    Disciplina *achou = NULL;

    if (NO == NULL || NO->InfoDisciplina->codigo == code) {
        achou = NO;
    } else if (NO->InfoDisciplina->codigo > code) {
        achou = buscaDisciplina(NO->esquerda, code);
    } else {
        achou = buscaDisciplina(NO->direita, code);
    }

    return achou;
}

int buscaCodDisciplina(Disciplina *NO, int code){
    int achou = 0;

    if (NO == NULL) {
        achou = 0;
    } else if (NO->InfoDisciplina->codigo == code) {
        achou = code;
    } else if (NO->InfoDisciplina->codigo > code) {
        achou = buscaCodDisciplina(NO->esquerda, code);
    } else {
        achou = buscaCodDisciplina(NO->direita, code);
    }

    return achou;
}

Disciplina* balancearDisciplina(Disciplina *NO) {
    // Caso 1: Nó à direita é vermelho e nó à esquerda é preto
    if (corDisciplina(NO->direita) == RED && corDisciplina(NO->esquerda) == BLACK)
        NO = rotacionaEsquerdaDisciplina(NO);

    // Caso 2: Nó à esquerda é vermelho e o filho esquerdo do nó à esquerda também é vermelho
    if (corDisciplina(NO->esquerda) == RED && corDisciplina(NO->esquerda->esquerda) == RED)
        NO = rotacionaDireitaDisciplina(NO);

    // Caso 3: Ambos filhos são vermelhos
    if (corDisciplina(NO->esquerda) == RED && corDisciplina(NO->direita) == RED)
        trocaCorDisciplina(NO);

    return NO;
}

int corDisciplina(Disciplina *NO){
    int ver;
    if(NO == NULL)
        ver = BLACK;
    else{
        ver = NO->InfoDisciplina->cor;
    }
    return ver;
}

void trocaCorDisciplina(Disciplina *NO){
    NO->InfoDisciplina->cor = !NO->InfoDisciplina->cor;
    if(NO->InfoDisciplina != NULL)
        NO->esquerda->InfoDisciplina->cor = !NO->esquerda->InfoDisciplina->cor;
    if(NO->direita != NULL)
        NO->direita->InfoDisciplina->cor = !NO->direita->InfoDisciplina->cor; 
}


Disciplina* rotacionaDireitaDisciplina(Disciplina *NO){
    Disciplina *aux = NO->esquerda;
    NO->esquerda = aux->direita;
    aux->direita = NO;
    aux->InfoDisciplina->cor = NO->InfoDisciplina->cor;
    NO->InfoDisciplina->cor = RED;

    return aux;
}

Disciplina* rotacionaEsquerdaDisciplina(Disciplina *NO){
    Disciplina *aux = NO->direita;
    NO->direita = aux->esquerda;
    aux->esquerda = NO;
    aux->InfoDisciplina->cor = NO->InfoDisciplina->cor;
    NO->InfoDisciplina->cor = RED;

    return aux;
}

Disciplina* moveRedEsquerdaDisciplina(Disciplina *NO) {
    trocaCorDisciplina(NO);
    if (corDisciplina(NO->direita->esquerda) == RED) {
        NO->direita = rotacionaDireitaDisciplina(NO->direita);
        NO = rotacionaEsquerdaDisciplina(NO);
        trocaCorDisciplina(NO);
    }
    return NO;
}

Disciplina* moveRedDireitaDisciplina(Disciplina *NO) {
    trocaCorDisciplina(NO);
    if (corDisciplina(NO->esquerda->esquerda) == RED) {
        NO = rotacionaDireitaDisciplina(NO);
        trocaCorDisciplina(NO);
    }
    return NO;
}

Disciplina* buscaMenorDisciplina(Disciplina *NO){
    Disciplina *no1 = NO;
    Disciplina *no2 = NO->esquerda;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esquerda;
    }
    return no1;
}

//Funções Remoção
int remove_Disciplina(Disciplina **NO, int code) {
    int x = 0;
    if (buscaCodDisciplina(*NO, code) == code) {
        *NO = remove_NODisciplina(*NO, code);
        if (*NO != NULL) {
            (*NO)->InfoDisciplina->cor = BLACK;
        }
        x = 1;
    } else {
        printf("Disciplina não encontrado ou não pode ser removido.\n");
    }
    
    return x;
}



Disciplina* remove_NODisciplina(Disciplina *NO, int code) {
    if (code < NO->InfoDisciplina->codigo) {
        if (corDisciplina(NO->esquerda) == BLACK && corDisciplina(NO->esquerda->esquerda) == BLACK) {
            NO = moveRedDireitaDisciplina(NO);
        }
        NO->esquerda = remove_NODisciplina(NO->esquerda, code);
    } else {
        if (corDisciplina(NO->esquerda) == RED) {
            NO = rotacionaDireitaDisciplina(NO);
        }
        if (code == NO->InfoDisciplina->codigo && NO->direita == NULL) {
            free(NO);
            NO = NULL;
        } else {
            if (corDisciplina(NO->direita) == BLACK && corDisciplina(NO->direita->esquerda) == BLACK) {
                NO = moveRedEsquerdaDisciplina(NO);
            }
            if (code == NO->InfoDisciplina->codigo) {
                Disciplina* menor = buscaMenorDisciplina(NO->direita);
                NO->InfoDisciplina = menor->InfoDisciplina;
                NO->direita = removeMenorDisciplina(NO->direita);
            } else {
                NO->direita = remove_NODisciplina(NO->direita, code);
            }
        }
    }

    if (NO != NULL) {
        NO = balancearDisciplina(NO);
    }
    
    return NO;
}

Disciplina* removeMenorDisciplina(Disciplina *NO) {
    if (NO->esquerda == NULL) {
        free(NO);
        NO = NULL;
    } else {
        if (corDisciplina(NO->esquerda) == BLACK && corDisciplina(NO->esquerda->esquerda) == BLACK) {
            NO = moveRedDireitaDisciplina(NO);
        }

        NO->esquerda = removeMenorDisciplina(NO->esquerda);

        if (NO != NULL) {
            NO = balancearDisciplina(NO);
        }
    }
    return NO;
}



