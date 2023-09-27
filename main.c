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


int main(int result_Int, char **charresult_Chr)
{
    int i = 1, esc, ext = 0;
    char opr[6][15] = {"Binario", "Decimal", "Hexadecimal", "Decimal", "Octal", "Decimal"};

    while (ext == 0)
    {
        printf("\n[%d] Binario -> Decimal", i++);       //Char
        printf("\n[%d] Decimal -> Binario", i++);
        printf("\n[%d] Hexadecimal -> Decimal", i++);   //Char
        printf("\n[%d] Decimal -> Hexadecimal", i++);
        printf("\n[%d] Octal -> Decimal", i++);         //Char
        printf("\n[%d] Decimal -> Octal", i++);

        printf("\nEscolha a Opcao Desejada: ");
        scanf("%d", &esc);


        if ((esc == 1) || (esc == 3) || (esc == 5))
        {
            char n[50];
            printf("Digite o Numero %s: ", opr[esc-1]);
            scanf("%s", n);

            switch (esc) {

                case 1: bin_dec(n); break;
                case 3: hex_dec(n); break;
                case 5: oct_dec(n); break;

            }



        }
        else
        {
            int n;
            printf("Digite o Numero %s: ", opr[esc-1]);
            scanf("%d", &n);

            switch (esc) {

                case 2: dec_bin(n); break;
                case 4: dec_hex(n); break;
                case 6: dec_oct(n); break;

            }
        }
    }


}

int bin_dec(char *bin)
{
    int tam, i;
    strrev(bin);
    tam = strlen(bin);

    int resultado = 0, potencia = 1;

    for (i = 0; i < tam; i++){

        if (bin[i] == '1'){

            resultado += potencia;
        }

        potencia *= 2;
    }

    printf ("O decimal eh: %d", resultado);
}

int dec_bin(int dec)
{

    char bin[100];
    int num;
    int i = 0;

    num = dec;

    if (dec >= 0) {
        if (dec == 0) {
            strcpy(bin, "0");
        } else {
            while (dec > 0) {
                int resto = dec % 2;
                bin[i] = resto + '0';
                dec = dec / 2;
                i++;
            }
            bin[i] = '\0';
            strrev(bin);
        }

        printf("O numero %d em binario eh: %s", num, bin);
    } else {
        printf("O numero deve ser nao negativo");
    }
}

int hex_dec(char *hex)
{

    int value, lstValues[100], sum = 0;

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

int oct_dec(char *num_octal)
{
    int l, t = 0, resultado[100], resultado_decimal = 0, cont = 0, tamanho_octal;

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

int dec_oct(int numero_int)
{
    int i = 1, j, divisao, resultado_octal[100];

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