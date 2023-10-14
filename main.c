#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int bin_dec(char *bin);
int dec_bin(int dec);
int hex_dec(char *hex);
int dec_hex(int vl);
int oct_dec(char *num_octal);
int dec_oct(int numero_int);

int main()
{
    int esc;
    /// ext = 0;
    char opr[6][15] = {"Binario", "Decimal", "Hexadecimal", "Decimal", "Octal", "Decimal"};
    char resposta[3];

    do // [Ismael] Arrumar o while que esta infinito (perguntando ao user se quer continuar)
    {
        int i = 1;
        printf("\n[%d] Binario -> Decimal", i++); // Char
        printf("\n[%d] Decimal -> Binario", i++);
        printf("\n[%d] Hexadecimal -> Decimal", i++); // Char
        printf("\n[%d] Decimal -> Hexadecimal", i++);
        printf("\n[%d] Octal -> Decimal", i++); // Char
        printf("\n[%d] Decimal -> Octal", i++);
        printf("\n[%d] Soma e subtracao de binarios", i++);

        printf("\nEscolha a Opcao Desejada: ");
        scanf("%d", &esc);

        if ((esc == 1) || (esc == 3) || (esc == 5))
        {
            char n[50];
            int res;
            printf("Digite o Numero %s: ", opr[esc - 1]);
            scanf("%s", n);

            switch (esc)
            {

            case 1:
                res = bin_dec(n);
                break;
            case 3:
                res = hex_dec(n);
                break;
            case 5:
                res = oct_dec(n);
                break;
            }
            printf("Resultado da Conversao: %d", res);
        }
        else // [Ismael] Retornar e printar
        {
            int n;
            printf("Digite o Numero %s: ", opr[esc - 1]);
            scanf("%d", &n);

            switch (esc)
            {

            case 2:
                dec_bin(n);
                break;
            case 4:
                dec_hex(n);
                break;
            case 6:
                dec_oct(n);
                break;
            }
        }


        printf("\nDeseja continuar(sim/nao): ");
        scanf("%s", resposta);

    } while (strcmp(resposta, "sim") == 0);
}

int bin_dec(char *bin)
{
    int tam, i;
    strrev(bin);
    tam = strlen(bin);

    int resultado = 0, potencia = 1;

    for (i = 0; i < tam; i++)
    {

        if (bin[i] == '1')
        {

            resultado += potencia;
        }

        potencia *= 2;
    }

    return resultado;
}

int dec_bin(int dec)
{

    char bin[100];
    // int num;
    int i = 0;

    // num = dec;

    if (dec >= 0)
    {
        if (dec == 0)
        {
            strcpy(bin, "0");
        }
        else
        {
            while (dec > 0)
            {
                int resto = dec % 2;
                bin[i] = resto + '0';
                dec = dec / 2;
                i++;
            }
            bin[i] = '\0';
            strrev(bin);
        }

        printf("Resultado da Conversao: %s", bin);
    }
    else
    {
        printf("O numero deve ser nao negativo");
    }
}

int hex_dec(char *hex)
{

    int value, lstValues[100], sum = 0, tam1;

    strupr(hex);
    strrev(hex);

    tam1 = strlen(hex);

    for (int i = 0; i < tam1; ++i)
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

    for (int i = 0; i < tam1; ++i)
    {
        sum += (lstValues[i]) * (pow(16, i));
    }
    return sum;
}

int dec_hex(int vl)
{
    int resto[100], restoOrg[100];
    char convertido[100], cnv[2];
    int i = 0;

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
        // printf("\n%d", restoOrg[j]);

        if ((restoOrg[j] >= 0) && (restoOrg[j] <= 9))
        {
            sprintf(cnv, "%d", restoOrg[j]);
            strcat(convertido, cnv);
        }
        else
        {

            if (restoOrg[j] == 10)
            {
                strcat(convertido, "A");
            }
            else if (restoOrg[j] == 11)
            {
                strcat(convertido, "B");
            }
            else if (restoOrg[j] == 12)
            {
                strcat(convertido, "C");
            }
            else if (restoOrg[j] == 13)
            {
                strcat(convertido, "D");
            }
            else if (restoOrg[j] == 14)
            {
                strcat(convertido, "E");
            }
            else if (restoOrg[j] == 15)
            {
                strcat(convertido, "F");
            }
        }
    }
    // return *convertido;
    printf("Resulatado da convercao: %s", convertido);
}

int oct_dec(char *num_octal)
{
    int l, t = 0, resultado[100], resultado_decimal = 0, cont = 0, tamanho_octal;

    tamanho_octal = strlen(num_octal);

    int numero_octal[tamanho_octal];

    for (int i = 0; i < tamanho_octal; i++)
    {
        numero_octal[i] = num_octal[i] - '0'; // chat que fez, transforma char em int
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

    /*for (l = 0; l < tamanho_octal; l++)
    {
        printf("\n%d", resultado[l]);
    }*/

    return resultado_decimal;
}

int dec_oct(int numero_int)
{
    int i = 1, j, divisao, resultado_octal[100];

    resultado_octal[0] = numero_int % 8;

    do
    {

        divisao = numero_int / 8;

        resultado_octal[i] = divisao % 8;
        i++;

        numero_int = divisao;

    } while (divisao >= 8);

    printf("Resultado da convercao: ");
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", resultado_octal[j]);
    }
}
