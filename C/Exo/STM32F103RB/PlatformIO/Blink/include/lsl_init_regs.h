#ifndef __LSL_INIT_REGS_H
#define __LSL_INIT_REGS_H

#include "stm32f103xb.h"
#include "main.h"

/* Init All */
void LSL_Init_Registers(void);

/* Init Features */
void LSL_Init_RCC(void);
void LSL_Init_GPIO(void);

/* Feature GPIO */
void LSL_GPIO_ClearModes(void);
void LSL_GPIO_SetInputs(void);
void LSL_GPIO_SetOutputs(void);

#endif // __LSL_INIT_REGS_H