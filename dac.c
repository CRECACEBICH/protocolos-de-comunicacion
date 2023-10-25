#include "MKL25Z4.h"
#include "dac.h"

void DAC_init(){
    SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK;
    PORTA->PCR[12] = (1 << PORT_PCR_MUX(0));

    DAC0->C0 = 0x18;
}

void DAC_writeValue(uint16_t val){
    if (val > 4095){
        val = 4095;
    }

    DAC0->DAT[0].DATL = (uint8_t)(val & 0xFF);
    DAC0->DAT[0].DATH = (uint8_t)((val >> 8) & 0x0F);
}

// Babich, Carballo, Cervera y Creatura | protocolo SPI.
