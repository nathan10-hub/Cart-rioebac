#include <stdio.h>    // Biblioteca para fun��es de entrada e sa�da (ex: printf, scanf, fopen)
#include <stdlib.h>   // Biblioteca para aloca��o de mem�ria, controle de processos (ex: system, malloc)
#include <locale.h>   // Biblioteca para definir localiza��o/regi�o (ex: para acentua��o correta)
#include <string.h>   // Biblioteca para manipula��o de strings (ex: strcpy)

// Fun��o respons�vel por cadastrar os usu�rios
int registro()
{
    // Cria��o de vari�veis do tipo string (vetores de caracteres)
    char arquivo[40];     // Nome do arquivo (ser� o CPF do usu�rio)
    char cpf[40];         // Armazena o CPF do usu�rio
    char nome[40];        // Armazena o nome do usu�rio
    char sobrenome[40];   // Armazena o sobrenome do usu�rio
    char cargo[40];       // Armazena o cargo do usu�rio
    
    // Solicita o CPF ao usu�rio
    printf ("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);  // L� o CPF como string

    // Copia o valor do CPF para a vari�vel 'arquivo' (o nome do arquivo ser� o CPF)
    strcpy(arquivo, cpf);

    // Cria e abre um novo arquivo com o nome igual ao CPF (modo de escrita "w" - sobrescreve se j� existir)
    FILE *file;
    file = fopen(arquivo, "w");

    // Escreve o CPF no arquivo
    fprintf(file, cpf);
    fclose(file); // Fecha o arquivo

    // Reabre o arquivo no modo de adicionar ("a") e adiciona uma v�rgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o nome do usu�rio
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // L� o nome como string

    // Adiciona o nome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    // Adiciona uma v�rgula ap�s o nome
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o sobrenome do usu�rio
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    // Adiciona o sobrenome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    // Adiciona uma v�rgula ap�s o sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o cargo do usu�rio
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // Adiciona o cargo ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    // Pausa o sistema para que o usu�rio possa ver a mensagem
    system("pause");
}

// Fun��o respons�vel por consultar os dados de um usu�rio
int consulta()
{
    // Define a localidade como Portugu�s para tratar acentua��o corretamente
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];          // Vari�vel para armazenar o CPF digitado
    char conteudo[200];    // Buffer para armazenar o conte�do lido do arquivo

    // Solicita o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Tenta abrir o arquivo com o nome igual ao CPF (modo leitura "r")
    FILE *file;
    file = fopen(cpf, "r");

    // Verifica se o arquivo foi encontrado
    if(file == NULL)
    {
        // Exibe mensagem de erro se o arquivo n�o for localizado
        printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!.\n");
    }

    // Enquanto houver conte�do no arquivo, imprime o conte�do na tela
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    // Pausa o sistema
    system("pause");
}

// Fun��o respons�vel por deletar os dados de um usu�rio
int deletar()
{
    char cpf[40];  // Vari�vel para armazenar o CPF a ser deletado

    // Solicita o CPF do usu�rio a ser deletado
    printf("Digite o CPF do usu�rio a ser deletado:");
    scanf("%s", cpf);

    // Remove o arquivo com nome igual ao CPF
    remove(cpf);

    // Verifica se o arquivo foi realmente removido tentando abri-lo novamente
    FILE *file;
    file = fopen(cpf, "r");

    // Se o arquivo n�o for encontrado, confirma que o usu�rio foi deletado
    if (file == NULL)
    {
        printf("O usu�rio n�o se encontra no sistema!.\n");
        system("pause");
    }
}

// Fun��o principal (ponto de entrada do programa)
int main()
{
    int opcao = 0; // Armazena a op��o do menu escolhida pelo usu�rio

    // Loop infinito do menu principal 
    while (1) // Executa indefinidamente at� que o usu�rio feche o programa manualmente
    {
        system("cls"); // Limpa a tela

        // Define a linguagem para portugu�s
        setlocale(LC_ALL, "Portuguese");

        // Exibe o menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o: ");

        // L� a op��o escolhida pelo usu�rio
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela antes de executar a op��o

        // Verifica qual op��o foi escolhida
        switch(opcao)
        {
            case 1:
                registro();  // Chama a fun��o de registro
                break;

            case 2:
                consulta();  // Chama a fun��o de consulta
                break;

            case 3:
                deletar();   // Chama a fun��o de deletar
                break;

            default:
                // Caso o usu�rio digite uma op��o inv�lida
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }
}

