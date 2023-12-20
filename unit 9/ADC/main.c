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
    //[0]set ADC7 channel to be input  (PA7)
    DDRA &=~((1<<7)|(1<<6));
    //[1] Enable the ADC
    ADCSRA |= (1<<7) ; // enable the ADC
    //[2] select the Vref source 
    ADMUX |= (1<<7)|(1<<6); // select the internal Vref which is 2.56 volt
    //[3] select the input channel
    ADMUX |= ((1<<0)|(1<<1)|(1<<2)); // select ADC channel 7 
    //[4] select data is saved right or left allignment 
    ADMUX &=~(1<<5); // left alligment
    //[5] select the prescalar
    ADCSRA |= 1<<2; // division by 4
    short ADC_Value;
    /***********************************
    * ------------ GPIO INIT-----------------
    ***********************************/
    DDRD = 0xFF;
    DDRC = 0XFF;
    while (1)
    {
        //[1] start conversion
        ADCSRA |= 1<<6;
        //[2] polling on conversion flag
        while(((ADCSRA & 1<<4))==0);
        //[3] store value of the ADC
        PORTD = ADCL; 
        PORTC = ADCH ;
        //ADC_Value = ADC_Value * (2.5/100);
        //[4] out the value ;
        PORTB |= ADC_Value ;
        delay(5000);
    }


    return 0 ;
}


/*********************************************************
 * *************** READ ADCL First ***********************
*********************************************************/
/*
When you read the ADCL first, you are sending a signal to the ADC that you are ready to receive the new
 conversion result. The ADC will wait until you read the ADCH, and then update the ADC buffer with
  the new conversion result. This way, the ADC buffer always holds the latest conversion result,
   and you can read it without losing any data.

When you read the ADCH first, you are not sending any signal to the ADC. The ADC does not know if you
 are ready to receive the new conversion result or not.
  Therefore, the ADC will not update the ADC buffer with the new conversion result,
   even if it is available. This way, the ADC buffer holds the old conversion result,
    and you will read it instead of the new one. The new conversion result will be lost,
     because the ADC buffer is not updated.
*/