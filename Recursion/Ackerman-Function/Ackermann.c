#include <stdio.h>
/*Función de Ackermann modificada para contar los pasos recursivos realizados
Versión original por Icler Anaya
*/

int ackermann(int m, int n, long *llamadas);

int main()
{
    int m, n, ack;
    long recursion;

    scanf("%d %d", &m, &n);
    while((m > 0) && (n != -2))
    {
        ack = ackermann(m,n,&recursion);
        printf("%d %li\n", ack, recursion);
        scanf("%d %d", &m, &n);
    }
    return 0;
}

int ackermann(int m, int n, long *llamadas)
{
    (*llamadas)++;

    if(m == 0)
        return n+1;
    else
    {
        if((m > 0) && (n == 0))
            return ackermann(m-1,1,llamadas);
        else
        {
            if((m > 0) && (n > 0))
                return ackermann(m-1,ackermann(m,n-1,llamadas),llamadas);
        }
    }
}
