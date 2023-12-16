#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

float keskiarvo(char *lista);

int main() {
    
    keskiarvo("201,53,12,31,5");
    
    return 0;
}

float keskiarvo(char *lista) {
    const char sep[] = ",";
    
    char *token;
    
    token = strtok(lista, sep);
    
    int summa = 0;
    
    float laskuri = 0;
    
    while( token != NULL ) {
        printf("%s\n",token);
        
        summa += atoi(token);
        
        printf("%i\n",summa);
       
        token = strtok(NULL, sep);
        
        laskuri += 1.00;
    }
    float arvo = summa / laskuri;
    printf("%.3f\n",arvo);
    return arvo;
}
