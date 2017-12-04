#include <stdio.h>
/*Juego de mosaicos
Versión original por Icler anaya*/

int mosaicos(int n);

int main()
{
    int numero;

    scanf("%d", &numero);
    while(numero >= 0)
    {
        printf("%d = %d\n", numero, mosaicos(numero));
        scanf("%d", &numero);
    }
    return 0;
}

int mosaicos(int n)
{
    if(n < 0)
        return 0;
    else
    {
        if(n == 0)
            return 1;
        else
        {
            return mosaicos(n-1) + mosaicos(n-2);
        }
    }

}