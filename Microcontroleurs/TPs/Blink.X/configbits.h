/* 
 * File:   
 * Author: Antoine Pirog
 * Comments: JUNIA AP4 2022-2023
 * Revision history: 
    * 2023/01/04 : File created
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _CONFIG_BITS_H_
#define _CONFIG_BITS_H_

#include <xc.h> // include processor files - each processor file is guarded.  

// CONFIG1
#pragma config FOSC     = HS     // Oscillator Selection Bits->HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins
#pragma config WDTE     = SWDTEN // Watchdog Timer Enable->WDT controlled by the SWDTEN bit in the WDTCON register
#pragma config PWRTE    = OFF    // Power-up Timer Enable->PWRT disabled
#pragma config MCLRE    = ON     // MCLR Pin Function Select->MCLR/VPP pin function is MCLR
#pragma config CP       = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled
#pragma config BOREN    = ON     // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#pragma config IESO     = ON     // Internal/External Switchover Mode->Internal/External Switchover Mode is enabled
#pragma config FCMEN    = ON     // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor is enabled

// CONFIG2
#pragma config WRT     = OFF     // Flash Memory Self-Write Protection->Write protection off
#pragma config PPS1WAY = OFF     // Peripheral Pin Select one-way control->The PPSLOCK bit can be set and cleared repeatedly by software
#pragma config ZCDDIS  = ON      // Zero-cross detect disable->Zero-cross detect circuit is disabled at POR and can be enabled with ZCDSEN bit.
#pragma config PLLEN   = OFF     // Phase Lock Loop enable->4x PLL is enabled when software sets the SPLLEN bit
#pragma config STVREN  = ON      // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config BORV    = LO      // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.
#pragma config LPBOR   = OFF     // Low-Power Brown Out Reset->Low-Power BOR is disabled
#pragma config LVP     = OFF     // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming

#endif /* _CONFIG_BITS_H_ */

