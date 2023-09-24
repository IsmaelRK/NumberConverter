#include <stdio.h>
#include <string.h>

int main() {
    char bin[100];
    int dec, num;
    int i = 0;

    printf("Entre com o numero decimal: ");
    scanf("%d", &dec);
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
