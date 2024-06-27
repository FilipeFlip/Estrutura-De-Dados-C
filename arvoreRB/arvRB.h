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

//Cria a raiz da arvore de cursos
int criaCurso(Curso **raiz, int valor);

//Insere o curso na arvore
Curso* insereCurso(Curso *curso, int valor, int *resposta);

//busca inorder
void busca_inorder(Curso *raiz);

// //insere valor no nó
// void insereArvRB(ArvRB **NO, int valor);

// //Rotação para a esquerda
// ArvRB* rotaciona_esq(ArvRB *NO);

// //Rotação para a direita
// ArvRB* rotaciona_dir(ArvRB *NO);

// //troca a cor do no filho com o pai
// void troca_cor(ArvRB *NO);

//Vê a cor do nó
int ver_cor(Curso *curso);

void mostra_cor(Curso *curso);

// //move o nó vermelho
// ArvRB* moveRedEsq(ArvRB *NO);

// ArvRB* moveRedDir(ArvRB *NO);

// // Balanceia o nó
// ArvRB* balancear(ArvRB *NO);

// //apaga a árvore quando não tem manis nenhum nó
// ArvRB* remove_ArvRB(ArvRB *NO, int valor);

// // remove um nó
// ArvRB* remove_NO(ArvRB *NO, int valor);

// // remove o menor nó
// ArvRB* remove_menor(ArvRB *NO);

// //busca o menor nó
// ArvRB* busca_menor(ArvRB *NO);

void busca_inorder(Curso *raiz);

#endif