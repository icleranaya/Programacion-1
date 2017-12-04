#include <stdio.h>

void ciudades(int *solu, int size, int matriz[size][size], int pos, int act);
int sigu_i(int a, int b, int c[b][b]);

int main()
{
    int n,m,x,y,j,i;

    while(scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0)
    {
        int matrix[n][n];
        int sol = 0;

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                matrix[i][j] = 0;

        if(n > 2)
        {
            for(i = 0; i < m; i++)
            {
                scanf("%d %d", &x, &y);
                matrix[x][y] = 1;
                matrix[y][x] = 1;
            }

            for(i = 0; i < n; i++)
            {
                ciudades(&sol, n, matrix, i, 0);
            }
            printf("%d\n", sol);
        }

    }
}


void ciudades(int *solu, int size, int matriz[size][size], int pos, int act)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(matriz[pos][i] != 0)
        {
            matriz[pos][i] = 0;
            matriz[i][pos] = 0;
            act++;

            if(!sigu_i(i, size, matriz))
            {
                if(*solu < act)
                {
                    *solu = act;
                }
            }
            else
            {
                ciudades(solu, size, matriz, i, act);
            }
            matriz[pos][i] = 1;
            matriz[i][pos] = 1;
            act--;
        }
    }
}

int sigu_i(int a, int b, int c[b][b])
{
    int j = 0, existe = 0;

    while(j < b && !existe)
    {
        if(c[a][j] != 0)
        {
            existe = 1;
        }
        j++;
    }
    return existe;
}
