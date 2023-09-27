#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int bin_dec(char *num);
int dec_bin(int num);
int hex_dec(char *num);
int dec_hex(int num);
int oct_dec(char *num);
int dec_oct(int num);


int main()
{
    int i = 1, esc;
    char opr[6][15] = {"Binario", "Decimal", "Hexadecimal", "Decimal", "Octal", "Decimal"};

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