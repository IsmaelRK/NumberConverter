#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
    int l, t = 0, resultado[100], resultado_decimal = 0, cont = 0, tamanho_octal;
    char num_octal[100];

        printf("Digite o numero Octal:");
        scanf("%s", num_octal);
    
    tamanho_octal = strlen(num_octal);

    int numero_octal[tamanho_octal];
    

     for (int i = 0; i < tamanho_octal; i++) {
        numero_octal[i] = num_octal[i] - '0';  //chat que fez, transforma char em int
    }

    do
    {
        cont = 0;
        for (l = tamanho_octal - 1; l >= 0; l--)
        {
            resultado[l] = numero_octal[l] * pow(8, cont);
            cont++;
        }
        resultado_decimal += resultado[t];
        t++;
    } while (t < tamanho_octal);

    for (l = 0; l < tamanho_octal; l++)
    {
        printf("\n%d", resultado[l]);
    }

    printf("\nNumero em Decimal:%d", resultado_decimal);
}

 