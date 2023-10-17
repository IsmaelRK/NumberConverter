#include <stdio.h>
#include <string.h>

int main() {
    char bin[100], bin2[100];
    int tam, tam2, i;

    printf("\nEntre com o numero em binario: ");
    gets(bin);

    printf("Entre com outro numero em binario: ");
    gets(bin2);

    strrev(bin);
    tam = strlen(bin);

    int resultado = 0, potencia = 1;

    for (i = 0; i < tam; i++) {
        if (bin[i] == '1') {
            resultado += potencia;
        }
        potencia *= 2;
    }

    strrev(bin2);
    tam2 = strlen(bin2);

    int resultado2 = 0, potencia2 = 1;

    for (i = 0; i < tam2; i++) {
        if (bin2[i] == '1') {
            resultado2 += potencia2;
        }
        potencia2 *= 2;
    }

    int soma_dec, sub_dec;
    char bin3[100], bin4[100];

    soma_dec = resultado + resultado2;
    sub_dec = resultado - resultado2;

    
    i = 0; 
    if (soma_dec >= 0) {
        if (soma_dec == 0) {
            strcpy(bin3, "0");
        } else {
            while (soma_dec > 0) {
                int resto = soma_dec % 2;
                bin3[i] = resto + '0';
                soma_dec = soma_dec / 2;
                i++;
            }
            bin3[i] = '\0';
            strrev(bin3);
        }
    } else {
        strcpy(bin3, "Numero negativo"); 
    }


    i = 0; 
    if (sub_dec >= 0) {
        if (sub_dec == 0) {
            strcpy(bin4, "0");
        } else {
            while (sub_dec > 0) {
                int resto = sub_dec % 2;
                bin4[i] = resto + '0';
                sub_dec = sub_dec / 2;
                i++;
            }
            bin4[i] = '\0';
            strrev(bin4);
        }
    } else {
        strcpy(bin4, "Numero negativo"); 
    }

    printf("Soma: %s\n", bin3);
    printf("Subtracao: %s\n", bin4);

}


