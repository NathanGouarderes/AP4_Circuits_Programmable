#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000

void demorar (void);
//void __interrupt() isr(void);
//int b = 0;
void main(void) {
    /* Code d'initialisation */
    
    TRISD &= 0xF0; // Port D en sortie
    TRISB &= 0xF0; // Port B en sortie

    T2CON =  0x07; // 0000 0111
    PR2 = 249;
    PIR1 = 0x02; //0000 0010 Pour activer uniquement le bit de TMR2IF
    //INTCON = 0xDB; // 1101 1011 pour activer tous les bits concernant les intéruptions sauf ceux en rapport à TMR0
    //PIE1 = 0x02; // On fait un masquage avec le seul bit qui nous intéresse (celui pour activer l'interupt sur le Timer 2)
    
    // 125 boucles avec prescaler 128 donc TMR0  = 125

    while(1){
        
        /* Code a executer dans une boucle infinie */
        
        LATD = 0x00; // On vide la latch du port D

        LATDbits.LATD0 = 1; //On allume les LEDs
        demorar();
        LATDbits.LATD0 = 0; //On allume les LEDs
        LATDbits.LATD1 = 1;
        demorar();
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1; //On allume les LEDs
        demorar();
        LATDbits.LATD2 = 0; //On allume les LEDs
        LATDbits.LATD3 = 1;
        demorar();
        LATDbits.LATD3 = 0; //On allume les LEDs
        LATBbits.LATB0 = 1;
        demorar();
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 1;
        demorar();
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 1;
        demorar();
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 1; //On allume les LEDs
        demorar();
        LATBbits.LATB3 = 0;
        
        }
    }

// Fonction pour attendre 1 seconde (PR2 = 249, Prescaler à 4, Postscaler à 1, FOSC/4 = 2Mhz)


//  249 + 1 * ((4 * 1) / 2 000 000) = 0,0005
// 0,0005 * 2000 = 1
void demorar (void){
    for (int i = 0; i < 125; i++){
        while(TMR2 != PR2){}//Tant que TMR2 n'est pas en haut
        PIR1bits.TMR2IF = 0; //On baisse le flag
        PR2 = 249;
        
    }
}

/*
 void __interrupt() isr(void){
    b++;
    if(b == PR2){
        b=0;
        PIR1bits.TMR2IF = 0;
    }
}
 */


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
 
 
 
 LATD = 0x00; // On vide la latch du port D
        LATDbits.LATD0 = 1; //On allume les LEDs
        demorar();
        LATDbits.LATD1 = 1; //On allume les LEDs
        demorar();
        LATDbits.LATD2 = 1; //On allume les LEDs
        demorar();
        LATDbits.LATD3 = 1; //On allume les LEDs
        demorar();
        LATBbits.LATB0 = 1;
        demorar();
        LATBbits.LATB1 = 1; //On allume les LEDs
        demorar();
        LATBbits.LATB2 = 1; //On allume les LEDs
        demorar();
        LATBbits.LATB3 = 1; //On allume les LEDs
        demorar();
        

        LATDbits.LATD0 = 0; //On allume les LEDs
        demorar();
        LATDbits.LATD1 = 0; //On allume les LEDs
        demorar();
        LATDbits.LATD2 = 0; //On allume les LEDs
        demorar();
        LATDbits.LATD3 = 0; //On allume les LEDs
        demorar();
        LATBbits.LATB0 = 0;
        demorar();
        LATBbits.LATB1 = 0; //On allume les LEDs
        demorar();
        LATBbits.LATB2 = 0; //On allume les LEDs
        demorar();
        LATBbits.LATB3 = 0; //On allume les LEDs
        demorar();
        LATBbits.LATB4 = 0; //On allume les LEDs
        demorar();*/