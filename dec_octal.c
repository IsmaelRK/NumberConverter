#include <stdio.h>


int main()
{

    int i = 1, j, numero_int, divisao, resultado_octal[100]; 

    printf("Digite o numero Decimal:");
    scanf("%d", &numero_int);

     resultado_octal[0] = numero_int%8;
     
    do
    {
            
        divisao = numero_int/8;

        resultado_octal[i] = divisao%8;
        i++;

        numero_int = divisao; 

    } while (divisao >= 8);


    printf("Numero em Octal: ");
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", resultado_octal[j]);
    }
    
}
