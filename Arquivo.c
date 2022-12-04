#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    int op;
    do
    {
        system("CLS");
        printf("Escolha:\n");
        printf("1 - exercicio 01\n");
        printf("2 - exercicio 02\n");
        printf("3 - exercicio 03\n");
        printf("4 - exercicio 04\n");
        printf("0 - Sair do programa\n");
        scanf("%i",&op);
        switch(op)
        {
        case 0:
            break;
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
        default:
            printf("Op o inv lida!\n");
        }
        system("pause");
    }
    while (op!=0);
    return 0;
}
int ex01()
{
    FILE * letraa;
    int i;
    double Fib, Fibb, Fibc;
    Fib=0;
    Fibb=1;
    if((letraa = fopen("letraa.txt","w")) == NULL)
    {
        printf("\aErro de abertura! \n");
    }
    else
    {
        for(i=0; i<=63; i++)
        {
            Fibc=Fibb+Fib;
            Fib=Fibb;
            Fibb=Fibc;
            fprintf(letraa, "\n%.0f", Fib);
        }
        fprintf(letraa, " ");
        fclose(letraa);
        printf("Primeiros 64 valores de fibonacci gravados na pasta letraa.txt com sucesso!\n\n");
    }
}
int ex02()
{
    long long int a;
    int par, impar;
    FILE *letraa, *pares, *impares;
    if((letraa = fopen("letraa.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        pares = fopen("pares.txt","w");
        impares = fopen("impares.txt","w");
        while(a!=10610209857723)
        {
            fscanf(letraa,"%lli",&a);
            if(a%2==0)
            {
                fprintf(pares, "%lli\n",a);
            }
            if(a%2!=0)
            {
                fprintf(impares, "%lli\n",a);
            }
        }
        fclose(pares);
        fclose(impares);
        fclose(letraa);
        printf("Valores pares e impares separados e gravados com sucesso!\n\n");
    }
}
int ex03()
{
    long long int a;
    FILE *letraa, *primo;
    if((letraa = fopen("letraa.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        primo = fopen("primo.txt","w");
        while(a!=10610209857723)
        {
            fscanf(letraa,"%lli",&a);
            if(a%2==0 && a!=2 && a!=1 || a%3==0 && a!=3 && a!=1 || a%5==0 && a!=5
                    && a!=1)
            {
                continue;
            }
            else
            {
                fprintf(primo, "%lli\n",a);
            }
        }
        fclose(primo);
        printf("Valores primos separados e gravados com sucesso!\n\n");
    }
}
int ex04()
{
    long long int a, numb;
    int conjval, posinum;
    FILE *letraa;
    posinum=0;
    conjval=0;
    if((letraa = fopen("letraa.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        while(conjval!=-1)
        {
            printf("Qual o valor deseja buscar: \n");
            scanf("%i",&conjval);
            letraa = fopen("letraa.txt","r");
            while(!feof(letraa))
            {
                fscanf(letraa,"%lli",&a);
                posinum++;
                if(conjval==a)
                {
                    printf("O valor %i esta no arquivo na posicao %i\n\n\n",
                           conjval, posinum);
                }
                if(numb<conjval && conjval<a)
                {
                    printf("O valor %i nao esta no arquivo, valores mais proximos:%lli e %lli\n\n\n", conjval, numb, a);
                }
                numb=a;
            }
            system("pause");
            system("CLS");
            printf("Para parar a busca digite -1\n");
            posinum=0;
            fclose(letraa);
        }
        system("CLS");
        fclose(letraa);
    }
}
