#ifndef CURSO_H
#define CURSO_H

#include "disciplina.h"

typedef struct Curso {
    int codigo;
    char nome[100];
    int quantidade_blocos;
    int semanas_por_disciplina;
    struct Disciplina* disciplinas; // Ponteiro para a árvore de disciplinas
    struct Curso *esquerda, *direita;
    int cor;
} Curso;

//Funções

#endif // CURSO_H