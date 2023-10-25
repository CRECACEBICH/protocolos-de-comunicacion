#include "MKL25Z4.h"
#include "adc.h"

void ADC_init(void){
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
    PORTE->PCR[29] = (PORTE->PCR[29] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(0x05);

    ADC0->CFG1 = ADC_CFG1_MODE(0x03) | ADC_CFG1_ADICLK(0x01) | ADC_CFG1_ADLSMP_MASK;
    ADC0->SC3 = ADC_SC3_ADICLK(0x01);
}

uint16_t ADC_read(void){
    ADC0->SC1[0] = ADC_SC1_ADCH(0x1F); //canal AD31

    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
    return ADC0->R[0];
}

// Babich, Carballo, Cervera y Creatura | protocolo I2C.
