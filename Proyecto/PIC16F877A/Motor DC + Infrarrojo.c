/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
Motor DC + Infrarrojo.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
Esta práctica consiste en variar la velocidad de un motor por medio de un sensor
SHARP usando los módulos PWM y ADC.
---------------------------------------------------------------------------
*/

#include <16F877A.h>                        //Incluye el microcontrolador con el que se va a trabajar
#device ADC = 8                             // Configura el ADC a 8 bits
#use delay( clock = 20Mhz, crystal )        // Tipo de oscilador y frecuencia dependiendo del microcontrolador

int VALOR_ADC;                              // Variable para almacenar el valor leído del ADC

void main( void ) {
   setup_timer_2( T2_DIV_BY_16, 254, 16 ); // Configura Timer2
   setup_ccp1( CCP_PWM );                  // Configura el módulo CCP para uso del PWM
   setup_adc_ports( AN0 );                 // Configura solo el puerto A0 como entrada analógica
   setup_adc( ADC_CLOCK_DIV_8 );           // Configura oscilador para la conversión

   while ( 1 ) {
      set_adc_channel( 0 );               // Selecciona el canal 0 para la conversión
      VALOR_ADC = read_adc() * 1.53;      // Lee el valor del ADC y lo guarda en la variable
      set_pwm1_duty( VALOR_ADC );
   }
}