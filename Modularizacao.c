#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();

void menu();
void procedimento_ex02();
void procedimento_ex03();
void procedimento_ex04(int);
int procedimento_ex05(int);
int procedimento_ex06(int);
int ler_qnt();

int n;
float s;

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
        case 4:
            ex04();
            break;
        case 5:
            ex05();
            break;
        case 6:
            ex06();
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
    printf("Programas para ler:\nS = 1/2 + 1/4 - 2/6 + 3/8 - 5/10 + 8/12 - 13/14 + 21/16 - ...\n");
    printf("1 - Em um programa principal.\n");
    printf("2 - Utilizando um procedimento.\n");
    printf("3 - Utilizando procedimento variáveis globais N e S.\n");
    printf("4 - Utilizando procedimento passando N como parâmetro e retornando o valor de S em um outro parâmetro.\n");
    printf("5 - Utilizando função retornando o valor de S e a variável global N\n");
    printf("6 - Utilizando função passando N como parâmetro e retornando o valor de S\n");
    printf("9 - Sair do programa\n");
}

void ex01()
{
    float termo,s=1.0/2;
    int den=4,sinal=1,qnt_termos,num=1,n1,n2=1,n3=1;
    printf("Digite a quantidade de termos desejada da série: ");
    scanf("%d",&qnt_termos);
    if(qnt_termos>1)
    {
        termo=s;
        printf("%f\n",termo);
        for(int cont=2; cont<=qnt_termos; cont++)
        {
            termo=((float)num/den)*(sinal);
            printf("%f\n",termo);
            s+=termo;
            n1=n2;
            n2=n3;
            n3=n1+n2;
            num = n3;
            den += 2;
            sinal*=(-1);
        }
    }
    printf("Para %d termos, o valor de S é aproximadamente %f\n",qnt_termos,s);
    return 0;
}
void ex02()
{
    procedimento_ex02();
    return 0;
}
void ex03()
{
    float termo;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1;
    printf("Digite a quantidade de termos desejada da série: ");
    scanf("%d",&n);
    s=1.0/2;
    if(n>1)
    {
        procedimento_ex03();
    }
    printf("Para %d termos, o valor de S é aproximadamente %f\n",n,s);
    return 0;
}
void ex04()
{
    float termo;
    int n,den=4,sinal=1,num=1,n1,n2=1,n3=1;
    printf("Digite a quantidade de termos desejada da série: ");
    scanf("%d",&n);
    s=1.0/2;
    if(n>1)
    {
        procedimento_ex04(n);
    }
    printf("Para %d termos, o valor de S é aproximadamente %f\n",n,s);
    return 0;
}
void ex05()
{
    float termo;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1,qnt;
    qnt=ler_qnt();
    s=1.0/2;
    if(qnt<=1)
    {
        printf("Para %d termo(s), o valor de S é aproximadamente %f\n",qnt,s);
    }
    if(qnt>1)
    {
        procedimento_ex05(qnt);
    }
    return 0;
}
void ex06()
{
    float termo,soma;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1,qnt;
    qnt=ler_qnt();
    soma=1.0/2;
    if(qnt<=1)
    {
        printf("Para %d termo(s), o valor de S é aproximadamente %f\n",qnt,soma);
    }
    if(qnt>1)
    {
        soma=procedimento_ex06(qnt);
        printf("Para %d termos, o valor de S é aproximadamente %f\n",n,soma);
    }
    return 0;
}


// PROCEDIMENTOS E FUNÇÕES ULTILIZADOS
void procedimento_ex02()
{
    float termo,s=1.0/2;
    int den=4,sinal=1,qnt_termos,num=1,n1,n2=1,n3=1;
    printf("Digite a quantidade de termos desejada da série: ");
    scanf("%d",&qnt_termos);
    if(qnt_termos>1)
    {
        termo=s;
        printf("%f\n",termo);
        for(int cont=2; cont<=qnt_termos; cont++)
        {
            termo=((float)num/den)*(sinal);
            printf("%f\n",termo);
            s+=termo;
            n1=n2;
            n2=n3;
            n3=n1+n2;
            num = n3;
            den += 2;
            sinal*=(-1);
        }
    }
    printf("Para %d termos, o valor de S é aproximadamente %f\n",qnt_termos,s);
}
void procedimento_ex03()
{
    float termo;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1;
    s=1.0/2;
    termo=s;
    printf("%f\n",termo);
    for(int cont=2; cont<=n; cont++)
    {
        termo=((float)num/den)*(sinal);
        printf("%f\n",termo);
        s+=termo;
        n1=n2;
        n2=n3;
        n3=n1+n2;
        num = n3;
        den += 2;
        sinal*=(-1);
    }
}
void procedimento_ex04(int qnt_termos)
{
    float termo;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1;
    s=1.0/2;
    termo=s;
    printf("%f\n",termo);
    for(int cont=2; cont<=qnt_termos; cont++)
    {
        termo=((float)num/den)*(sinal);
        printf("%f\n",termo);
        s+=termo;
        n1=n2;
        n2=n3;
        n3=n1+n2;
        num = n3;
        den += 2;
        sinal*=(-1);
    }
}
int procedimento_ex05(int qnt_termos)
{
    float termo,soma;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1;
    soma=1.0/2;
    termo=soma;
    printf("%f\n",termo);
    for(int cont=2; cont<=qnt_termos; cont++)
    {
        termo=((float)num/den)*(sinal);
        printf("%f\n",termo);
        soma+=termo;
        n1=n2;
        n2=n3;
        n3=n1+n2;
        num = n3;
        den += 2;
        sinal*=(-1);
    }
    printf("Para %d termos, o valor de S é aproximadamente %f\n",n,soma);
    return soma;
}
int procedimento_ex06(int qnt_termos)
{
    float termo;
    int den=4,sinal=1,num=1,n1,n2=1,n3=1;
    s=1.0/2;
    termo=s;
    printf("%f\n",termo);
    for(int cont=2; cont<=qnt_termos; cont++)
    {
        termo=((float)num/den)*(sinal);
        printf("%f\n",termo);
        s+=termo;
        n1=n2;
        n2=n3;
        n3=n1+n2;
        num = n3;
        den += 2;
        sinal*=(-1);
    }
    printf("soma=%f.\n\n",s);
    return s;
}
int ler_qnt()
{
    printf("Digite a quantidade de termos desejada da série: ");
    scanf("%d",&n);
    return n;
}
/* BANCO DE TESTES
1 = 0,5
2 = 0,75
3 = 0,41666666666666666666666666666667
4 = 0,79166666666666666666666666666667
5 = 0,29166666666666666666666666666667
6 = 0,95833333333333333333333333333333
7 = 0,0297619047619047619047619047619
8 = 1,3422619047619047619047619047619
9 = -0,54662698412698412698412698412698
10 = 2,203373015873015873015873015873
*/
