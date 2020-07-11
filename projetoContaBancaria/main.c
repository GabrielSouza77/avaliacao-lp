#include <stdio.h>
#include <stdlib.h>

#define qtdClientes 3
#define opSaque 1
#define opDeposito 2

 typedef struct {
        char nome[256];
        int cpf;
    } Cliente;

 typedef struct {
        int numero_da_conta;
        Cliente cliente;
        float saldo;
    } Conta;

int main(){

    Cliente clientes[qtdClientes];
    Conta contas[qtdClientes];

    printf("Campos: CPF | Nome | Deposito Inicial \n");
  for(int i = 0; (i < qtdClientes) ; i++){
    printf("\nDados para abertura da conta: ", i + 1);
    scanf("%d %s %f", &clientes[i].cpf, clientes[i].nome,
      &contas[i].saldo);

    contas[i].numero_da_conta = i;
    contas[i].cliente.cpf = clientes[i].cpf;
    fflush(stdin);

    printf("\nCliente: %s Conta: %d Saldo inicial: %.2f \n",
      clientes[i].nome, contas[i].numero_da_conta, contas[i].saldo);
  }

  int operacao;

  int num_conta;
  float valor;
  int sair = 0;

  while (!sair){
    printf("\nInforme a operação: 1-Saque 2-Deposito 3-Sair: ");
    scanf("%d", &operacao);

    if (operacao == opSaque || operacao == opDeposito){
      printf("\nInforme numero-da-conta e valor: ");
      scanf("%d %f", &num_conta, &valor);
      for(int i = 0; (i < qtdClientes); i++){
        if (contas[i].numero_da_conta == num_conta) {
          if (operacao == opSaque){
            contas[i].saldo -= valor;
            printf("\n SAQUE: %.2f", valor);
          }
          if (operacao == opDeposito){
            contas[i].saldo += valor;
            printf("\n DEPOSITO: %.2f", valor);
          }
          for(int j = 0 ; j < qtdClientes; j++){
            if (clientes[j].cpf == contas[i].cliente.cpf)
              printf("\n Cliente: %s Saldo atual: %.2f",
                clientes[j].nome, contas[i].saldo);
          }
        }
      }
    }else{
      sair = 1;
    }
  }

  getchar();
  return 0;
}
