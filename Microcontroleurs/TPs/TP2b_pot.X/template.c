#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000


void main(void) {
    // Configure the ADC module
    ADCON1bits.ADFM = 1; // Right justified p.249
    ADCON1bits.ADCS = 0b010; // Horloge Fosc/8 - bit ADCS du registre ADCON1 p.249
    ADCON1bits.ADPREF = 0b00; // Vref est connecté à Vss 
    ADCON0bits.CHS = 0b00000; // Selectionne AN0 comme une entrée p.248 de la DOC
    ADCON0bits.ADON = 1; // Allume le module ADC
    
    // Configueation des pins de sorties
    TRISD = 0x00; // PORTD
    PORTD = 0x00;
    TRISB = 0x00;
    PORTB = 0x00;
  
    while (1) {
        ADCON0bits.GO = 1; //Commence la conversion
        while (ADCON0bits.GO); // Attend
        int adcResult = ADRES; // Lis le resultat dans le registre ADC [ADRESH:ADRESL register pair]
        
        if (adcResult < 85) { //85 pour être plus précis 
            PORTD = 0x01;
            PORTB = 0x00;
        } else if (adcResult > 939) { //939 pour être plus précis
            PORTD = 0x00;
            PORTB = 0x80;
        } else {
            int ledNumber = (adcResult * 8) / 1024; 
            //On renvoie une valeur comprise entre 0 et 1
            //On multiplie par 8 pour avoir une valeur entre 0 et 8, et donc déterminer quel LED doit être allumer
            //On arrondie
            //On ajoute 1 pour avoir des valeurs entre les LEDs entre 1 et 8;sinon D8 est pas concerné
            
            
            if (ledNumber >= 5) {//Si la valeur est supérieur à 5 on va alors manipuler les LED du PORTB de D5 à 8
                PORTB = 1 << (ledNumber - 5);
                PORTD = 0x00;
            } else {
                PORTD = 1 << (ledNumber - 1);
                PORTB = 0x00;
            }
        }
    }
}