#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double i;
    char s[MAXOP];
    printf("输入两个数，以空格间隔:\n");

    while((type = getop(s)) != '\n')
    {
        push(atof(s));
    }
    i = (pop() + pop());
    i = (i * i);
    printf("和的平方为:%.2f\n",i);
    return 0;
}

int sp = 0;
double val[MAXOP];

void push(double f)
{
    if(sp < MAXOP)
    val[sp++] = f;
    else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp > 0)
    return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c, a, b;
    i = 0;

    while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
    return c;
    if(c == '-' && !isdigit(b = getch()))
    {
        ungetch(b);
        return c;
    }
    if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
    ;
    else
    {
        s[++i] = b;
        while(isdigit(s[++i] = c = getch()))
        ;
    }
    if(c == '.')
    while(isdigit(s[++i] = c = getch()))
    ;
    s[i] = '\0';
    if(c != EOF)
    ungetch(c);
    return NUMBER;
}

char buf[MAXOP];
int bufp = 0 ;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= MAXOP)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}