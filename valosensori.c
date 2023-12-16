#include <stdio.h>
#include <math.h>
#include <inttypes.h>
float valoisuus(uint16_t rekisteri);
float valoisuus(uint16_t rekisteri){
    float lux;
    uint16_t vi = rekisteri >> 12;
    uint16_t vl = rekisteri & 0b0000111111111111;
    lux = 0.01 * pow(2,vi) * vl;
    return (lux);
}