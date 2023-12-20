#include "MCAL/adc.h"
#include "MCAL/GPIO.h"
#define delay(x)   for (int i = 0 ; i<x ; i++);
/***************************************************
 * ********** Procedures to use ADC *****************
***************************************************
1- make the pin for the selected ADC channel an input pin
2- turn on the ADC Module
3- select the conversion speed  ADPS2:0
4- select the voltage reference
5- activiate start convesion
6- wait for the conversion to be completed (ADIF in ADCSRA)
7- when ADIF is set, read ADCL and ADCH " read the ADCL first"
*/

int main()
{
    /***********************************
     * ------------ ADC INIT-----------------
    ***********************************/
    //[1]set ADC7 channel to be input  (PA7)
    DDRA &=~((1<<7)|(1<<6));
    //[0] Enable the ADC
    ADCSRA |= (1<<7) ; // enable the ADC
    //[1] select the Vref source 
    ADMUX |= (1<<7)|(1<<6); // select the internal Vref which is 2.56 volt
    //[2] select the input channel
    ADMUX |= ((1<<0)|(1<<1)|(1<<2)); // select ADC channel 7 
    //[3] select data is saved right or left allignment 
    ADMUX &=~ (1<<5); // right alligment
    //[4] select the prescalar
    ADCSRA |= 1<<2; // division by 4
    short ADC_Value;
    /***********************************
    * ------------ GPIO INIT-----------------
    ***********************************/
    DDRB = 0xFF;
    while (1)
    {
        //[1] start conversion
        ADCSRA |= 1<<6;
        //[2] polling on conversion flag
        while((ADCSRA&(1<<4)>>4) != 1);
        //[3] store value of the ADC
        ADC_Value = ADCL | ADCH ; 
        ADC_Value = ADC_Value * (2.5/100);
        //[4] out the value ;
        PORTB = ADC_Value ;
        delay(5000);
    }
    return 0 ;
}