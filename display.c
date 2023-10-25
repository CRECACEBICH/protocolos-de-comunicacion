#include "MKL25Z4.h"
#include "UART_display.h"

void UART_display_init(){
    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

    PORTA->PCR[1] = (1 << PORT_PCR_MUX(2)); //TX
    PORTA->PCR[2] = (1 << PORT_PCR_MUX(2)); //RX

    UART0->BDH = 0;
    UART0->BDL = 26;

    UART0->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

void UART_display_print(const char* oracion){
    while (*oracion){
        while (!(UART0->S1 & UART_S1_TDRE_MASK)){}
        UART0->D = *oracion;
        oracion++;
    }
}

// Babich, Carballo, Cervera y Creatura | protocolo UART.
