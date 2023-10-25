#include "MKL25Z4.h"
#include <stdint.h>
#ifndef DAC_h
#define DAC_h

void DAC_init();
void DAC_writeValue(uint16_t val);

#endif
