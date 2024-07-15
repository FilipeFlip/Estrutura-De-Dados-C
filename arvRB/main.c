#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "curso.h"
#include "disciplina.h"
#include "curso.c"
#include "disciplina.c"

// Funções MENU
// Função para verificar se a string contém apenas dígitos
int inteiroMenu(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

// Função para ler um inteiro do menu
int lerInteiroMenu() {
    char entrada[100];
    while (1) {
        // Lê a entrada do usuário como uma string
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
            // Remove o caractere de nova linha, se houver
            size_t len = strlen(entrada);
            if (len > 0 && entrada[len-1] == '\n') {
                entrada[len-1] = '\0';
            }
            // Verifica se a entrada é um número inteiro válido
            if (inteiroMenu(entrada)) {
                return atoi(entrada); // Converte para inteiro e retorna
            } else {
                printf("Entrada inválida. Por favor, digite um número inteiro.\n");
            }
        } else {
            printf("Erro ao ler a entrada. Tente novamente.\n");
        }
    }
}

int main() {
    int code, escolha = 0;
    char nomeCurso[MAX_NOME], nomeDisciplina[MAX_NOME];
    Curso* cursos = NULL;
    //Disciplina* disciplinas = NULL;

    criaCurso(&cursos, "Engenharia de Software", 1);
    criaCurso(&cursos, "Ciência da Computação", 2);
    criaCurso(&cursos, "Sistemas de Informação", 3);

    do {
        // Exibir o menu
        printf("\n***********************************\n");
        printf("Menu:\n");
        printf("0 - Sair\n");
        printf("1 - ADICIONAR NOVO CURSO\n");
        printf("2 - EXIBIR CURSOS\n");
        printf("3 - REMOVER CURSO\n");
        printf("4 - ADICIONAR DISCIPLINA\n");
        printf("5 - REMOVER DISCIPLINA\n");
        printf("6 - LISTAR DISCIPLINAS\n");
        printf("7 - LISTAR DISCIPLINAS\n");
        printf("8 - LISTAR DISCIPLINAS\n");
        printf("9 - LISTAR DISCIPLINAS\n");
        printf("Escolha uma op (0-9): ");

        
        escolha = lerInteiroMenu();

        switch (escolha) {
            case 1:
                printf("Nome do Curso: ");
                scanf(" %[^\n]s", nomeCurso);
                while (getchar() != '\n');
                printf("Codigo do Curso: ");
                code = lerInteiroMenu();
                criaCurso(&cursos, nomeCurso, code);
                break;

            case 2:
                if (cursos != NULL) {
                    printf("Cursos:\n");
                    listaCurso(cursos);
                } else {
                    printf("\nNenhum Arvore adicionado.\n");
                }
                break;

            case 3:
                printf("Codigo do curso a ser removido: ");
                code = lerInteiroMenu();
                if (remove_Curso(&cursos, code)) {
                    printf("Curso removido com sucesso.\n");
                } else {
                    printf("Curso não encontrado ou não pode ser removido.\n");
                }
                break;
                
            case 4:
                printf("Codigo do Curso: ");
                code = lerInteiroMenu();
                Curso* cursoEncontrado = buscaCurso(cursos, code);
                if (cursoEncontrado != NULL) {
                    printf("Nome da Disciplina: ");
                    scanf(" %[^\n]s", nomeDisciplina);
                    while (getchar() != '\n');  // Limpar o buffer
                    printf("Codigo da Disciplina: ");
                    code = lerInteiroMenu();
                    criaDisciplina(&(cursoEncontrado->Info->Disciplinas), nomeDisciplina, code);
                } else {
                    printf("Curso não encontrado.\n");
                }
                break;
            case 5:
                printf("Codigo do Curso: ");
                code = lerInteiroMenu();
                cursoEncontrado = buscaCurso(cursos, code);
                if (cursoEncontrado != NULL) {
                    if (remove_Disciplina(&(cursoEncontrado->Info->Disciplinas), code)) {
                        printf("Disciplina removida com sucesso.\n");
                    } else {
                        printf("Disciplina não encontrada ou não pode ser removida.\n");
                    }
                } else {
                    printf("\nNenhum curso adicionado com esse codigo.\n");
                }
                break;

            case 6:
                printf("Codigo do Curso: ");
                code = lerInteiroMenu();
                cursoEncontrado = buscaCurso(cursos, code);
                if (cursoEncontrado != NULL) {
                    printf("Disciplinas:\n");
                    listaDisciplina(cursoEncontrado->Info->Disciplinas);
                } else {
                    printf("\nNenhum curso adicionado com esse codigo.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (escolha != 0);

    return 0;
}