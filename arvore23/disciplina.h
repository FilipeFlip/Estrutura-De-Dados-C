#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct InfoDisciplina{
    int codigo;
    char nome[100];
    int bloco;
    int carga_horaria;
}InfoDisciplina;

typedef struct Disciplina{
    InfoDisciplina *InfoDisciplina;
    struct Disciplina *esquerda, *direita;
    int cor;
}Disciplina;


//Dfunções

#endif // DISCIPLINA_H