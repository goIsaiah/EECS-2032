#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
 
/* TODO: insert other definitions and declarations here. */
 
/*
 * @brief   Application entry point.
 */
int Sw3;
int Sw1;
int main(void) {
 
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
 
    PRINTF("Hello World\n");
 
    SIM->SCGC5 |= (1<<9) | (1<<11) | (1<<12) | (1<<13);
    PORTA->PCR[4] = 0x103;                      /*Sw1 PTA4*/
    PORTC->PCR[3] = 0x103;                      /*Sw3 PTC3 */
 
    PORTD->PCR[5] = 0x100;                      /*Green Led */
    PORTE->PCR[31] = 0x100;                     /*Red Led */
 
    PTA->PDDR &= ~(1<<4);
    PTC->PDDR &= ~(1<<3);
 
    PTD->PDDR |= (1<<5);
    PTE->PDDR |= (1<<31);
 
    PTD->PSOR |= (1<<5);
 
    __disable_irq();
    NVIC_DisableIRQ(PORTC_PORTD_IRQn);
 
    //PORTC->PCR[3] |= 0x103;                    // Pin C3 GPIO with Pull up Resistor
    PORTC->PCR[3] &= ~0xF0000;                  // Disable Interrupt on Pin C3  ........IRQC setting to 0000
    PORTC->PCR[3] |= 0xA0000;                   // Enable Interrupt on Falling Edge
    NVIC_SetPriority(PORTC_PORTD_IRQn, 192);
    NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
    __enable_irq();
 
    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
 
    while(1) {
        Sw1 = (PTA->PDIR & (1<<4)) >> 4;        // PTA4 or can do anything here, for e.g., say a hello! in printf ...
 
        i++;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0;
}
 
void PORTC_PORTD_IRQHandler(void) {    //When PTC3 is pressed.. COMPLETE THIS FOR LAB 8
 
    if (PORTC->ISFR & (1<<3)) { // Check if interrupt is from PTC3
        PORTC->ISFR |= (1<<3); // Clear the interrupt flag
 
        Sw1 = (PTA->PDIR & (1<<4)) >> 4; // Check the status of Sw1 (PTA4)
        if (Sw1 == 0) { // If Sw1 is pressed
            PTD->PTOR |= (1<<5); // Toggle the green LED
        }
    }
 
    // Clear all other interrupt flags on PORTC and PORTD
    PORTC->ISFR = 0xFFFFFFFF;
    PORTD->ISFR = 0xFFFFFFFF;
}
