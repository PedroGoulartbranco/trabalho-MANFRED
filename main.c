#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void limpar_terminal() {
    if (system("cls") == -1) {
        system("clear");
    }
}

void mostrar_menu() {
    printf("=====================================\n");
    printf("                Menu                 \n");
    printf("=====================================\n");
    printf("[1] Incluir contato\n[2] Listar Contatos\n[3] Consultar contato pelo nome\n[4] Excluir contato\n[5] Sair\n");
}

void opcao_incluir() {
    int opcao;
    char nome[100];
    char telefone[20];
    int tamanho = 0;
    int valido = 1;

    limpar_terminal();

    printf("=====================================\n");
    printf("             Incluir                 \n");
    printf("=====================================\n\n");

    printf("[1] Incluir contato\n");
    printf("[2] Voltar\n\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    if (opcao == 2) {
        return;
    }

    printf("\nNome do contato: ");
    scanf(" %99[^\n]", nome);

    printf("Telefone do contato: ");
    scanf("%19s", telefone);

    while (telefone[tamanho] != '\0') {
        if (!isdigit(telefone[tamanho])) {
            valido = 0;
        }
        tamanho++;
    }

    if (tamanho != 10 && tamanho != 11) {
        valido = 0;
    }

    if (!valido) {
        printf("\nTelefone invalido!\n");
        printf("Digite apenas numeros com 10 ou 11 digitos.\n");
        return;
    }

    printf("\nContato cadastrado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("Telefone: %s\n\n", telefone);

    printf("[1] Incluir outro contato\n");
    printf("[2] Voltar ao menu\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        opcao_incluir();
    }
}

int main() {
    int opcao = 0;

    while (1) {
        mostrar_menu();

        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            opcao_incluir();
            break;
        case 2:
            printf("Fazer para Listar\n");
            break;
        case 3:
            printf("Fazer para consultar\n");
            break;
        case 4:
            printf("Fazer para Excluir\n");
            break;
        case 5:
            printf("Mensagem de fechar aqui\n");
            return 0;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}