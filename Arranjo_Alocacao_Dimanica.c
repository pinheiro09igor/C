#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
//ex10();
void ex11();

void imprimeVetor(float *, int);
void menu();
void menu_ex07();
void menorMaior(int **aux8);
void somaDiagonal(int matriz[10][10]);
void recebeMatriz(int **aux11);

int *numAleatorio(int, int), **mat2, matriz[10][10];
float *leVetor (int);

int i, j, a[100], b[100], c[100], x, y, z, cont;
int main()
{
    setlocale(LC_ALL,"portuguese");
    int op, op_ex08=0;
    srand(time(0));
    do
    {
        menu();
        scanf("%i",&op);
        switch(op)
        {
        case 0:
            printf("Até a próxima!\n");
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
        case 5:
            ex05();
            break;
        case 6:
            ex06();
            break;
        case 7:
            op_ex08++;
            ex07();
            break;
        case 8:
            if(op_ex08==0)
            {
                printf("Para rodar o Exercicio 8, é necessario ter rodado o 7 primeiro!!\n\n");
                break;
            }
            else
            {
                ex08();
            }
            break;
        case 9:
            if(op_ex08==0)
            {
                printf("Para rodar o Exercicio 9, é necessario ter rodado o 7 primeiro!!\n\n");
                break;
            }
            else
            {
                ex09();
            }
            break;
        /*case 10:
            ex10();
            break;*/
        case 11:
            if(op_ex08==0)
            {
                printf("Para rodar o Exercicio 11, é necessario ter rodado o 7 primeiro!!\n\n");
                system("pause");
                break;
            }
            else
            {
                ex11();
            }
            break;
        default:
            printf("\aOpção inválida!\n");
        }
        printf("\n");
        system("pause");
    }
    while (op!=0);
    return 0;
}

void menu()
{
    system("CLS");
    printf("Escolha: \n");
    printf(" 1 - Somatório de 1 ate o valor correspondente de cada elemento da matriz A\n");
    printf(" 2 - União dos vetores A e B\n");
    printf(" 3 - Inverssão de Vetores 03\n");
    printf(" 4 - Qte de vezes que os elementos de A apareceram no vetor frequência\n");
    printf(" 5 - Ordene e imprima o vetor A\n");
    printf(" 6 - Programa que leia um valor e chame a função e o procedimentos criados\n");
    printf(" 7 - Matriz de valores aleatorios entre um intervalo determinado\n");
    printf(" 8 - Maior e menor valor da matriz do exercicio 7\n");
    printf(" 9 - Soma dos elementos da diagonal da matriz do exercicio 7\n");
    printf("10 - Posição [i,j] da matriz do exercicio 7\n");
    printf("11 - Verifique de número na matriz do exercicio 7\n");
    printf(" 0 - Sair do programa\n ");
}

void ex01()
{
    int soma=0;
    x=15, y=15;
    printf("\nVetor A: ");
    for(i=0; i<15; i++)
    {
        a[i]=rand()% 51;
        printf("%d  ",a[i]);
    }
    printf("\n");
    for(i=0; i<15; i++)
    {
        soma=0;
        for(j=1; j<=a[i]; j++)
        {
            soma += j;
        }
        b[i]=soma;
        printf("a[%d]=%d - a[%d]=%d\n",i,a[i],i,b[i]);
    }
}

void ex02()
{
    cont=0;
    printf("\nVetor A: ");
    for(i=0; i<10; i++)
    {
        a[i]=rand()% 51;
        printf("%d  ",a[i]);
    }
    printf("\nVetor B: ");
    for(i=0; i<10; i++)
    {
        b[i]=rand()% 51;
        printf("%d  ",b[i]);
    }
    for(i=0; i<10; i++)
    {
        j=0;
        while(j<cont && c[j]!=a[i])
        {
            j++;
        }
        if(j==cont)
        {
            c[cont]=a[i];
            cont++;
        }
    }
    for(i=0; i<10; i++)
    {
        j=0;
        while(j<cont && c[j]!=b[i])
        {
            j++;
        }
        if(j==cont)
        {
            c[cont]=b[i];
            cont++;
        }
    }
    for(i=0; i<cont; i++)
    {
        printf("%i\n", c[i]);
    }
}

void ex03()
{
    float c[20], aux;
    printf("Matriz : ");
    for(i=0; i<20; i++)
    {
        c[i]=((rand()%500)/100.0);
        printf("%.2f\t", c[i]);
    }
    for(i=0; i<10; i++)
    {
        aux=c[i];
        c[i]=c[19-i];
        c[19-i]=aux;
    }
    printf("\nInverso: ");
    for(i=0; i<20; i++)
    {
        printf("%.2f\t", c[i]);
    }
}

void ex04()
{
    x=100;
    y=10;
    printf("Vetor A: ");
    for(i=0; i<100; i++)
    {
        a[i]=(rand()% 10)+1;
        printf("%d  ",a[i]);
    }
    for(i=0; i<y; i++)
    {
        c[i]=0;
    }
    printf("\nVetor Frequência: ");
    for(i=0; i<y; i++)
    {
        b[i]=i+1;
        printf("%d  ",b[i]);
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<100; j++)
        {
            if(a[j]==b[i])
            {
                c[i]++;
            }
        }
    }
    for(i=0; i<10; i++)
    {
        printf("\n[%i] - %ix", b[i], c[i]);
    }
}

void ex05()
{
    int aux;
    x=10;
    printf("\nVETOR: \n");
    for(i=0; i<x; i++)
    {
        a[i]=rand()%51;
        printf("[%i] - %i\n", i, a[i]);
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(a[i]<a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    printf("\nORDENADO: \n");
    for(i=0; i<10; i++)
    {
        printf("[%i] - %i\n", i, a[i]);
    }
}

void ex06()
{
    float *A;
    int tam;
    printf("Informe o tamanho do vetor: \n");
    scanf("%i",&tam);
    A=leVetor(tam);
    imprimeVetor(A, tam);
    free(A);
    A=NULL;
}
float *leVetor(int tam)
{
    float *v;
    v=malloc(sizeof(float)*tam);
    for(i=0; i<tam; i++)
    {
        v[i]=30+((rand()%200)/(float)10);
    }
    return v;
}
void imprimeVetor(float *v, int tam)
{
    for(i=0; i<tam; i++)
    {
        printf("[%i]=%.2f\n", i, v[i]);
    }
}

void ex07()
{
    int parametro1, parametro2, escolha=0;
    printf("Digite um intervalo de numeros para a matriz:\nInicial: ");
    scanf("%i", &parametro1);
    printf("Final: ");
    scanf("%i", &parametro2);
    mat2 = malloc(10 * sizeof(int*));
    for(i=0; i<10; i++)
    {
        mat2[i] = malloc(10*sizeof(int));
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            mat2[i][j] = matriz[i][j]=numAleatorio(parametro1, parametro2);
        }
    }
    printf("      ");
    for(i=0; i<10; i++)
    {
        printf("[%i]|", i);
    }
    for(i=0; i<10; i++)
    {
        printf("\n[%i] - ", i);
        for(j=0; j<10; j++)
        {
            printf("%i |", matriz[i][j]);
        }
    }
    do
    {
        menu_ex07();
        scanf("%i",&escolha);
        switch(escolha)
        {
        case 1:
            ex08();
            break;
        case 2:
            ex09();
            break;
        case 3:
            ex10();
            break;
        case 4:
            ex11();
            break;
        case 9:
            printf("Até a próxima!\n");
            break;
        default:
            printf("\aOpção inválida!\n");
        }

    }while(escolha!=9);
}

int *numAleatorio(int param1, int param2)
{
    param2=param2-param1+1;
    int retorno;
    retorno=(rand()%param2)+param1;
    return retorno;
}

void menu_ex07()
{
    printf("\n\nEscolha: \n");
    printf(" 1 - Para o menor e maior numero da matriz - (Exercicio 8)\n");
    printf(" 2 - Para a soma dos elementos da diagonal - (Exercicio 9)\n");
    printf(" 3 - Para consultar o valor de uma linha e coluna específica - (Exercicio 10)\n");
    printf(" 4 - Para saber se um valor faz parte da matriz e sua localização - (Exercicio 11)\n");
    printf(" 9 - Para sair\n");
}

void ex08()
{
    menorMaior(mat2);
}
void menorMaior(int **aux8)
{
    int aux;
    if(aux8[0][0] > aux8[9][9])
    {
        aux=aux8[0][0];
        aux8[0][0]=aux8[9][9];
        aux8[9][9]=aux;
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(aux8[0][0]>aux8[i][j])
            {
                aux8[0][0]=aux8[i][j];
            }
            if(aux8[9][9]<aux8[i][j])
            {
                aux8[9][9]=aux8[i][j];
            }
        }
    }
    printf("\nO menor e maior valores da Matriz são:\n\nMenor = %i\nMaior = %i\n", aux8[0][0], aux8[9][9]);
}

void ex09()
{
    somaDiagonal(matriz);
}
void somaDiagonal(int matriz[10][10])
{
    int somaTudo=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(i==j)
            {
                somaTudo+=matriz[i][j];
            }
        }
    }
    printf("A soma dos valores da diagonal da matriz é: %i", somaTudo);
}

void ex10()
{
    posicao(mat2);
}
void posicao(int **aux10)
{
    int l,c,op10;
    printf("      ");
    for(i=1; i<11; i++)
    {
        printf("[%i]|", i);
    }
    for(i=0; i<10; i++)
    {
        printf("\n[%i] - ", i+1);
        for(j=0; j<10; j++)
        {
            printf("%i |", aux10[i][j]);
        }
    }
    while(l!=-1 || c!=-1)
    {
        printf("\n\nDigite o valor da linha: ");
        scanf("%d",&l); l--;
        printf("Digite o valor da coluna: ");
        scanf("%d",&c);c--;
        printf("\nposição[%d][%d]: %i", l,c,aux10[l][c]);
    }
}

void ex11()
{
    recebeMatriz(mat2);
}
void recebeMatriz(int **aux11)
{
    int op11, cont11=0;
    printf("      ");
    for(i=1; i<11; i++)
    {
        printf("[%i]|", i);
    }
    for(i=0; i<10; i++)
    {
        printf("\n[%i] - ", i+1);
        for(j=0; j<10; j++)
        {
            printf("%i |", aux11[i][j]);
        }
    }
    while(op11!=-1)
    {
        printf("\n\nDigite um número: ");
        scanf("%i",&op11);
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {
                if(op11==aux11[i][j])
                {
                    printf("\nPosição - Linha [%i] e Coluna [%i]\n", i+1, j+1);
                    cont11++;
                }
            }
        }
        if(cont11==0 && op11!=-1)
        {
            printf("A matriz não possui o número %i", op11);
        }
        cont11=0;
    }
}
