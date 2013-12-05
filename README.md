Sensor Code
=============

This library is for the left, right, and center sensors of the Robot

Functions
=========

void initSensors();

  *This initializes the sensors by enabling the ADC10 interupt and selecting SMCLK

  
Get reading from center sensor
============================
  *int CenterSensorScan(){
  *        ADC10CTL0 &= ~ENC;                                                        //Clear
  *        ADC10CTL1 = INCH_3;                       // input A3
  *        ADC10AE0 |= BIT3;                         // PA.1 ADC option select
  *        ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
  *        __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
  *        return ADC10MEM;
  *}

  * The left and right sensor have a similar code with the differences on the channels
  * First the sensor is cleared and a reading is taken which return the reading (ADC10MEM)

