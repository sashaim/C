#include <stdio.h>
#include <stdlib.h>

int devolverCantidadDeUnos(unsigned int);

int main()
{
    printf("%d \n", devolverCantidadDeUnos(0b111111110010));
    return 0;
}

int devolverCantidadDeUnos(unsigned int n)
{
    int resultado = 0;
    int mascara = 1;
    int i;

    for (i = 0; i < 16; i++)
    {
        if ((n & mascara) == 1)
        {
            resultado++;
        }

        n = n >> 1;
    }

    return resultado;
}
