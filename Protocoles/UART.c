#include "stm32f103xb.h"

void LSL_USART_Init(void);
void LSL_USART_Tx(uint8_t c);
uint8_t LSL_USART_Rx(void);

void LSL_USART_Init(void) {

    // Pins
    // Tx1 PA9
    // RX1 PA10

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN; // Enable clocks USART1, GPIOA

    USART1->CR1 |= USART_CR1_UE | USART_CR1_M;  // Enable USART with 8,n,1 // M = 8 or 9 bits
    USART1->CR1 |= USART_CR1_PCE;     // Parity Even (PS Cleared)
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable Tx & Rx

    USART1->CR2 &= ~USART_CR2_STOP; // 1 Stop

    USART1->BRR |= (39 << 4) | (1 << 0); // Set 115200 Bauds
    // 39 Mantissa : 72MHz / (BAUDRATE * 16) ; BAUDRATE as 115200
    // 1 Frac div : 16 * 0.0625 ; 0.0625 is the decimals of previous result (39.0625)

}

int main(void) {

    LSL_USART_Init();

    while (1)
    {
        uint8_t data LSL_USART_Rx();
        LSL_USART_Rx(data);
    }
    

    return 0;
}


void LSL_USART_Tx(uint8_t c) {
    USART1->DR = c;
    while (!(USART1->SR & USART_SR_TC));
}

uint8_t LSL_USART_Rx(void) {
    while (!(USART1->SR & USART_SR_RXNE));
    return USART1->DR & 0xFF;
}