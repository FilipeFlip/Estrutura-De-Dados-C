#ifndef ARVRB_H
#define ARVRB_H
#define RED 1 // Define as cores
#define BLACK 0

typedef struct Disciplina{
    int codigoDisciplina;
    int cor;
};

typedef struct Info{
    int codigoCurso;
    int cor;
    struct Disciplina;
    struct
} Info;

typedef struct Curso{
    Info *Info;
    struct Curso *esq;
    struct Curso *dir;
} Curso;


#endif