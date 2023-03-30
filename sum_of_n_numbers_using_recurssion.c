#include <stdio.h>

int sum(int n);
int square(int n);
int prime(int i, int n);
int fibbonacci(int n);
int power(int n);

int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d", &n);
    printf("The sum is %d \n", sum(n));
    printf("The sum of squares is %d \n", square(n));
    for (int i = 2; i <= n; i++)
    {
        if (prime(2, i) == 0)
        {
            printf("%d \t", i);
        }
    }
    printf("\nFibbonacci number = %d", fibbonacci(n));
    printf("\n2 power %d is %d", n, power(n));
}

int sum(int n)
{
    if (n == 1)
    {
        return (1);
    }
    else
        return (n + sum(n - 1));
}

int square(int n)
{
    if (n == 1)
    {
        return (1);
    }
    else
        return (n * n + square(n - 1));
}

int prime(int i, int n)
{
    if (n == i)
    {
        return (0);
    }
    else if (n % i == 0)
    {
        return (1);
    }
    else
        return prime(i + 1, n);
}

int fibbonacci(int n)
{
    if (n == 1)
    {
        return (0);
    }
    else if (n == 2)
    {
        return (1);
    }
    else
    {
        return (fibbonacci(n - 1) + fibbonacci(n - 2));
    }
}

int power(int n)
{
    if (n == 1)
    {
        return (2);
    }
    else
    {
        return (2 * power(n - 1));
    }
}