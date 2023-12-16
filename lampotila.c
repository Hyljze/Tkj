#include <stdio.h>
#include <inttypes.h>
float lampotila(uint16_t rekisteri, float kerroin);
float lampotila(uint16_t rekisteri, float kerroin){
 float vastaus = rekisteri >> 2;
 return vastaus * kerroin;
}