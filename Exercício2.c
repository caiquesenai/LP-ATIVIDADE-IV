#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>



struct Aluno
{
    char nome[200];
    char dataNascimento[200];
    float nota1;
    float nota2;
    float media;
};

void limpatela()
{
    system("cls||Clear");
}

float calcularMedia(struct Aluno *aluno)
{
    return (aluno[0].nota1 + aluno[0].nota2) / 2;
}


char *verificarAprovacao(struct Aluno *aluno)
{
    return (aluno[0].media >= 7) ? "Aprovado" : "Reprovado";
}

int main()
{
setlocale(LC_ALL, "portuguese");
    struct Aluno alunos[5];
int i;
    for ( i = 0; i < 5; ++i)
    {
        printf("Forneça os dados do aluno:\n");

        printf("%d° Aluno :\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Data de Nascimento: ");
        scanf("%s", alunos[i].dataNascimento);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        // Calculando a média
        alunos[i].media = calcularMedia(&alunos[i]);

        printf("---------------------------\n");
    }

    limpatela();


    // Exibindo os resultados
    for ( i = 0; i < 5; ++i)
    {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);
        printf("Situação: %s\n", verificarAprovacao(&alunos[i]));
        printf("---------------------------\n");
    }
   
   
    getchar();
    return 0;
}
