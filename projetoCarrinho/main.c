#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int  codigo;
        char  nome[100];
        float preco;
} Produto;

typedef struct {
        int num_item;
        int cod_prod;
        int qtd;
        float preco_Total;

} Carrinho;

#define qtdProdutos 2

int main(){

        Produto produtos[qtdProdutos];
        Carrinho carrinho[qtdProdutos];

        carrinho[qtdProdutos].preco_Total = 0;

        printf("Campos: codigo-do-produto nome preco\n");
        for(int i=0; (i < qtdProdutos); i++){
                printf("\nInforme os dados do produto: ",i+1);
                scanf("%d %s %f",&produtos[i].codigo,produtos[i].nome,
                        &produtos[i].preco);
        }

        for(int i=0; (i < qtdProdutos); i++){
                printf("\n%d\t%s R$ %.2f", produtos[i].codigo,
                        produtos[i].nome,produtos[i].preco);
        }

        int codigo_digitado;

        for(int i = 0; (i < qtdProdutos); i++){
        printf("\nInforme o codigo do produto: ");
        scanf("%d", &codigo_digitado);

        for(int i = 0; (i < qtdProdutos); i++){
                if (produtos[i].codigo == codigo_digitado) {
                        carrinho[i].preco_Total += produtos[i].preco;
                }
        }
        printf("\nPreco Total: R$ %.2f\n", carrinho[i].preco_Total);
    }
        getchar();
        return 0;
}

