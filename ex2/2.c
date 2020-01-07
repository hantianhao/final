#include<stdio.h>

#define MAX 50

void reverse(char s[]);

int main()
{
    char s[MAX];
    int a,b;
    char c;
    int *p;
    printf("输入50个单位内的字符:\n");
    for(a = 0;(c = getchar()) != EOF && c != '\n';a++)
    {
        s[a] = c;
    }
    s[++a] = '\0';
    reverse(s);
    a = 0;
    printf("字符串经倒置后得:\n");
    while(s[a] != '\0')
    printf("%c",s[a++]);
    printf("\n");
}

int p = 0;
int d = 0;
int c;
void reverse(char s[])
{
    if(s[p++] != '\0')
    {
        reverse(s);
    }
    else
    --p;
    if(p > d)
    {
        c = s[--p];
        s[p] = s[d];
        s[d++] = c;
    }
}