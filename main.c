#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

char lista_contatos[50][2][50];
int total_contatos = 0;

void limpar_terminal();
void mensagem_opacao_invalida();
void adiconar_contato();
void mostrar_menu();
void menu_incluir();
void mensagem_saida();
void incluir_contato();
void titulo(char mensagem[]);
void mostrar_contatos();
void excluir_contatos();
void linha();
void pesquisar_contato();

int main()
{
    char opcao = '0';

    while (1)
    {
        limpar_terminal();
        mostrar_menu();

        linha();
        printf("Digite sua opcao: ");

        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            menu_incluir();
            break;
        case '2':
            mostrar_contatos();
            break;
        case '3':
            pesquisar_contato();
            break;
        case '4':
            excluir_contatos();
            break;
        case '5':
            mensagem_saida();
            return 0;
        default:
            opcao = '0';
            mensagem_opacao_invalida();
            break;
        }
    }

    return 0;
}

void limpar_terminal()
{
    if (system("cls") == -1)
    {
        system("clear");
    }
}

void mensagem_opacao_invalida()
{
    limpar_terminal();
    printf("Opcao invalida!\n");
    Sleep(900);
    return;
}

void mostrar_menu()
{
    printf("=====================================\n");
    printf("                Menu                 \n");
    printf("=====================================\n");
    printf("[1] Incluir contato\n[2] Listar Contatos\n[3] Consultar contato pelo nome\n[4] Excluir contato\n[5] Sair\n");
}

void titulo(char mensagem[]) {
    printf("=====================================\n");
    printf("             %s                 \n", mensagem);
    printf("=====================================\n");
}

void menu_incluir()
{
    char opcao;
    while (1)
    {
        limpar_terminal();

        titulo("Incluir");

        printf("[1] Incluir contato\n");
        printf("[2] Voltar\n");

        printf("=====================================\n");

        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '2':
            return;
            break;
        case '1':
            incluir_contato();
            break;
        default:
            mensagem_opacao_invalida();
            break;
        }
    }
}

void mensagem_saida()
{
    limpar_terminal();
    char mensagem[] = "Obrigado por ter usado nosso programa, volte sempre!";
    int quantidade_letras = strlen(mensagem);

    for (int i = 0; i < quantidade_letras; i++)
    {
        printf("%c", mensagem[i]);
        Sleep(100);
    }
}

void incluir_contato()
{
    limpar_terminal();
    titulo("Incluir");

    char nome[50] = "";
    char telefone[16] = "";

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    while (1)
    {
        printf("\nDigite o nome: ");
        fgets(nome, 50, stdin);

        nome[strcspn(nome, "\n")] = '\0';
        if (nome[0] != '\0')
        {
            break;
        }
        printf("Nome invalido!\n");
    }
    printf("Nome aceito: %s\n", nome);
    Sleep(1000);

    limpar_terminal();
    titulo("Incluir");

    while (1)
    {
        printf("\nDigite o telefone: ");
        fgets(telefone, sizeof(telefone), stdin);

        telefone[strcspn(telefone, "\n")] = '\0';
        if (strlen(telefone) >= 10 && strlen(telefone) <= 11)
        {
            break;
        }
        printf("Telefone invalido!\n");
    }
    printf("Telefone aceito: %s\n", telefone);
    Sleep(1000);

    if (total_contatos < 50) {
        
        strcpy(lista_contatos[total_contatos][0], nome);
        
        strcpy(lista_contatos[total_contatos][1], telefone);

        printf("\nContato salvo com sucesso na posicao %i!\n", total_contatos + 1);
        
        total_contatos++;
    } else {
        printf("\nErro: Agenda cheia!\n");
    }
    Sleep(1000);

}

void mostrar_contatos() {
    limpar_terminal();
    if (total_contatos < 1) {
        printf("Nenhum contato adiconado!");
        Sleep(1000);
        return;
    }
    limpar_terminal();
    titulo("Contatos");
    for(int i = 0; i < total_contatos; i++) {
        printf("Contato %i -> Nome: %s | Tel: %s\n", i + 1, lista_contatos[i][0], lista_contatos[i][1]);
    }
    printf("\nAperte ENTER para sair...");

    getchar(); 
    getchar();
}

void excluir_contatos() {
    limpar_terminal();

    char opcao = '0';
    int indice_excluir;

    if (total_contatos < 1) {
        printf("Nenhum contato adiconado.");
        Sleep(2000);
        return;
    }
    while (1) {
        limpar_terminal();
        titulo("Menu Excluir");

        printf("[1] Excluir\n[2] Sair\n");

        linha();

        printf("Digite sua opcao: ");

        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '2':
            limpar_terminal();
            printf("Retornando para o menu principal!");
            Sleep(2000);
            return;
            break;
        case '1':
            limpar_terminal();
            titulo("Excluir");

            for(int i = 0; i < total_contatos; i++) {
                printf("Contato %i -> Nome: %s | Tel: %s\n", i + 1, lista_contatos[i][0], lista_contatos[i][1]);
            }
            linha();
            
            printf("Digite o numero do usuario que deseja excluir: ");
            if (scanf("%d", &indice_excluir) != 1) {
                mensagem_opacao_invalida();
                int c; while ((c = getchar()) != '\n' && c != EOF); 
                break;
            }

            int posicao_matriz = indice_excluir - 1;

            if (posicao_matriz < 0 || posicao_matriz >= total_contatos) {
                mensagem_opacao_invalida();
                break;
            }

            for (int i = posicao_matriz; i < total_contatos - 1; i++) {
                strcpy(lista_contatos[i][0], lista_contatos[i + 1][0]);
                strcpy(lista_contatos[i][1], lista_contatos[i + 1][1]);
            }

            total_contatos--;

            printf("\nContato excluido com sucesso!\n");
            Sleep(2000);
            return; 

            break;
        default:
            opcao = '0';
            mensagem_opacao_invalida();
            break;
        }
    }

}

void pesquisar_contato() {
    limpar_terminal();

    if (total_contatos < 1) {
        printf("Nenhum contato adicionado!");
        Sleep(2000);
        return;
    }

    titulo("Pesquisar Contato");
    char termo_busca[50] = "";
    int c;
    
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nDigite o nome (ou parte dele) para buscar: ");
    fgets(termo_busca, sizeof(termo_busca), stdin);
    termo_busca[strcspn(termo_busca, "\n")] = '\0'; 

    limpar_terminal();
    titulo("Resultados da Busca");

    int encontrados = 0;
    for (int i = 0; i < total_contatos; i++) {

        if (strstr(lista_contatos[i][0], termo_busca) != NULL) {
            printf("Contato %i -> Nome: %s | Tel: %s\n", i + 1, lista_contatos[i][0], lista_contatos[i][1]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum contato encontrado com o termo \"%s\".\n", termo_busca);
    } else {
        printf("\nForam encontrados %d contato(s).\n", encontrados);
    }

    printf("\nPressione ENTER para sair...");
    getchar();
}

void linha() {
    printf("=====================================\n");
}