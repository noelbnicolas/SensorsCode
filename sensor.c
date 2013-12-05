/*
 * sensor.c
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Noel.Nicolas
 */
#include <msp430g2553.h>
#include "sensor.h"

char direction;

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

void initSensors(){
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
}

int CenterSensorScan(){
	ADC10CTL0 &= ~ENC;							//Clear
	ADC10CTL1 = INCH_3;                       // input A3
	ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	return ADC10MEM;
}

int LeftSensorScan(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}

int RightSensorScan(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;
	ADC10AE0 |= BIT5;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}
/*
 * sensor.c
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Noel.Nicolas
 */


