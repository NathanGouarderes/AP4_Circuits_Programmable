#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000

void main(void) {
    /* Code d'initialisation */
    
    TRISD &= 0xF0;
    TRISB &= 0xF0;
    
    while(1){
        /* Code a executer dans une boucle infinie */
        LATD = 0x00;
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD3 = 1;
        LATDbits.LATD4 = 0;
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 0;
        __delay_ms(1000);
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD3 = 0;
        LATDbits.LATD4 = 1;
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;
        
        __delay_ms(1000);      
    }
}
