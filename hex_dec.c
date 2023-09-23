#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char hex[100];
    int value, lstValues[100], sum = 0;

    printf("Digite o Hexadecimal: ");
    scanf("%s", hex);

    strupr(hex);
    strrev(hex);


    for (int i = 0; i < strlen(hex); ++i)
    {

        if (isdigit(hex[i]))
        {
            value = hex[i] - '0';
            lstValues[i] = value;
        }
        else
        {
            value = hex[i] - 'A' + 10;
            lstValues[i] = value;

        }


    }

    for (int i = 0; i < strlen(hex); ++i)
    {
        sum += (lstValues[i]) * (pow(16, i));
    }
    printf("\nResultado: %d", sum);
}