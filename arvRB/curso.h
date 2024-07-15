#ifndef CURSO_H
#define CURSO_H

#include "disciplina.h"

typedef struct Info {
    char nomeCurso[MAX_NOME];
    int codigo;
    int bloco;
    int semana;
    int cor;
    struct Disciplina* Disciplinas; // Ponteiro para a árvore de disciplinas
}Info ;

typedef struct Curso {
    struct Info *Info;
    struct Curso *esquerda, *direita;
} Curso;

//Funções Inserir
void criaCurso(Curso **raiz, const char* nomeCurso, int code, int bloco, int semanas); 
void insereCurso(Curso **raiz,const char* nomeCurso, int code, int bloco, int semanas);
Curso* cria_NOCurso(const char* nomeCurso, int code, int bloco, int semanas);

//Funções Remoção
int remove_Curso(Curso **NO, int code);
Curso* remove_NOCurso(Curso *NO, int code);
Curso* removeMenorCurso(Curso *NO);

//Funçõesa Auxiliares
Curso* buscaCurso(Curso *NO, int code);
int buscaCodCurso(Curso *NO, int code);
Curso* balancearCurso(Curso *NO);
int corCurso(Curso *NO);
void trocaCorCurso(Curso *NO);
Curso* rotacionaDireitaCurso(Curso *NO);
Curso* rotacionaEsquerdaCurso(Curso *NO);
void listaCurso(Curso *NO);
Curso* moveRedEsquerdaCurso(Curso *NO);
Curso* moveRedDireitaCurso(Curso *NO);
Curso* buscaMenorCurso(Curso *NO);




#endif // CURSO_H