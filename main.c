#include <stdlib.h>
#include <stdio.h>

void limpar_termial() {
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
    limpar_termial();

    printf("=====================================\n");
    printf("             Incluir                 \n");
    printf("=====================================\n");
    
}

int main() {
    int opcao = 0;


    while (1) {
        mostrar_menu();
        printf("Digite sua opção: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            opcao_incluir();
            break;
        case 2:
            printf("Fazer para Listar");
            break;
        case 3:
            printf("Fazer para consultar");
            break;
        case 4:
            printf("Fazer para Excluir");
            break;
        case 5:
            printf("Mensagem de fechar aqui");
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}