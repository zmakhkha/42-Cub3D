#include <stdio.h>

typedef struct mehdi
{
    int i;
    int k;
    int s;
    int j;
}t_mehdi;


int main()
{
    static t_mehdi m;

    printf("%d\n%d\n%d\n%d\n",m.i,m.j,m.k, m.s);
}