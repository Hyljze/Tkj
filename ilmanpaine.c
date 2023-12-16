#include <stdio.h>
#include <inttypes.h>
#include <math.h>

uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb);

int main(){
    uint32_t moti = ilmanpaine(0b11011110, 0b10111100, 0b0011000);
    printf("%d", moti);
    return 0;
}

uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb){
    uint32_t pressure = ((msb << 12) | (lsb << 4) |(xlsb >> 4));
    return pressure;
}