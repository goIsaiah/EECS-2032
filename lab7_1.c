/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    MKL43Z256xxx4_Project_2032_Lab7.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
void delay(void);


void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}
/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    PORTC->PCR[3] = 0x103;
    PORTA->PCR[4] = 0x103;
    PORTD->PCR[5] = 0x100;
    PORTE->PCR[31] = 0x100;
    PTE->PDDR |= 0b10000000000000000000000000000000;
    PTD->PDDR |= (1<<5);

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
    	int sw3 = PTC->PDIR;
    	int sw1 = PTA->PDIR & (1<<4);
    	if((sw3 == 8) && (sw1 == 16)) { // Switch 1 is not pressed and switch 3 is not pressed
    		PTE->PCOR |= 0b10000000000000000000000000000000; // Red LED is turned on
    		PTD->PSOR |= (1<<5); // Green LED is turned off
    	}

    	else if((sw3 == 8) && (sw1 != 16)) { // Switch 1 is pressed and switch 3 is not pressed
    		PTE->PTOR |= 0b10000000000000000000000000000000; // Red LED is blinking
    		PTD->PCOR |= (1<<5); // Green LED is turned on
    		delay();
    	}

    	else if((sw3 != 8) && (sw1 == 16)) { // Switch 3 is pressed and switch 1 is not
    		PTE->PTOR |= 0b10000000000000000000000000000000; // Red LED is blinking
    		PTD->PSOR |= (1<<5); // Green LED is off
    		delay(); // Delay used to make Red LED blink
    	}
    	else{ // Both switches are pressed
    	    PTE->PTOR |= 0b10000000000000000000000000000000; // Red LED is blinking
    	    PTD->PTOR |= (1<<5); // Green LED is blinking
    	    delay();
    	}
    }
    return 0 ;
}
