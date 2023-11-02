#include <stdio.h>
#include <stdbool.h>
#define NUMERO_DE_TENTATIVAS 5

int main()
{
    // imprime cabeçalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numerosecreto = 42;
    int chute;
    bool ganhou = false;
    int tentativas = 1;
    double pontos = 1000;

    while (!ganhou)
    {
        printf("Tentativa %d de %d.\n", tentativas, NUMERO_DE_TENTATIVAS);
        printf("Qual é o seu chute: ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d.\n", chute);

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if (chute < 0)
        {
            printf("Você não pode chutar um número negativo.");
            continue;
        }
        else if (acertou)
        {
            printf("Parabéns. Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            ganhou = true;
            break;
        }
        else
        {
            double pontosperdidos = (double)(chute - numerosecreto) / 2;
            pontos -= pontosperdidos;
            printf("Você errou!\n");
            printf("Mas não desanime, tente novamente!\n");
            if (maior)
            {
                printf("Seu chute foi maior do que o número secreto.\n");
            }
            else
            {
                printf("Seu chute foi menor do que o número secreto.\n");
            }
        }
        if (tentativas == 5)
        {
            break;
        }
        tentativas += 1;
    }

    printf("Fim de jogo! Você acertou em %d tentativa(s).\n", tentativas);
    printf("Você terminou o jogo com %.1f pontos!\n", pontos);

    return 0;
}
