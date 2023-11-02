#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // imprime cabeçalho do nosso jogo
    printf("\n\n");
    printf("          P  /_\\  P                                \n");
    printf("         /_\\_|_|_/_\\                              \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao       \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!   \n");
    printf("    |"
           "  |  |_|  |"
           " |                           \n");
    printf("    |_____| ' _ ' |_____|                           \n");
    printf("          \\__|_|__/                                \n\n");

    int segundos = time(0);
    srand(segundos);
    int numerosecreto = rand() % 100;

    int chute;
    bool ganhou = false;
    int tentativas = 1;
    double pontos = 1000;
    int nivel;
    int numerodetentativas;

    printf("Selecione um nível de dificuldade:\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;
    case 2:
        numerodetentativas = 15;
        break;
    default:
        numerodetentativas = 6;
        break;
    }

    while (!ganhou)
    {
        printf("Tentativa %d de %d.\n", tentativas, numerodetentativas);
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
            ganhou = true;
            break;
        }
        else
        {
            double pontosperdidos = abs(chute - numerosecreto) / (double)2;
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
        if (tentativas == numerodetentativas)
        {
            break;
        }
        tentativas += 1;
    }

    if (ganhou)
    {
        printf("\n");
        printf("             ___________       \n");
        printf("            '._==_==_=_.'      \n");
        printf("            .-\\:      /-.     \n");
        printf("           | (|:.     |) |     \n");
        printf("            '-|:.     |-'      \n");
        printf("              \\::.    /       \n");
        printf("               '::. .'         \n");
        printf("                 ) (           \n");
        printf("               _.' '._         \n");
        printf("            '''''''''''''      \n\n");
        printf("Parabéns. Você acertou!\n");
        printf("Você acertou em %d tentativa(s).\n", tentativas);
        printf("Total de pontos: %.1f.\n", pontos);
        printf("Jogue de novo, você é um bom jogador!\n");
    }
    else
    {
        printf("\n");
        printf("       \\|/ ____ \\|/      \n");
        printf("        @~/ ,. \\~@        \n");
        printf("       /_( \\__/ )_\\      \n");
        printf("          \\__U_/          \n\n");
        printf("Você perdeu! Tente novamente.\n");
    }

    return 0;
}
