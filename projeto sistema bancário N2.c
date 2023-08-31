// Sistema bancário - Vinicius Samuel e Jhone do Vale

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTAS 100

// Definição da estrutura da conta bancária
typedef struct {
    int numeroConta;
    char tipoConta[20];
    char titularConta[50];
    char cpf[12];
    char agencia[10]; 
    char endereco[100]; 
    double saldo;
} Conta;
// Declaração do array de contas e contador de contas
Conta contas[MAX_CONTAS];
int numContas = 0;

// Função para criar uma nova conta
void criarConta() {
    if (numContas < MAX_CONTAS) {
        Conta novaConta;
        printf("Digite o número da conta: ");
        scanf("%d", &novaConta.numeroConta);
            printf("Digite o tipo de conta (1 para POUPANÇA, 2 para CORRENTE): ");
    int tipoOpcao;
    scanf("%d", &tipoOpcao);

    if (tipoOpcao == 1) {
        strcpy(novaConta.tipoConta, "POUPANÇA");
    } else if (tipoOpcao == 2) {
        strcpy(novaConta.tipoConta, "CORRENTE");
    } else {
        printf("Opção inválida. O tipo foi definido como N/D.\n");
        strcpy(novaConta.tipoConta, "N/D");
    }
        printf("Digite o nome do titular da conta: ");
        scanf("%s", novaConta.titularConta);
        printf("Digite o CPF do titular da conta (sem pontos ou traços): ");
        scanf("%s", novaConta.cpf);
        printf("Digite a agência da conta: ");
        scanf("%s", novaConta.agencia); 
        printf("Digite o endereço do titular da conta: ");
        scanf(" %[^\n]s", novaConta.endereco);
        novaConta.saldo = 0.0;
        contas[numContas++] = novaConta;
        printf("Conta criada com sucesso!\n");
    } else {
        printf("Limite máximo de contas atingido.\n");
    }
}

// Função para exibir informações de uma conta
void exibirConta(int numeroConta) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            printf("Número da Conta: %d\n", contas[i].numeroConta);
            printf("Tipo de Conta: %s\n", contas[i].tipoConta);
            printf("Titular da Conta: %s\n", contas[i].titularConta);
            printf("CPF do Titular: %s\n", contas[i].cpf);
            printf("Agência: %s\n", contas[i].agencia);
            printf("Endereço: %s\n", contas[i].endereco);
            printf("Saldo: %.2f\n", contas[i].saldo);
            return;
        }
    }
    printf("Conta não encontrada.\n");
}
// Função para remover uma conta
void removerConta(int numeroConta) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            for (int j = i; j < numContas - 1; j++) {
                contas[j] = contas[j + 1];
            }
            numContas--;
            printf("Conta removida com sucesso!\n");
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

// Função para creditar um valor em uma conta
void creditarConta(int numeroConta, double valor) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            contas[i].saldo += valor;
            printf("Crédito realizado com sucesso!\n");
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

// Função para debitar um valor de uma conta
void debitarConta(int numeroConta, double valor) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            if (contas[i].saldo >= valor) {
                contas[i].saldo -= valor;
                printf("Débito realizado com sucesso!\n");
            } else {
                printf("Saldo insuficiente.\n");
            }
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

// Função para renderizar juros em uma conta de poupança
void renderJuros(int numeroConta, double taxaJuros) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            if (strcmp(contas[i].tipoConta, "POUPANÇA") == 0) {
                double juros = contas[i].saldo * taxaJuros / 100;
                contas[i].saldo += juros;
                printf("Juros renderizados com sucesso!\n");
            } else {
                printf("Essa operação só é permitida em contas do tipo POUPANÇA.\n");
            }
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

// Função para transferir um valor entre duas contas
void transferirValor(int numeroContaDebito, int numeroContaCredito, double valor) {
    Conta *contaDebito = NULL;
    Conta *contaCredito = NULL;

    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroContaDebito) {
            contaDebito = &contas[i];
        }
        if (contas[i].numeroConta == numeroContaCredito) {
            contaCredito = &contas[i];
        }
    }
// Verifica se as contas foram encontradas
    if (contaDebito == NULL || contaCredito == NULL) {
        printf("Pelo menos uma das contas não foi encontrada.\n");
        return;
    }
// Verifica se há saldo suficiente na conta de débito
    if (contaDebito->saldo >= valor) {
        contaDebito->saldo -= valor;
        contaCredito->saldo += valor;
        printf("Transferência realizada com sucesso!\n");
    } else {
        printf("Saldo insuficiente na conta de débito.\n");
    }
}

// Função para listar todas as contas e suas informações
void listarContas() {
    printf("Lista de Contas:\n");
    for (int i = 0; i < numContas; i++) {
        printf("Número da Conta: %d | Tipo: %s | Titular: %s | CPF: %s\n", 
               contas[i].numeroConta, contas[i].tipoConta, contas[i].titularConta, contas[i].cpf);
        printf("Agência: %s | Endereço: %s\n", contas[i].agencia, contas[i].endereco);
        printf("Saldo: %.2f\n", contas[i].saldo);
    }
}


// Função Principal
int main() {
    int escolha;
    do {    // Exibição do menu
        printf("|********************************************************************|\n");
        printf("|                                                                    |\n");
        printf("|--------------------------SISTEMA BANCÁRIO--------------------------|\n");
        printf("|                                                                    |\n");
        printf("|********************************************************************|\n");
        printf("                                     \n");
        printf("                                     \n");
        printf("|---------------MENU----------------|\n");
        printf("|-------------PRINCIPAL-------------|\n");
        printf("|                                   |\n");
        printf("|  ➊ Criar Conta                    |\n");
        printf("|  ➋ Consultar Conta                |\n");
        printf("|  ➌ Remover Conta                  | \n");
        printf("|  ➍ Creditar                       |\n");
        printf("|  ➎ Debitar                        |\n");
        printf("|  ➏ Render Juros                   |\n");
        printf("|  ➐ Efetuar Transferência          |\n");
        printf("|  ➑ Listar Contas                  |\n");
        printf("|  ➒ Sair do Sistema                |\n");
        printf("|-----------------------------------|\n");
        
        printf(" Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                criarConta();
                break;
            case 2:
                printf("Digite o número da conta a ser consultada: ");
                int numeroConta;
                scanf("%d", &numeroConta);
                exibirConta(numeroConta);
                break;
            case 3:
                printf("Digite o número da conta a ser removida: ");
                int contaARemover;
                scanf("%d", &contaARemover);
                removerConta(contaARemover);
                break;
            case 4:
                printf("Digite o número da conta para creditar: ");
                int contaParaCreditar;
                scanf("%d", &contaParaCreditar);
                printf("Digite o valor a ser creditado: ");
                double valorCredito;
                scanf("%lf", &valorCredito);
                creditarConta(contaParaCreditar, valorCredito);
                break;
            case 5:
                printf("Digite o número da conta para debitar: ");
                int contaParaDebitar;
                scanf("%d", &contaParaDebitar);
                printf("Digite o valor a ser debitado: ");
                double valorDebito;
                scanf("%lf", &valorDebito);
                debitarConta(contaParaDebitar, valorDebito);
                break;
            case 6:
                printf("Digite o número da conta para render juros: ");
                int contaParaRenderizarJuros;
                scanf("%d", &contaParaRenderizarJuros);
                printf("Digite a taxa de juros: ");
                double taxaJuros;
                scanf("%lf", &taxaJuros);
                renderJuros(contaParaRenderizarJuros, taxaJuros);
                break;
            case 7:
                printf("Digite o número da conta de débito: ");
                int numeroContaDebito;
                scanf("%d", &numeroContaDebito);
                printf("Digite o número da conta de crédito: ");
                int numeroContaCredito;
                scanf("%d", &numeroContaCredito);
                printf("Digite o valor a ser transferido: ");
                double valorTransferencia;
                scanf("%lf", &valorTransferencia);
                transferirValor(numeroContaDebito, numeroContaCredito, valorTransferencia);
                break;
            case 8:
                listarContas();
                break;
            case 9:
                printf("Saindo do Sistema.\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (escolha != 9);

    return 0;
}




