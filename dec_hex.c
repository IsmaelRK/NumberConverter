#include <stdio.h>
#include <string.h>

int main()
{
    int vl, resto[100], restoOrg[100];
    char convertido[100], cnv[2];
    int i = 0;

    printf("Digite o Inteiro: ");
    scanf("%d", &vl);

    for (int a = 0; a < 100; a++)
    {
        resto[a] = 1;
    }

    while (vl >= 16)
    {
        resto[i] = vl % 16;
        vl = vl / 16;
        i++;
    }
    resto[i] = vl;

    int ind = i;
    for (int j = 0; j <= i; j++)
    {

        restoOrg[j] = resto[ind];
        ind -= 1;

    }

    for (int j = 0; j <= i; j++)
    {
        //printf("\n%d", restoOrg[j]);

        if ((restoOrg[j] >=0) && (restoOrg[j] <= 9))
        {
            sprintf(cnv, "%d", restoOrg[j]);
            strcat(convertido, cnv);
        } else
        {

            if(restoOrg[j] == 10)
            {
                strcat(convertido, "A");
            }
            else if(restoOrg[j] == 11)
            {
                strcat(convertido, "B");
            }
            else if(restoOrg[j] == 12)
            {
                strcat(convertido, "C");
            }
            else if(restoOrg[j] == 13)
            {
                strcat(convertido, "D");
            }
            else if(restoOrg[j] == 14)
            {
                strcat(convertido, "E");
            }
            else if(restoOrg[j] == 15)
            {
                strcat(convertido, "F");
            }
        }

    }
    printf("Resultado: ");
    puts(convertido);
}