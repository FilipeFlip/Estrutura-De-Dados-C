#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#define MAX_NOME 100
#define RED 1 // Define as cores
#define BLACK 0

typedef struct InfoDisciplina{
    char nomeDisciplina[MAX_NOME];
    int codigo;
    int cor;
}InfoDisciplina;

typedef struct Disciplina{
    InfoDisciplina *InfoDisciplina;
    struct Disciplina *esquerda, *direita;
}Disciplina;


//Funções
void criaDisciplina(Disciplina **raiz, const char* nomeDisciplina, int code);
void insereDisciplina(Disciplina **raiz, const char* nomeDisciplina, int code);
Disciplina* cria_NODisciplina(const char* Disciplina, int  code);

//Funções auxiliares
Disciplina* balancearDisciplina(Disciplina *NO);
int buscaCodDisciplina(Disciplina *NO, int code);
int corDisciplina(Disciplina *NO);
void trocaCorDisciplina(Disciplina *NO);
Disciplina* rotacionaDireitaDisciplina(Disciplina *NO);
Disciplina* rotacionaEsquerdaDisciplina(Disciplina *NO);
void listaDisciplina(Disciplina *NO);
Disciplina* moveRedEsquerdaDisciplina(Disciplina *NO);
Disciplina* moveRedDireitaDisciplina(Disciplina *NO);
Disciplina* buscaMenorDisciplina(Disciplina *NO);

//Funções Remoção

int remove_Disciplina(Disciplina **NO, int code);
Disciplina* remove_NODisciplina(Disciplina *NO, int code);
Disciplina* removeMenorDisciplina(Disciplina *NO);

#endif // DISCIPLINA_H