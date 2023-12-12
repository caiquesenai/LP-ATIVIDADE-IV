#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

struct Funcionario
{
    char nome[200];
    char cargo[200];
    float salario;
};

float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, char cargoAlvo[])
{
    float somaSalarios = 0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; ++i)
    {

        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0)
        {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0)
    {
        return somaSalarios / contador;
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Funcionario programadores[200];

    int numFuncionarios = 0;
    char cargoAlvo[200];

    int escolha;

    do
    {
        printf("\nOpções\n");
        printf("1. Adicionar um programador\n");
        printf("2. Calcular a media salarial e sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (numFuncionarios < 10)
            {
                system("cls || clear");
                printf("Digite o nome do programador %d: ", numFuncionarios + 1);
                scanf("%s", programadores[numFuncionarios].nome);

                printf("Digite o cargo do programador %d: ", numFuncionarios + 1);
                scanf("%s", programadores[numFuncionarios].cargo);

                printf("Digite o salario do programador %d: ", numFuncionarios + 1);
                scanf("%f", &programadores[numFuncionarios].salario);

                numFuncionarios++;
            }
           
            break;

        case 2:
            if (numFuncionarios > 0)
            {
                system("cls || clear");
                printf("Digite o cargo para calcular a media salarial: ");
                scanf("%s", cargoAlvo);

                float mediaSalarial = calcularMediaSalarial(programadores, numFuncionarios, cargoAlvo);

                if (mediaSalarial > 0)
                {
                    printf("A media salarial dos %s na empresa e: %.2f\n", cargoAlvo, mediaSalarial);
                }
                else
                {
                    printf("Nenhum %s encontrado na empresa.\n", cargoAlvo);
                }
            }
            else
            {
                printf("Nenhum programador cadastrado.\n");
            }
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 2);

    getchar();
    return 0;
}
