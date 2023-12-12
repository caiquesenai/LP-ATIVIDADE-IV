#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct Produto
{
    char nome[200];
    float preco;
    int quantidadeEmEstoque;
};

void limpatela()
{
    system("cls||Clear");
}

float calcularValorTotal(struct Produto *produto)
{
    return produto[0].preco * produto[0].quantidadeEmEstoque;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeComprada;
    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeComprada);

    if (quantidadeComprada > 0 && quantidadeComprada <= produto[0].quantidadeEmEstoque)
    {
        produto[0].quantidadeEmEstoque -= quantidadeComprada;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade inválida ou estoque insuficiente.\n");
    }
}


void consultarEstoque(struct Produto *produto)
{
    printf("Nome: %s\n", produto[0].nome);
    printf("Preço: R$ %.2f\n", produto[0].preco);
    printf("Quantidade em estoque: %d\n", produto[0].quantidadeEmEstoque);
    printf("Valor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Produto meuProduto;
    int opcao;

    printf(meuProduto.nome, "Produto Elástico");
    meuProduto.preco = 10.99;
    meuProduto.quantidadeEmEstoque = 5000;
    limpatela();

    do
    {
        // Exibindo o menu
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        
        limpatela();

        switch (opcao)
        {
        case 1:
            realizarCompra(&meuProduto);
            break;
        case 2:
            consultarEstoque(&meuProduto);
            break;
        case 3:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 3);
    
    getchar();
    return 0;
}
