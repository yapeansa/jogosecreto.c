#include <stdio.h>

int main()
{
    // imprime cabeçalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numerosecreto = 42;
    int chute;

    printf("Qual é o seu chute: ");
    scanf("%d", &chute);
    printf("Seu chute foi: %d.\n", chute);

    int acertou = (chute == numerosecreto);

    if (acertou)
    {
        printf("Parabéns. Você acertou!\n");
        printf("Jogue de novo, você é um bom jogador!\n");
    }
    else
    {
        printf("Você errou!\n");
        printf("Mas não desanime, tente novamente!\n");
        if (numerosecreto > chute)
        {
            printf("O número secreto é menor do que %d.\n", chute);
        }
        else
        {
            printf("O número secreto é maior do que %d.\n", chute);
        }
    }

    return 0;
}
