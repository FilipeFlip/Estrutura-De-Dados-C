#ifndef ARVRB_H
#define ARVRB_H
#define RED 1 // Define as cores
#define BLACK 0

typedef struct Info{
    int codigo;
    int disciplinas;
    int cor;
} Info;

typedef struct Curso{
    Info *info;
    struct Curso *esq;
    struct Curso *dir;
} Curso;

int cont = 0; 

void criaArv(Curso **raiz, int code, int ndisciplina);
void insere(Curso **raiz, int code, int ndisciplina);
Curso* cria_NO(int code, int ndisciplina);
Curso* balancear(Curso *NO);

int codigoCurso();
void busca_inorder(Curso *NO);
int cor(Curso *NO);
void trocaCor(Curso *NO);
Curso* rotacionaDireita(Curso *NO);
Curso* rotacionaEsquerda(Curso *NO);

#endif