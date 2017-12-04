#include <stdio.h>
/*Converir un número decimal a otra base
Versión original por Icler Anaya
*/

#define MAX 50000

/*Constante para realizar el cambio de base*/
#define CADENA "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void cambio(int m, int n);

int main()
{
    int numero, base;

    scanf("%d %d", &numero, &base);
    while(numero >= 0 && base >= 0)
    {
        /*Condicional para realizar la llamada de la función de cambio de base*/
        if(base > 1 && base <= 36 && numero <= MAX && numero > 0)
            cambio(numero,base);
        else
            printf("***");
        scanf("%d %d", &numero, &base);
        printf("\n");
    }
    return 0;
}

void cambio(int m, int n)
{
    if(m >= n)/*Condicional para realizar el paso recursivo*/
        cambio(m/n,n);
    printf("%c", CADENA[m%n]);
}