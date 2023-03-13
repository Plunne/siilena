#ifndef __LSL_INIT_REGS_H
#define __LSL_INIT_REGS_H

#include "lsl_pinouts.h"
#include "main.h"

/* Init All */
void LSL_Init_Registers(void);

/* Init Features */
void LSL_Init_RCC(void);
void LSL_Init_GPIO(void);

#endif // __LSL_INIT_REGS_H