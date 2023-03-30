#include <stdio.h>
#include <stdlib.h>

int strlen(char s[])
{
    int i, count = 0;
    for (i = 0; s[i] != '\0'; i++)
        count++;
    return count;
}

void strev(char str[])
{
    char temp;
    int len = 0, i = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    len = len - 1;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
        i++;
    }
    printf("\nAfter reverse:%s", str);

    return 0;
}

int strcmp(char s1[], char s2[])
{
    int i, m, n;
    m = strlen(s1);
    n = strlen(s2);
    if (m != n)
        return (0);
    for (i = 0; i < m; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

void sttok(char s[])
{
    int i;
    for (i = 0; s[i] != '\0';)
    {
        if (s[i] == ' ')
        {
            printf("\n");
            i++;
        }
        else
        {
            printf("%c", s[i]);
            i++;
        }
    }
}

int bruteforce(char text[],char pattern[])
{
    int i,j,m,n,flag=0;
    n=strlen(text);
    m=strlen(pattern);
    strev(pattern);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
                break;
        }
        if(j==m)
        {
           printf("\nPattern Found\n");
           flag=1;
        }

    }
    if(flag==0)
        printf("\nPattern not found\n");
    return 0;
}
int bruteforceWord(char text[],char pattern[])
{
    int i,j,m,n,count=0,flag=0;
    n=strlen(text);
    m=strlen(pattern);
    strev(pattern);
    for(i=0;i<n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
                break;
        }
        if(j==m&&text[i-1]==' '&&text[i+m]==' ')
         {
            printf("\nPattern exist as word\n");
            flag=1;
         }

    }
    if(flag==0)
        printf("\nPattern does not exist as word\n");
    return 0;
}
