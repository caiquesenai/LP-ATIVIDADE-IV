#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

struct Contato
{
    char nome[200];
    char numero[200];
    char email[200];
};

void limpatela()
{
    system("cls||Clear");
}

char *buscarTelefone(struct Contato contatos[], int tamanho, char *nome)
{

    int i;

    for (i = 0; i < tamanho; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            return contatos[i].numero;
        }
    }
    return "Contato inexistente";
}

struct Contato contatos[3];

int main()
{
    setlocale(LC_ALL, "portuguese");

    char nomePesquisado[200];
    int i;
    int codigo = 0;
    char numeroEncontrado[200];

    for (i = 0; i < 3; i++)
    {

        printf("Digite o nome do  %d° contato: ", i + 1);
        scanf("%s", contatos[i].nome);
        printf("Digite o número do %d° contato: ", i + 1);
        scanf("%s", contatos[i].numero);
        printf("Digite o email do %d° contato:", i + 1);
        scanf("%s", contatos[i].email);
    }

    do
    {
        limpatela();
        printf("Agenda:\n");

        printf("\nDigite o nome do contato para buscar o número de telefone: ");
        scanf("%s", nomePesquisado);

        char *numeroEncontrado = buscarTelefone(contatos, 3, nomePesquisado);

        if (numeroEncontrado != "Contato inexistente")
        {
            printf("Número de telefone de %s: %s\n", nomePesquisado, numeroEncontrado);
        }
        else
        {
            printf(" Contato inexistente.\n");
        }

        printf("\nPara procurar mais um nome digite 1\n");
        printf("Para sair da agenda digite 2\n");
        scanf("%d", &codigo);

    } while (codigo != 2);

    getchar();
    return 0;
}
