#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000

void horloge (void);

void main(void) {
    /* Code d'initialisation */
    
    TRISD &= 0xF0;
    TRISB &= 0xF0;
    //OPTION_REG = 0x02; // 0000 0010 prescaler à 8
    OPTION_REGbits.INTEDG = 0;
    OPTION_REGbits.T0SE = 0;
    OPTION_REGbits.nWPUEN = 0;
    OPTION_REGbits.TMR0CS = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS0 = 0;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS2 = 0;
    //OPTION_REG &= ~0x28; // 
    TMR0 = 6;
    // 125 boucles avec prescaler 128 donc TMR0  = 125
            
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
        horloge();
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD3 = 0;
        LATDbits.LATD4 = 1;
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;
        horloge();
        }
    }


void horloge (void){
    for (int i = 0; i < 1000; i++){
        while(INTCONbits.TMR0IF != 1){}
    
        INTCONbits.TMR0IF = 0;
        TMR0 = 6;
    }
}

/*LATD = 0x00;
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
for (long int i = 0; i < 1000; i++){
        if(INTCONbits.TMR0IF == 1){
            INTCONbits.TMR0IF = 0;
            TMR0 = 6;
        }
    } 
 
 
 */