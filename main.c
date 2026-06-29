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

int main()
{
    char opcao = '0';

    while (1)
    {
        limpar_terminal();
        mostrar_menu();

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
            printf("Fazer para consultar\n");
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

void adiconar_contato()
{
    char nome[100];
    char telefone[20];
    int tamanho = 0;
    int valido = 1;
    char opcao;

    printf("\nNome do contato: ");
    scanf(" %99[^\n]", nome);

    printf("Telefone do contato: ");
    scanf("%19s", telefone);

    while (telefone[tamanho] != '\0')
    {
        if (!isdigit(telefone[tamanho]))
        {
            valido = 0;
        }
        tamanho++;
    }

    if (tamanho != 10 && tamanho != 11)
    {
        valido = 0;
    }

    if (!valido)
    {
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
    scanf(" %c", &opcao);
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
    char telefone[12] = "";

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

    if (total_contatos < 1) {
        printf("Nenhum contato adiconado.");
        Sleep(2000);
        return;
    }
    while (1) {
        limpar_terminal();
        titulo("Contatos");

        for(int i = 0; i < total_contatos; i++) {
            printf("Contato %i -> Nome: %s | Tel: %s\n", i + 1, lista_contatos[i][0], lista_contatos[i][1]);
        }
        linha();

        printf("[0] Excluir\n[1] Sair\n");

        linha();

        printf("Digite sua opcao: ");

        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            limpar_terminal();
            printf("Retornando para o menu principal!");
            Sleep(2000);
            return;
            break;
        default:
            break;
        }
    }

}

void linha() {
    printf("=====================================\n");
}