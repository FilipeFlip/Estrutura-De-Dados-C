#ifndef ARVRB_H
#define ARVRB_H
#define RED 1 // Define as cores
#define BLACK 0



typedef struct Curso{
    int codigo;
    int disciplinas;
    int cor;
} Curso;

typedef struct Arvore{
    Curso *Curso;
    struct Arvore *esq;
    struct Arvore *dir;
} Arvore;

int cont = 0; 
//Funções para inserção 
void criaArv(Arvore **raiz, int code, int ndisciplina);
void insere(Arvore **raiz, int code, int ndisciplina);
Arvore* cria_NO(int code, int ndisciplina);

//Funções auxiliares
Arvore* balancear(Arvore *NO);
int codigoArvore();
void busca_inorder(Arvore *NO);
int cor(Arvore *NO);
void trocaCor(Arvore *NO);
Arvore* rotacionaDireita(Arvore *NO);
Arvore* rotacionaEsquerda(Arvore *NO);
Arvore* moveRedEsquerda(Arvore *NO);
Arvore* moveRedDireita(Arvore *NO);
int buscaNO(Arvore *NO, int code);
Arvore* buscaMenor(Arvore *NO);

// Funções para remoção
Arvore* remove_NO(Arvore *NO, int code);
int remove_Arvore(Arvore *NO, int code);
Arvore* removeMenor(Arvore *NO);

//Funções Menu
int inteiroMenu(const char *str);
int lerInteiroMenu();


#endif