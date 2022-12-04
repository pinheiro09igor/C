#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ex01();
void ex02();
void ex03();
void menu();
void le_valores();
int funcao_ex02(int, int);
int funcao_ex03(int, int);

int quociente,resto;
float x,y;

int main()
{
    setlocale(LC_ALL,"portuguese");
    int op;
    do
    {
        menu();
        printf("Escolha: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            ex01();
            break;
        case 2:
            ex02();
            break;
        case 3:
            ex03();
            break;
        case 9:
            printf("Até a próxima!\n");
            break;
        default:
            printf("\aOpção inválida\n");
            break;
        }
        printf("\n");
        system("pause");
    }
    while(op!=9);
    return 0;
}

void menu()
{
    system("CLS");
    printf("FUNÇÕES RECURSIVAS\n");
    printf("1 - Faça um programa que peça ao usuários dois valores e imprima o resto inteiro da divisão de X por Y.\n");
    printf("2 - Faça uma função que receba dois parâmetros (passados por valor) e retorne  o resto inteiro da divisão de X por Y.\n");
    printf("3 - Faça uma função RECURSIVA que receba dois parâmetros (passados por valor) e retorne  o resto inteiro da divisão de X por Y.\n");
    printf("9 - Sair do programa\n");
}

void ex01()
{
    printf("Este programa que peça ao usuários dois valores e imprima o resto inteiro da divisão de X por Y.\n");
    le_valores();
    quociente = x/y;
    resto = x - (quociente*y);
    printf("O resto inteiro da divisão de %.2f por %.2f = %d",x,y,resto);
}

void ex02()
{
    printf("Função que receba dois parâmetros (passados por valor) e retorne  o resto inteiro da divisão de X por Y.\n");
    le_valores();
    printf("O resto inteiro da divisão de %.2f por %.2f = %d",x,y,funcao_ex02(x,y));
}

void ex03()
{
    printf("Função RECURSIVA que receba dois parâmetros (passados por valor) e retorne  o resto inteiro da divisão de X por Y.\n");
    le_valores();
    printf("O resto inteiro da divisão de %.2f por %.2f = %d",x,y,funcao_ex03(x,y));
}


// PROCEDIMENTOS E FUNÇÕES ULTILIZADOS

int funcao_ex02(int dividendo, int divisor)
{
    quociente = dividendo/divisor;
    resto = dividendo - (quociente*divisor);
    return resto;
}
int funcao_ex03(int dividendo, int divisor)
{
    if(dividendo < divisor)
        return dividendo;
    else
        return funcao_ex03(dividendo-divisor,divisor);
}
void le_valores()
{
    printf("Digite um valor(x): \n");
    scanf("%f",&x);
    printf("Digite outro valor valor(y): \n");
    scanf("%f",&y);
}

/*
BANCO DE TESTES
1)  x=5,  y=5, resto=0
    x=10, y=7, resto=3
    x=23, y=6, resto=5

2)  x=5,  y=5, resto=0
    x=10, y=7, resto=3
    x=23, y=6, resto=5

3)  x=5,  y=5, resto=0
    x=10, y=7, resto=3
    x=23, y=6, resto=5
*/
