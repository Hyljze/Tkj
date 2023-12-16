#include <stdio.h>
#include <math.h>
#include <inttypes.h>
float kosteus(uint16_t rekisteri);
float kosteus(uint16_t rekisteri){
    float vastaus = rekisteri / pow(2,16) * 100;
    return vastaus;
}

    
