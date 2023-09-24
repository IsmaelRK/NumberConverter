#include <stdio.h>
#include <string.h>
#include <math.h>

main(){

    char bin[100];
    int tam, i;

        printf ("Entre com o numero em binario: ");
        gets (bin);

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

