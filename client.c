#include <stdio.h>
#include <rpc/rpc.h>
#include "calculadora.h"

int main(int argc, char *argv[]) {
    CLIENT *meuClient;
    int *repostaServidor;
    char *ipServidor = argv[1];

    if(argc !=  2) {
        printf("Sintaxe incorreta (Utilize: ./cliente <IP DO SERVIDOR>)\n");
        exit(1);
    }

    meuClient = clnt_create(ipServidor, calculadora, calculadora_versao_1, "tcp");

    if(meuClient == NULL) {
        clnt_pcreateerror(ipServidor);
        exit(1);
    }

    int n;
    printf("Digite n: ");
    scanf("%d", &n);

    int operacao;
    printf("Escolha a operacao (0) Subtrai e (1) soma um: ");
    scanf("%d", &operacao);

    switch (operacao)
    {
        case(0):
            repostaServidor = subtrai_1(&n, meuClient);
        break;
        case(1):
            repostaServidor = soma_1(&n, meuClient);
        break;
    }

    if(repostaServidor == NULL) {
        clnt_perror(meuClient, argv[1]);
        exit(1);
    }

    printf("A resposta do servidor foi = %d\n", *repostaServidor);
    return 0;
}