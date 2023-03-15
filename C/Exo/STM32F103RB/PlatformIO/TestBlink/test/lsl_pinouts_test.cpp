#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
    #include "../include/lsl_pinouts.h"
    #include "../include/main.h"
}


TEST(LSL_STM32F103_TestBlink, TestWriteLED) {   
	
    LSL_PINOUTS_Write(&LED, HIGH);			// LED ON
    EXPECT_EQ(GPIOA->ODR, (1 << LED.pin));
    ASSERT_TRUE(true);
}