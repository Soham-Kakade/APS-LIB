#include <stdio.h>
#include <stdlib.h>
#define max 100000

void selectionsort(int *A, int n)
{
    int index_of_min;
    for (int i = 0; i < n - 1; i++)
    {
        index_of_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[index_of_min])
            {
                index_of_min = j;
            }
        } 
        int *a = &A[i];
        int *b = &A[index_of_min];
        swap(a,b);
    }
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void randomarray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
}

void fileprint(char fname[], int n, int a[])
{
    int i, k;
    FILE *fp;
    fp = fopen(fname, "w");
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        k = a[i];
        fprintf(fp, "%d\t", k);
    }
    fclose(fp);
}

void readfile(char fname[], int a[], int n)
{
    int i, k;
    FILE *fp;
    fp = fopen(fname, "r");
    fscanf(fp, "%d", &n);
    printf("%d", n);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &k);
        printf("\n%d", k);
    }

    fclose(fp);
}

int main()
{
    int n;
    printf("Enter the Number of elements \n");
    scanf("%d", &n);
    int A[max];

    char fname[30] = "data.text";
    char fname2[30] = "Sorted.text";

    randomarray(A, n);
    printf("\nThe generated random array is:\n");
    display(A, n);
    fileprint(fname, n, A);
    selectionsort(A, n);
    printf("--------------------------\n");
    printf("SORTED ARRAY \n");
    printf("--------------------------\n");
    fileprint(fname2, n, A);
    display(A, n);
}
