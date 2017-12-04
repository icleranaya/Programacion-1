#include <stdio.h>


void f(int n);

int main()
{
    int n;

    scanf("%d", &n);
    while(n > 0)
    {
        f(n);
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}

void f(int n)
{
    if(n == 1)
        printf("%d\n", n);
    else
    {
        printf("%d ", n);
        if(n % 2)
            f(3 * n + 1);
        else
            f(n >>  1);
    }
}
