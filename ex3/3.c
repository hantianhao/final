#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int a = 0;
    double b;
    double c;
    if (argc == 1)
    {
        printf("The program needs at least one integer parameter to run!\n");
        return 0 ;
    }
    c = atof(argv[++a]);
    while((--argc) > 0 )
    {
        if(isdigit(*argv[a]))
        {
            if(c > (b = atof(argv[a])))
            c = b;
            a++;
        }
        else
        {
            c = EOF;
            printf("The parameter has to be an integer format!\n");
            return 0;
        }
    }
    if(c != EOF)
    {
        printf("Min parameter is %g\n",c);
    }
}