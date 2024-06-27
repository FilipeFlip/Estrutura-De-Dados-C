#ifndef ARVRB_H
#define ARVRB_H
#define RED 1 // Define as cores
#define BLACK 0

//Definição do curso
typedef struct Disciplina{
    int codDisciplina;
    char nomeDisciplina[100];
    struct Disciplina *esq;
    struct Disciplina *dir;
    int cor;
} Disciplina;

//definição da arvore
typedef struct Curso{
    int codCurso;
    char nomeCurso[100];
    int quantidadeBlocos;
    int quantidadeDisciplina;
    Disciplina *disciplinas;
    struct Curso *esq;
    struct Curso *dir;
    int cor;
} Curso;


//void troca_cor(Curso *curso);
int ver_cor(Curso *curso);
Curso* rotacionaEsquerda(Curso *curso);
Curso* rotacionaDireita(Curso *curso);

void criaCurso(Curso **raiz, int valor);
Curso* insereCurso(Curso *curso, int valor);
void busca_inorder(Curso *raiz);

#endif