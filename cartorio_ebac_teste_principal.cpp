#include <stdio.h>    // Biblioteca para funções de entrada e saída (ex: printf, scanf, fopen)
#include <stdlib.h>   // Biblioteca para alocação de memória, controle de processos (ex: system, malloc)
#include <locale.h>   // Biblioteca para definir localização/região (ex: para acentuação correta)
#include <string.h>   // Biblioteca para manipulação de strings (ex: strcpy)

// Função responsável por cadastrar os usuários
int registro()
{
    // Criação de variáveis do tipo string (vetores de caracteres)
    char arquivo[40];     // Nome do arquivo (será o CPF do usuário)
    char cpf[40];         // Armazena o CPF do usuário
    char nome[40];        // Armazena o nome do usuário
    char sobrenome[40];   // Armazena o sobrenome do usuário
    char cargo[40];       // Armazena o cargo do usuário
    
    // Solicita o CPF ao usuário
    printf ("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);  // Lê o CPF como string

    // Copia o valor do CPF para a variável 'arquivo' (o nome do arquivo será o CPF)
    strcpy(arquivo, cpf);

    // Cria e abre um novo arquivo com o nome igual ao CPF (modo de escrita "w" - sobrescreve se já existir)
    FILE *file;
    file = fopen(arquivo, "w");

    // Escreve o CPF no arquivo
    fprintf(file, cpf);
    fclose(file); // Fecha o arquivo

    // Reabre o arquivo no modo de adicionar ("a") e adiciona uma vírgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o nome do usuário
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // Lê o nome como string

    // Adiciona o nome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    // Adiciona uma vírgula após o nome
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o sobrenome do usuário
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    // Adiciona o sobrenome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    // Adiciona uma vírgula após o sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita o cargo do usuário
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // Adiciona o cargo ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    // Pausa o sistema para que o usuário possa ver a mensagem
    system("pause");
}

// Função responsável por consultar os dados de um usuário
int consulta()
{
    // Define a localidade como Português para tratar acentuação corretamente
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];          // Variável para armazenar o CPF digitado
    char conteudo[200];    // Buffer para armazenar o conteúdo lido do arquivo

    // Solicita o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Tenta abrir o arquivo com o nome igual ao CPF (modo leitura "r")
    FILE *file;
    file = fopen(cpf, "r");

    // Verifica se o arquivo foi encontrado
    if(file == NULL)
    {
        // Exibe mensagem de erro se o arquivo não for localizado
        printf("Não foi possível abrir o arquivo, não foi localizado!.\n");
    }

    // Enquanto houver conteúdo no arquivo, imprime o conteúdo na tela
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    // Pausa o sistema
    system("pause");
}

// Função responsável por deletar os dados de um usuário
int deletar()
{
    char cpf[40];  // Variável para armazenar o CPF a ser deletado

    // Solicita o CPF do usuário a ser deletado
    printf("Digite o CPF do usuário a ser deletado:");
    scanf("%s", cpf);

    // Remove o arquivo com nome igual ao CPF
    remove(cpf);

    // Verifica se o arquivo foi realmente removido tentando abri-lo novamente
    FILE *file;
    file = fopen(cpf, "r");

    // Se o arquivo não for encontrado, confirma que o usuário foi deletado
    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
}

// Função principal (ponto de entrada do programa)
int main()
{
    int opcao = 0; // Armazena a opção do menu escolhida pelo usuário

    // Loop infinito do menu principal 
    while (1) // Executa indefinidamente até que o usuário feche o programa manualmente
    {
        system("cls"); // Limpa a tela

        // Define a linguagem para português
        setlocale(LC_ALL, "Portuguese");

        // Exibe o menu
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");

        // Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela antes de executar a opção

        // Verifica qual opção foi escolhida
        switch(opcao)
        {
            case 1:
                registro();  // Chama a função de registro
                break;

            case 2:
                consulta();  // Chama a função de consulta
                break;

            case 3:
                deletar();   // Chama a função de deletar
                break;

            default:
                // Caso o usuário digite uma opção inválida
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }
}

